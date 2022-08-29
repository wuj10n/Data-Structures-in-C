#include "Stack.h"
#include <malloc.h>


void Create(Stack* S, int maxSize)
{
    S->maxSize = maxSize;
    S->element = (int*)malloc(sizeof(int) * maxSize);
    S->top = -1;    
}

//销毁一个已存在的堆栈，释放堆栈占用的空间
void Destroy(Stack* S)
{
    S->maxSize = 0;
    free(S->element);
    S->element = NULL;  //避免悬指针
    S->top = -1;
}

//判断堆栈是否为空，若是则返回TRUE; 否则返回FALSE
bool IsEmpty(Stack* S)
{
    return S->top==-1;
}

//判断堆栈是否已满，若是则返回TRUE; 否则返回FALSE
bool IsFull(Stack* S)
{
    return S->top==S->maxSize;
}

//获取栈顶元素，并通过x返回。若操作成功，则返回TRUE; 否则返回FALSE
bool Top(Stack* S, int* x)
{
    if (IsEmpty(S)) 
    {
        return false;
    }
    *x = S->element[S->top];
    return true;
}

//在栈顶位置插入元素x（入栈操作）。若操作成功，则返回TRUE; 否则返回FALSE。
bool Push(Stack* S, int x)
{
    if (IsFull(S))
    {
        return false;
    }
    S->top++;
    S->element[S->top] = x;
    return true;
}
//删除栈顶元素（出栈操作）。若操作成功，则返回TRUE; 否则返回FALSE。
bool Pop(Stack* S)
{
    if (IsEmpty(S))
    {
        return false;
    }
    S->top--;
    return false;
}
//清除堆栈中全部元素，但并不释放空间
void Clear(Stack* S)
{
    S->top = -1;
}

