#include"Queue.h"

//����һ��������mSize��Ԫ�Ŀն���
void Create(Queue* Q, int mSize)
{
	Q->maxSize = mSize;
	Q->element = (ElemType*)malloc(sizeof(ElemType) * mSize);
	Q->front = Q->rear = 0;
}
//����һ���Ѵ��ڵĶ��У��ͷŶ���ռ�õ�����ռ�
void Destory(Queue* Q)
{
	Q->maxSize = 0;
	free(Q->element);
	Q->front = Q->rear = -1;
}
//�ж϶����Ƿ�Ϊ�գ����ǣ��򷵻�TURE,���򷵻�FALSE
BOOL IsEmpty(Queue* Q)
{
	return Q->front == Q->rear;
}
//�ж϶����Ƿ����������ǣ��򷵻�TURE,���򷵻�FALSE
BOOL IsFull(Queue* Q)
{
	return (Q->rear + 1) % Q->maxSize == Q->front;
}
//��ȡ��ͷԪ�أ���ͨ��x���ء��������ɹ����򷵻�TURE,���򷵻�FALSE
BOOL Front(Queue* Q, ElemType* x)
{
	if (IsEmpty(Q))
	{
		return FALSE;
	}
	*x = Q->element[(Q->front + 1) % Q->maxSize];
	return TRUE;
}
//�ڶ���Q�Ķ�β����Ԫ��x(��Ӳ������������ɹ����򷵻�TURE,���򷵻�FALSE
BOOL EnQueue(Queue* Q, ElemType x)
{
	if (IsFull(Q))
	{
		return FALSE;
	}
	Q->rear = (Q->rear + 1) % Q->maxSize;
	Q->element[Q->rear] = x;
	return TRUE;
}
//�Ӷ���Q��ɾ����ͷԪ��(���Ӳ���)���������ɹ����򷵻�TURE,���򷵻�FALSE
BOOL DeQueue(Queue* Q)
{
	if (IsEmpty(Q))
	{
		return FALSE;
	}
	Q->front = (Q->front + 1) % Q->maxSize;
	return TRUE;
}
//���������ȫ��Ԫ�أ�ʹ���лָ�����ʼ״̬��Q->front->rear=0),�������ͷſռ䡣
void Clear(Queue* Q)
{
	Q->front = Q->rear = 0;
}