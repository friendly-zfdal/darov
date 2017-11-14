#include <stdio.h>
#include <stdlib.h>
#include "index_first_zero.h"
#include "index_last_zero.h"
#include "sum_between.h"
#include "sum_before_and_after.h"
int main(){
int c[100], sum = 0, m, z, n, i;
scanf("%d",&n);
for(i=0;i<100;i++){
scanf("%d ",&c[i]);}
switch (n) {
case 0:
printf("%d\n", index_first_zero(c));
break;
case 1: printf("%d\n", index_last_zero(c));
break;
case 2: printf("%d\n", sum_between(c));
break;
case 3: printf("%d\n", sum_before_and_after(c));
break;
default: printf("Данные некорректны");
}
return 0;
}
