#include"index_last_zero.h"

int index_last_zero(int mass[], int size){
	int j;
	if(index_first_zero(mass,size)==-1)
		return j=-1;
	else{
		for(j=size-1;j>=0;j--){
			if(mass[j]==0)
				return j;
		}
	}
}
