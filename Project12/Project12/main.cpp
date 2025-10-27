#include <stdio.h>

int rec_func(int n);

int main(void)
{
	int result;
	int n = 10;
	result = rec_func(n);
	printf("%d\n", result);
	return 0;
}
int rec_func(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n + rec_func(n - 1);
	}
}