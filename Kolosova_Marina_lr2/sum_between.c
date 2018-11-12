#include"sum_between.h"
int sum_between(int mass[], int size){
	int sum=0,k;
	if(index_first_zero(mass,size)==-1)
		return sum;
	else{
		for(k=index_first_zero(mass,size);k<=index_last_zero(mass,size);k++)
			sum+=abs(mass[k]);
	}
	return sum;
}
