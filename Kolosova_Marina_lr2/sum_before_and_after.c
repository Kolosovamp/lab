#include"sum_before_and_after.h"
int sum_before_and_after(int mass[], int size){
	int sum=0,k;
	if (index_first_zero(mass,size)==-1)
		return sum;
	else{
		for(k=0;k<size;k++){
			if(k==index_first_zero(mass,size))
				k=index_last_zero(mass,size)+1;			
			sum+=abs(mass[k]);
		}
	}
	return sum;
}
