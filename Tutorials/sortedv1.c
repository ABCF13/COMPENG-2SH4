/*
 * L2Ex5v1.c
 *
 *  Created on: Sep 4, 2022
 *      Author: Scott Chen
 */

#include <stdio.h>

int main(void)
{
	// Declarations
	/////////////////////
	int numBuf[20], i, flag = 1;

	// Get 20 integers and store them into the array
	printf("Please input 20 integers, one per line:");

	for(i = 0; i < 20; i++)
	{
		scanf("%d", &numBuf[i]);
	}


	// Then, iterate through them to check for sorted-ness
	for(i = 0; i < 19; i++)
	{
		if(numBuf[i] > numBuf[i + 1])
		{
			flag = 0; // only reset flag if unsorted-ness detected
		}
	}

	// Report sorted-ness
	if(flag == 1)
		printf("Array sorted.");
	else
		printf("Array not sorted.");

	// Can also be written in Ternary Operator statement
	// flag == 1? printf("Array sorted.") : printf("Array not sorted.");
	//
	// Ternary Operator
	//  Test Condition?  [Run this part when TRUE] : [Run this part when FALSE];

	return 0;
}
