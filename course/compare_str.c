#include"compare_str.h"

int compare_str(struct Sentence* str1, struct Sentence* str2){
	int i;
	if(str1->size!=str2->size){
		return 0;
	}
	else{
		for(i=0;i<str1->size;i++){
			if(towupper((str1->sent)[i])!=towupper((str2->sent)[i])){
				return 0;
			}
		}
	}
	return 1;
}
