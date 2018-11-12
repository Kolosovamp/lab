#include<stdio.h>
#include"sum_before_and_after.h"
#define N 100

int main() {
 int i=0;//кол-во введенных элементов
 int result=-1;
 int operation;//номер операции
 int mass[N];
 char symbol=' ';
scanf("%d", &operation);
while (symbol!='\n') {
	scanf("%d%c", &mass[i], &symbol);
	i++;
}
switch(operation) {
case 0:
	result=index_first_zero(mass, i);
	break;
case 1:
	result=index_last_zero(mass, i);
	break;
case 2:
	result=sum_between(mass, i);
	break;
case 3:
	result=sum_before_and_after(mass, i);
	break;
default:
	printf("%s\n", "Данные некорректны");
        break;
}
if (result!=-1)
	printf("%d\n", result); 
return 0;
}
