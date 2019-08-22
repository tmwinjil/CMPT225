#include <stdio.h>
#include "add.h"
#include "sub.h"

int main()
{
	printf("The sum of 2 and 5 is %d\n", add(2,5));
	printf("2 minus 5 is %d\n", sub(2,5));
	return 0;
}
