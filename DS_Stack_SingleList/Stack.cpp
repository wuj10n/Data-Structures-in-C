#include "Stack.h"
#include <malloc.h>

int Top(Stack* S)
{
	if (S->top != NULL) {
		return S->top->element;
	}
	else {
		return 999;
	}
}

void Creat(Stack* S)
{
	S->top = NULL;
}

void Destory(Stack* S)
{
	Node* p;
	while (S->top)
	{
		p = S->top;
		S->top = p->link;
		free(p);
		
	}
}
//x进栈
void Push(Stack* S, int x)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (p) {
		p->element = x;
		p->link = NULL;
		p->link = S->top;
		S->top = p;
	}
}
//栈顶元素出栈
void Pop(Stack* S)
{
	//若堆栈为空，则直接返回
	if (S->top == NULL)
		return;
	Node* p = S->top;
	S->top = p->link;
	free(p);
}
