#include "Stack.h"
#include <malloc.h>


void Create(Stack* S, int maxSize)
{
    S->maxSize = maxSize;
    S->element = (int*)malloc(sizeof(int) * maxSize);
    S->top = -1;    
}

//����һ���Ѵ��ڵĶ�ջ���ͷŶ�ջռ�õĿռ�
void Destroy(Stack* S)
{
    S->maxSize = 0;
    free(S->element);
    S->element = NULL;  //������ָ��
    S->top = -1;
}

//�ж϶�ջ�Ƿ�Ϊ�գ������򷵻�TRUE; ���򷵻�FALSE
bool IsEmpty(Stack* S)
{
    return S->top==-1;
}

//�ж϶�ջ�Ƿ������������򷵻�TRUE; ���򷵻�FALSE
bool IsFull(Stack* S)
{
    return S->top==S->maxSize;
}

//��ȡջ��Ԫ�أ���ͨ��x���ء��������ɹ����򷵻�TRUE; ���򷵻�FALSE
bool Top(Stack* S, int* x)
{
    if (IsEmpty(S)) 
    {
        return false;
    }
    *x = S->element[S->top];
    return true;
}

//��ջ��λ�ò���Ԫ��x����ջ���������������ɹ����򷵻�TRUE; ���򷵻�FALSE��
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
//ɾ��ջ��Ԫ�أ���ջ���������������ɹ����򷵻�TRUE; ���򷵻�FALSE��
bool Pop(Stack* S)
{
    if (IsEmpty(S))
    {
        return false;
    }
    S->top--;
    return false;
}
//�����ջ��ȫ��Ԫ�أ��������ͷſռ�
void Clear(Stack* S)
{
    S->top = -1;
}

