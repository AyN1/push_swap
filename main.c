#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void print(bool checker)
{
	if (checker)
		printf("checker\n");
	else if (!checker)
		printf("not checker\n");
}

int main(void)
{
	print(true);
	printf("\n");
	print(false);
	return (0);
}
