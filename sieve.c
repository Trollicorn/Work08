#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"


int sieve(int targetPrime){
	int size = (int)(targetPrime * log(targetPrime) * 1.15) >> 5;
	int bits = size << 5;
	printf("%d\n",bits );
	int * nums = calloc(size,1);
	int pr = 0;
	int cur;
	
	for (int bit = 2; bit < bits; bit++){
	//	printf("%d\n",nums[bit>>5] & (1 << (bit&31)) );
		if  ( nums[bit>>5] & (1 << (bit&31)) ) {
		
		//	pr++;
		/*	//printf("%d\n", ( ( (nums[bit>>5] >> (bit&31)) & 1)));
			
		//	printf("bit=%d, nums[bit]=%d, pr=%d\n",bit,nums[bit>>5] >> (bit&31),pr );
			if (pr == targetPrime){
				free(nums);
				return bit;
			}
			cur = bit;
			for (int j = bit; j < bits; j += cur){
				nums[j>>5] |= (1 << (j&31));
			}
		*/
		}
		
	}

	
	printf("%d\n",pr );
	free(nums);
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
