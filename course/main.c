#include<stdio.h>
//#include<string.h>
#include<ctype.h>
#include<wchar.h>
#include<wctype.h>
#include<locale.h>
#include<stdlib.h>
#include"print_unique_words.h"
#include"declaration_of_struct.h"
#include"analysis_of_text.h"
#include"delete_some_sent.h"
#include"get_sentence.h"
#include"sort_of_text.h"
#include"replace_date.h"

struct Text text;

void print_text(struct Text *txt){
	int i;
	for(i=0;i<txt->size;i++){
		wprintf(L"%ls\n",(txt->array_of_sent)[i]->sent);
	}
}
void print_menu(){
	wprintf(L"Введите номер команды.\n");
	wprintf(L"1) Распечатать каждое слово, которое встречается не более одного раза в тексте.\n"
		L"2) Каждую подстроку вида " L"<день> <месяц> <год> г " L"заменить на подстроку вида" L" ДД/ММ/ГГ.\n"
		L"3) Отсортировать предложения по произведению длин слов в предложении.\n"
		L"4) Удалить все предложения, которые содержат символ '#' или '№', но не содержат ни одной цифры.\n"
		L"5) Распечатать предложения.\n"
		L"6) Выйти из программы.\n");
}

int main(){
	int size=50,len_of_text=50;
	setlocale(LC_CTYPE,"");
	int i,operation=0,choice_of_sort=0;
	wchar_t finish=L'\t';	
	text.array_of_sent=malloc(sizeof(struct Sentence*)*len_of_text);
	struct Sentence **array;
	for(i=0;finish!=L'\n';i++){
		if(i==len_of_text){
			len_of_text+=DELTA;
			array=realloc(text.array_of_sent,sizeof(wchar_t*)*len_of_text);
			if(array==NULL){
				wprintf(L"Failed input. Memory is over.\n");
				break;
			}
			else {
				text.array_of_sent=array;
			}			
		}		
		finish=get_sentence(&text,size,i);
		(text.array_of_sent[i])->size=wcslen((text.array_of_sent[i])->sent);
	}
	analysis_of_text(&text);
	delete_some_sent(&text,L"replays");
	if(text.size==0){
		wprintf(L"Все предложения удалены.\n");
		wprintf(L"Good luck!\n");
		return 0;
	}
	for(i=0;operation!=6;i++){
		print_menu();
		wscanf(L"%ld", &operation);
		switch(operation){
			case 1:
				print_unique_words(&text);
				break;
			case 2:
				replace_date(&text);
				analysis_of_text(&text);
				break;
			case 3:
				wprintf(L"Если хотите отсортировать по возрастанию,то введите 1, по убыванию - введите 2.\n");
				wscanf(L"%ld", &choice_of_sort);
				sort_of_text(&text, choice_of_sort);
				break;
			case 4:
				delete_some_sent(&text, L"special_symb");
				break;
			case 5:
				print_text(&text);
				break;
			case 6:
				wprintf(L"Good luck!\n");
				return 0;
			default:
				wprintf(L"Wrong operation!\n");
				break;
		}
	
	
	}
	return 0;
}

