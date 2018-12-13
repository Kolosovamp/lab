#include<stdio.h>
#include<stdlib.h>
int cmp(const void* arg1, const void* arg2){
	return (*(int*)arg1-*(int*)arg2);
}


void* my_bsearch(const void* key, const void* mass, unsigned int size_of_mass, unsigned int size_of_el, int (*compar)(const void *arg1,const void* arg2)){
	if(mass==NULL)
		return NULL;
	int current_index=size_of_mass/2;
	const void* result=mass+(size_of_el*current_index);	
	if( compar(result,key)==0)
		return result;
	else{
		if (size_of_mass==1)
			return NULL;
		else{
			if(compar(result,key)>0)
				return my_bsearch(key,mass,current_index,size_of_el,compar);
			else{
				return my_bsearch(key,result,size_of_mass-current_index,size_of_el,compar);
			}
		}
	}
}

int main(){
	int* key=malloc(sizeof(int));
	*key=4;
	int* str=malloc(5*sizeof(int));
	int i;
	for(i=0;i<5;i++)
		scanf("%d",&str[i]);
	int *result=my_bsearch(key,str,5,4,&cmp);
	printf("%d\n", result-str);
	//printf("%p\n", str);
	//printf("%d\n", my_bsearch(key,str,5,4,&cmp)-&str[0]);
	return 0;
}
