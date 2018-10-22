#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"


int sieve(int targetPrime){
	int size = targetPrime * log(targetPrime) * 1.15;
	char * nums = calloc(size,sizeof(char));
	int pr = 0;
	int cur;
//	printf("%d\n",size );
	for (int i = 2; i < size; i++){
	//	printf("i=%d, nums[i]=%d, pr=%d\n",i,nums[i],pr );
		if (!nums[i]){
			pr++;
		//	printf("%d is %d\n", pr, nums[i]);
			if (pr == targetPrime){
				return i;
			}
			cur = i;
			for (int j = i; j < size; j += cur){
				nums[j] = 'a';
			}
		}
	}
	return -1;
}
/*
int main(){
	printf("%d\n",sieve(100000) );

	return 0;
}
*/