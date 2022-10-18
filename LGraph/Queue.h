#ifndef Queue_H
#define Queue_H

#define BOOL int
#define TRUE 1
#define FALSE 0
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct queue
{
	int front;//ָ���ͷԪ�ص�ǰһ��Ԫ���±�λ��
	int rear;//ָ���βԪ�ص��±�λ��
	int maxSize;//�����������洢��Ԫ������
	ElemType* element;//�������Ԫ�ص�һά������׵�ַָ��
}Queue;
//����һ��������mSize��Ԫ�Ŀն���
void Create(Queue* Q, int mSize);
//����һ���Ѵ��ڵĶ��У��ͷŶ���ռ�õ�����ռ�
void Destory(Queue* Q);
//�ж϶����Ƿ�Ϊ�գ����ǣ��򷵻�TURE,���򷵻�FALSE
BOOL IsEmpty(Queue* Q);
//�ж϶����Ƿ����������ǣ��򷵻�TURE,���򷵻�FALSE
BOOL IsFull(Queue* Q);
//��ȡ��ͷԪ�أ���ͨ��x���ء��������ɹ����򷵻�TURE,���򷵻�FALSE
BOOL Front(Queue* Q, ElemType* x);
//�ڶ���Q�Ķ�β����Ԫ��x(��Ӳ������������ɹ����򷵻�TURE,���򷵻�FALSE
BOOL EnQueue(Queue* Q, ElemType x);
//�Ӷ���Q��ɾ����ͷԪ��(���Ӳ���)���������ɹ����򷵻�TURE,���򷵻�FALSE
BOOL DeQueue(Queue* Q);
//���������ȫ��Ԫ�أ�ʹ���лָ�����ʼ״̬��Q->front->rear=0),�������ͷſռ䡣
void Clear(Queue* Q);

#endif
