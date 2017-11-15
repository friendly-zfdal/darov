#include <stdio.h>
int index_first_zero(int c[],int p){
int m,i;
for(i=0;i<=p;i++){
if (c[i]==0){
m=i;
break;
}
}
return m;
}
