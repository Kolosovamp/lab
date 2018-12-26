#include"sort_of_text.h"

long unsigned int cmp_for_multisort1(const void *arg1, const void *arg2){
	struct Sentence **sent1=(struct Sentence **)arg1;
	struct Sentence **sent2=(struct Sentence **)arg2;
	return (*sent1)->multi-(*sent2)->multi;  
}

long unsigned int cmp_for_multisort2(const void *arg1, const void *arg2){
	struct Sentence **sent1=(struct Sentence **)arg1;
	struct Sentence **sent2=(struct Sentence **)arg2;
	return (*sent2)->multi-(*sent1)->multi;  
}

void sort_of_text(struct Text *txt, int choice){
	if(choice==1){
		qsort(txt->array_of_sent,txt->size,sizeof(struct Sentence *), cmp_for_multisort1);
	}
	if(choice==2){
		qsort(txt->array_of_sent,txt->size,sizeof(struct Sentence *), cmp_for_multisort2);
	}
	if(choice!=1 && choice!=2){
		wprintf(L"Данной команды не существует.\n");
	}
}

