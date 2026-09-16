/*
 * L3Ex2-Monolith.c
 *
 *  Created on: Sep 5, 2022
 *      Author: Scott Chen
 */

#include <stdio.h>
#include "mymath.h"



int main(void)
{
	int a = 10, b = 20;

	printf("%d + %d = %d\n", a, b, add_num(a, b));
	printf("%d - %d = %d\n", a, b, sub_num(a, b));

	return 0;
}


// Function Implementation (Definition)
///////////////////////////////////////

