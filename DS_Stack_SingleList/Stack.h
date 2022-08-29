#ifndef Stack_H
#define Stack_H
typedef struct node {
	int element;
	struct node* link;
} Node;

typedef struct stack {
	Node* top;	//栈顶指针指向栈顶元素结点
}Stack;
int Top(Stack* S);
void Creat(Stack* S);
void Destory(Stack* S);
void Push(Stack*S,int x);
void Pop(Stack* S);
#endif 
