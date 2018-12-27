#include"analysis_of_text.h"

void analysis_of_text(struct Text *txt){
	int i,j;
	wchar_t c;
	unsigned int max_len=0;
	for(i=0;i<txt->size;i++){
		if((txt->array_of_sent)[i]->size>max_len){
			max_len=(txt->array_of_sent)[i]->size;
		}
		(txt->array_of_sent)[i]->symb=0;
		(txt->array_of_sent)[i]->digit=0;
		(txt->array_of_sent)[i]->replays=0;
		if(wcschr((txt->array_of_sent)[i]->sent,L'#')!=NULL || wcschr((txt->array_of_sent)[i]->sent,L'№')!=NULL){
			(txt->array_of_sent)[i]->symb=1;
		}
		for(j=0;j<(txt->array_of_sent)[i]->size;j++){
			c=((txt->array_of_sent)[i]->sent)[j];
			if(iswdigit(c)){
				(txt->array_of_sent)[i]->digit=1;
			}
		}
	}
	for(i=0;i<txt->size;i++){
		for(j=i+1;j<txt->size;j++){
			if( compare_str((txt->array_of_sent)[i],(txt->array_of_sent)[j]) ) {
				(txt->array_of_sent)[i]->replays=1;
				(txt->array_of_sent)[j]->replays=1;
			}
		}
	}
	wchar_t *buff;
	unsigned long int m;
	wchar_t *word, *ptr;
	buff=malloc(sizeof(wchar_t)*(max_len+1));
	for(i=0;i<txt->size;i++){
		m=1;
		wcscpy(buff,(txt->array_of_sent)[i]->sent);
		word=wcstok(buff,L" ,.",&ptr);
		while(word!=NULL){
			m*=wcslen(word);
			word=wcstok(NULL,L" .,",&ptr);
		}
		(txt->array_of_sent)[i]->multi=m;
	}
	free(buff);
}
