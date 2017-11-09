#include <stdio.h>
#include "index_first_zero.h"
#include "index_last_zero.h"
#include <stdlib.h>
int sum_before_and_after(int c[]){
int i, sum=0;
	for(i=0;i<=index_first_zero(c);i++){
	sum+=abs(c[i]);
	return sum;
	}
	for(i=9;i>=index_last_zero(c);i--)
	{
	sum+=abs(c[i]);
	return sum;
	}
return sum;
}

