#include"delete_some_sent.h"

void delete_some_sent(struct Text *txt, wchar_t choice[]){
	int i,j;
	for(i=0;i<txt->size;i++){
		if(((txt->array_of_sent)[i]->replays==1 && !wcscmp(choice,L"replays")) || ((txt->array_of_sent)[i]->digit==0 && (txt->array_of_sent)[i]->symb==1 && !wcscmp(choice,L"special_symb"))){
			txt->size--;
			free((txt->array_of_sent)[i]->sent);
			for(j=i;j<txt->size;j++){
				(txt->array_of_sent)[j]=(txt->array_of_sent)[j+1];
			}
			i--;
		}
	}
	txt->array_of_sent=realloc(txt->array_of_sent,sizeof(struct Sentence*)*(txt->size));
}
