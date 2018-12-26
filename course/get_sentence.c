#include"get_sentence.h"

wchar_t get_sentence(struct Text *t,int size, unsigned long int count_of_sent){
	struct Sentence **txt=t->array_of_sent;
	txt[count_of_sent]=malloc(sizeof(struct Sentence));
	int i;
	unsigned long int len=0;
	wchar_t c=L' ';
	wchar_t *buf,*sent_;
	sent_=malloc(size*sizeof(wchar_t));
	for(i=0;c!=L'.';i++){
		c=getwchar();
		if(i+1==size-2){
			wprintf(L"/\n");
			size+=DELTA;
			buf=realloc(sent_,size*sizeof(wchar_t));
			if(buf==NULL){
				wprintf(L"Failed input. Memory is over.\n");
				c=L'\n';
				(sent_)[i]=L'\0';
				return c;
			}
			else{
				sent_=buf;
			}
		}
		sent_[i]=c;
		len=i;
	}
	(txt[count_of_sent])->sent=malloc(sizeof(wchar_t)*(len+2));
	c=getwchar();
	sent_[len+1]=L'\0';
	wcscpy(txt[count_of_sent]->sent,sent_);
	free(sent_);
	buf=NULL;
	txt[count_of_sent]->size=len;
	t->size=count_of_sent+1;
	return c;
}
