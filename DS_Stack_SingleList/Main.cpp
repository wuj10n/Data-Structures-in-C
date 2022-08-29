#include"Stack.h"
#include<cstdio>
int main()
{
	Stack testStack;
	Creat(&testStack);
	Push(&testStack, 0);
	Push(&testStack, 1);
	Push(&testStack, 2);
	Push(&testStack, 3);

	printf("%d ", Top(&testStack));
	Pop(&testStack);
	printf("%d ", Top(&testStack));
	Pop(&testStack);
	printf("%d ", Top(&testStack));
	Pop(&testStack);
	printf("%d ", Top(&testStack));
	Pop(&testStack);
	printf("%d ", Top(&testStack));
	Pop(&testStack);
	return 0;
}