#include <stdio.h>
#include <stdlib.h>
#include "index_first_zero.h"
#include "index_last_zero.h"
#include "sum_between.h"
#include "sum_before_and_after.h"
int main(){
char s;
int c[100], sum = 0, m, z, n,p=0;
scanf("%d",&n);
while(s!='\n'){
scanf("%d%c",&c[p],&s);
p++;
}
switch (n) {
case 0:
printf("%d\n", index_first_zero(c,p));
break;
case 1: printf("%d\n", index_last_zero(c,p));
break;
case 2: printf("%d\n", sum_between(c,p));
break;
case 3: printf("%d\n", sum_before_and_after(c,p));
break;
default: printf("Данные некорректны");
}
return 0;
}
