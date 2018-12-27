#include"get_sentence.h"


void input(struct Text *txt){
	//FILE *fp=freopen("input.txt","r",stdin);	
	unsigned long int size_of_text=50, size_of_sent=50, count_of_sent=0;
	txt->array_of_sent=malloc(size_of_text*sizeof(struct Sentence*));
	int i,flag=0;
	wchar_t c;
	wchar_t *sent_,*buf;
	struct Sentence **buff;
	sent_=malloc(sizeof(wchar_t)*size_of_sent);
	for(i=0;(c=getwchar())!=WEOF; i++){
		if(count_of_sent+1==size_of_text){
			size_of_text+=DELTA;
			buff=realloc(txt->array_of_sent,sizeof(struct Sentence*)*size_of_text);
			if(!buff){
				wprintf(L"Failed input. Memory is over.\n");
				c=WEOF;
			}
			else{
				txt->array_of_sent=buff;
			}
		}		
		if(i+1==size_of_sent-2){
			size_of_sent+=DELTA;
			buf=realloc(sent_,sizeof(wchar_t)*size_of_sent);
			if(!buf){
				wprintf(L"Failed input. Memory is over.\n");
				c=WEOF;
				sent_[i]=L'.';
				sent_[i+1]=L'\0';
			}
			else{
				sent_=buf;
			}	
		}
		if(c!=L'.'){
			if(flag==1 && !iswspace(c)){
				i=0;
			}
			if(!iswspace(c)){
				flag=0;
			}
			if(flag==0){
				sent_[i]=c;
			}
		}
		else{
			flag=1;
			sent_[i]=c;
			sent_[i+1]=L'\0';
			count_of_sent++;		
			(txt->array_of_sent)[count_of_sent-1]=malloc(sizeof(struct Sentence));
			(txt->array_of_sent)[count_of_sent-1]->sent=malloc(sizeof(wchar_t)*(i+2));
			(txt->array_of_sent)[count_of_sent-1]->size=i+1;
			i=0;
			wcscpy((txt->array_of_sent)[count_of_sent-1]->sent,sent_);
			free(sent_);
			txt->size=count_of_sent;
			c=getwchar();
			sent_=malloc(sizeof(wchar_t)*size_of_sent);
		}
	}
	txt->array_of_sent=realloc(txt->array_of_sent,txt->size*sizeof(struct Sentence *));
	free(sent_);
	//fclose(fp);
}

