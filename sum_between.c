#include <stdio.h>
#include "index_first_zero.h"
#include "index_last_zero.h"
#include <stdlib.h>
int sum_between(int c[],int p){
int i, sum = 0;
for(i=index_first_zero(c,p);i<=index_last_zero(c,p);i++){
sum+=abs(c[i]);}
return sum;
}
