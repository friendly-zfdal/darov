#include <stdio.h>
int index_last_zero(int c[],int p){
int k,m;
	for (k=p;k>=0;k--){
	if(c[k]!=0){
		for (m=k;m>=0;m--){
		if(c[m]==0)
		return m;
}	
}
}
}
