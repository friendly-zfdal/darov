#include <stdio.h>
int index_last_zero(int c[]){
int k,z=1,m=0;
	for (k=9;k>=0 && m!=1;k--){
	if(c[k]==0){
	m=1;
	return k;
	}
}
return k;
}
