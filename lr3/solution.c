#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define N 200
#define START_DIR "/home/marina/lr3/root"
#define MAX_COUNT 3000
#define DEL 1
#define ADD 0

extern int errno;

struct address{
        char *address;
	char *prevAddress;//файл, из кт идет подключение файла по адресу address
        int Minotaur;
        int number;

};

void findFile(const char *dirPath, const char *fileName,struct address **array, const char *prevFileAddress);
int addPath(struct address **array, const char *newPath, const char *prevFileAddress);
int readFile(const char *filePath, struct address **array);
void printResult(struct address **array, int index, const char *nextAddress);

int main(){
  struct address *arr=malloc(MAX_COUNT*sizeof(struct address));
  findFile(START_DIR,"file.txt",&arr,"");
  
  //почистить память
  return 0;
}


int addPath(struct address **array, const char *newPath, const char *prevFileAddress){
	static int count=0;
	struct address *arr=*array;
	arr[count].address=malloc(sizeof(char)*N);
	arr[count].prevAddress=malloc(sizeof(char)*N);
	strcpy(arr[count].address, newPath);
	strcpy(arr[count].prevAddress, prevFileAddress);
	arr[count].number=count+1;
	arr[count+1].number=0;
	count++;
	return count-1;
}

void findFile(const char *dirPath, const char *fileName, struct address **array, const char *prevFileAddress){
	struct address *arr=*array;
	char str[N];
	int index;
	strcpy(str,dirPath);
	DIR *dir=opendir(dirPath);
	if(dir){
		struct dirent *de=NULL;
		while(de=readdir(dir)){
			if( (!strstr(de->d_name, ".") && de->d_type == DT_DIR) ){
				strcat(str,"/");
				strcat(str, de->d_name);
				findFile(str,fileName,array, prevFileAddress);
				str[strlen(str)-strlen(de->d_name)-1]='\0';
			}
			if( !strcmp(de->d_name, fileName) && de->d_type == DT_REG){
				strcat(str,"/");
				strcat(str, fileName);
				index=addPath(array, str,prevFileAddress);
				arr[index].Minotaur=0;
				if(readFile(str,array)){
					arr[index].Minotaur=1;
					printResult(array,index,NULL);
					return;
				}
				str[strlen(str)-strlen(fileName)-1]='\0';	
			}
		}
	}
	closedir(dir);
	return;	
}


int readFile(const char *filePath, struct address **array){
	//__asm__ __volatile__("int3");
	char *str=malloc((N+1)*sizeof(char));
	FILE *fp=fopen(filePath, "rt");
	struct address *arr=*array;
	//int index=addPath(array, str);
	if(fp){
		while(!feof(fp)){
        		fgets(str,N,fp);
			if(!feof(fp))
		   		*(strstr(str,"\n"))=0;
			if(!strcmp(str,"Deadlock")){
				//arr[index].Minotaur=0;
        	        	return 0;
			}
        		if(!strcmp(str,"Minotaur")){
				return 1;
			}
			str=strstr(str," ")+1;
			if(!feof(fp))
				findFile(START_DIR, str, array, filePath);
		}
	}
	fclose(fp);
	return 0;
}

void printResult(struct address **array, int index, const char *nextAddress){
	//__asm__ __volatile__("int3");
	FILE *fp=fopen("result.txt", "a+");
	struct address *arr=*array;
	if(arr[index].Minotaur){
		if(index && arr[index].prevAddress)
			printResult(array, index-1, arr[index].prevAddress);
		fprintf(fp, "%s\n", arr[index].address);
	}
	else{
		if(!strcmp(arr[index].address, nextAddress)){
			if(index && arr[index].prevAddress)
				printResult(array, index-1, arr[index].prevAddress);
			fprintf(fp, "%s\n", arr[index].address);
		}
		else 
			if(index)
				printResult(array, index-1, nextAddress);
	}
	fclose(fp);
	return;
}
