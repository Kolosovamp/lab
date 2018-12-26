#include"replace_date.h"

int cmpr(const void* arg1, const void* arg2){
	wchar_t **arg22=(wchar_t **)arg2;
	wchar_t *arg11=(wchar_t*)arg1;
	return wcscmp(arg11, *arg22);
}

void replace_date(struct Text *txt){
	int i,j;
	wchar_t *buf,*word,*ptr;
	wchar_t *month[]={L"августа",L"апреля",L"декабря",L"июля",L"июня",L"марта",L"мая",L"ноября",L"октября",L"сентября",L"февраля",L"января"};
	wchar_t *number_of_month[]={L"08",L"04",L"12",L"07",L"06",L"03",L"05",L"11",L"10",L"09",L"02",L"01"};
	wchar_t **array_of_words;
	int count_of_words;
	for(i=0;i<txt->size;i++){
		buf=malloc(sizeof(wchar_t)*((txt->array_of_sent)[i]->size+1));
		wcscpy(buf,(txt->array_of_sent)[i]->sent);
		count_of_words=1;
		for(j=0;j<(txt->array_of_sent)[i]->size;j++){
			if(buf[j]==L' '){
				count_of_words++;
			}
		}
		array_of_words=malloc(sizeof(wchar_t*)*count_of_words);
		word=wcstok(buf,L" ,",&ptr);
		for(j=0;j<count_of_words;j++){
			array_of_words[j]=malloc(sizeof(wchar_t)*(wcslen(word)+1));
			wcscpy(array_of_words[j],word);
			word=wcstok(NULL,L" ,.",&ptr);
		}
		if(count_of_words>3){
			for(j=0;j<count_of_words-3;j++){
				int number=wcstol(array_of_words[j],&ptr,10);
				int year=wcstol(array_of_words[j+2],&ptr,10);
				wchar_t **mnth=bsearch(array_of_words[j+1],&month,12,sizeof(wchar_t *),cmpr);
				if (number>0 && number<32 && year!=0 && mnth!=NULL && !wcscmp(array_of_words[j+3],L"г")){
					wchar_t *new_date=malloc(30*sizeof(wchar_t));	
					wchar_t *old_date=malloc(30*sizeof(wchar_t));
					new_date[0]=L'\0';
					old_date[0]=L'\0';
					wcscat(old_date,array_of_words[j]);
					wcscat(old_date,L" ");
					wcscat(old_date,array_of_words[j+1]);
					wcscat(old_date,L" ");
					wcscat(old_date,array_of_words[j+2]);
					wcscat(old_date,L" ");
					wcscat(old_date,L"г");
					wcscat(new_date,array_of_words[j]);
					wcscat(new_date,L"/");
					wcscat(new_date,number_of_month[mnth-month]);
					wcscat(new_date,L"/");
					wcscat(new_date,array_of_words[j+2]);
					wchar_t new_sent[(txt->array_of_sent)[i]->size+1];
					wcscpy(new_sent,(txt->array_of_sent)[i]->sent);
					int dest=wcsstr((txt->array_of_sent)[i]->sent,old_date)-(txt->array_of_sent)[i]->sent;
					memmove(new_sent+dest,new_date,wcslen(new_date)*sizeof(wchar_t));
					memmove(new_sent+dest+wcslen(new_date),new_sent+dest+wcslen(old_date),sizeof(wchar_t)*wcslen(new_sent+dest+wcslen(old_date)));
					free((txt->array_of_sent)[i]->sent);
					(txt->array_of_sent)[i]->size-=(wcslen(old_date)-wcslen(new_date));
					(txt->array_of_sent)[i]->sent=malloc(sizeof(wchar_t)*((txt->array_of_sent)[i]->size+1));
					new_sent[(txt->array_of_sent)[i]->size]=L'\0';
					wcsncpy((txt->array_of_sent)[i]->sent,new_sent,(txt->array_of_sent)[i]->size+1);
					free(new_date);
					free(old_date);
				}
			}
		}
		for(j=0;j<count_of_words;j++){
			free(array_of_words[j]);
		}	
		free(array_of_words);
		free(buf);
	}
}
