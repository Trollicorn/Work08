#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"


int sieve(int targetPrime){
	int size = targetPrime * log(targetPrime) * 1.15 / 4;
	int bits = size * (int)(sizeof(int));
	int * nums = calloc(size,sizeof(int));
	int pr = 0;
	int cur;
//	printf("%d\n",bits );
	for (int bit = 2; bit < bits; bit++){
	//	printf("i=%d, nums[i]=%d, pr=%d\n",i,nums[i],pr );
		if (! ((nums[bit/32] >> (bit%32)) & 1)){
			pr++;
		//	printf("%d is %d\n", pr, nums[i]);
			if (pr == targetPrime){
				return bit;
			}
			cur = bit;
			for (int j = bit; j < bits; j += cur){
				nums[bit/32] |= 1 << (bit%32);
			}
		}
	}
	return -1;
}
/*
void setBit(int[] A, int k){
	A[k/32] |= 1 << (k%32);
}*/
/*
int main(){
	printf("%d\n",sieve(100000) );

	return 0;
}
*/
