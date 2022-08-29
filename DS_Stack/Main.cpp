#include "Stack.h"
#include<cstdio>

int main()
{
	Stack testStack;
	Create(&testStack, 10);
	for (int i = 0; i < 10; i++) {
		Push(&testStack, i);
	}

	for (int i = 0; i < 5; i++) {
		int x;
		Top(&testStack, &x);
		Pop(&testStack);
		printf("%d ", x);
	}

}