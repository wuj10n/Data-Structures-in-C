#ifndef Stack_H
#define Stack_H
typedef struct stack {
	int top;		//栈顶位置下标
	int maxSize;	//堆栈最大容量
	int* element;	//堆栈数组的首地址
} Stack;

void Create(Stack* S, int maxSize);	//建立一个最多能存储maxSize个元素的空堆栈。
void Destroy(Stack* S);				//销毁堆栈，释放堆栈所占的存储空间。
bool IsEmpty(Stack* S);				//若堆栈为空，则返回TRUE; 否则返回FALSE。
bool IsFull(Stack* S);				//若堆栈已满，则返回TRUE; 否则返回FALSE。
bool Top(Stack* S, int*x);			//获取堆栈的栈顶元素，并通过x返回。若操作成功，则返回TRUE; 否则返回FALSE。
bool Push(Stack* S, int x);			//在栈顶位置插入元素x （入栈操作） 。若操作成功，则返回TRUE; 否则返回FALSE。
bool Pop(Stack* S);					//从堆栈中删除栈顶元素（出栈操作）。若操作成功，则返回TRUE; 否则返回FALSE。
void Clear(Stack* S);				//清除堆栈中全部元素。

#endif
