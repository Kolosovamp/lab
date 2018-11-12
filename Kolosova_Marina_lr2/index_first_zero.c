#include"index_first_zero.h"

int index_first_zero(int mass[],int size) {
	int j;
	for(j=0;j<size;j++){
		if(mass[j]==0)
			return j;
		else{
			if(j==size-1)
				return j=-1;
		}
	}
}
