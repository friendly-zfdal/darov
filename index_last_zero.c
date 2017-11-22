#include <stdio.h>
int index_last_zero(int c[],int p){
int i,m;
	for (i=p-1;i>=0;i--){
		if(c[i]==0)
		return i;
}	
}

