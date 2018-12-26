#include"print_unique_words.h"

void print_unique_words(struct Text *txt){
	int i;
	unsigned int txt_len=0;
	wchar_t *word, *ptr, *buf;
	for(i=0;i<txt->size;i++){
		txt_len+=(txt->array_of_sent)[i]->size;
	}
	wchar_t *all_text;
	all_text=malloc(sizeof(wchar_t)*(txt_len+1));
	all_text[0]=L'\0';
	buf=malloc(sizeof(wchar_t)*(txt_len+1));
	for(i=0;i<txt->size;i++){
		wcscat(all_text,(txt->array_of_sent)[i]->sent);
	}
	wcscpy(buf,all_text);
	wchar_t *first_time;
	wchar_t *next_time=NULL;
	word=wcstok(buf,L" ,.",&ptr);
	while(word!=NULL){
		first_time=wcsstr(all_text,word);
		next_time=wcsstr(first_time+wcslen(word),word);
		if (next_time==NULL){
			wprintf(L"%ls\n", word);
		}
		next_time=NULL;
		word=wcstok(NULL,L" ,.", &ptr);
	}
	free(buf);
	free(all_text);
}
