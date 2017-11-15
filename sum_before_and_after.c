#include <stdio.h>
#include "index_first_zero.h"
#include "index_last_zero.h"
#include <stdlib.h>
int sum_before_and_after(int c[], int p){
int i, sum1=0, sum2=0;
	for(i=0;i<=index_first_zero(c,p);i++){
	sum1+=abs(c[i]);
	}
	for(i=p;i>=index_last_zero(c,p);i--)
	{
	sum2+=abs(c[i]);
	}
return sum1+sum2;
}

