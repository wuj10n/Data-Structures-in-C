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
	int front;//指向队头元素的前一单元的下标位置
	int rear;//指向队尾元素的下标位置
	int maxSize;//队列最多允许存储的元素数量
	ElemType* element;//储存队列元素的一维数组的首地址指针
}Queue;
//创建一个能容纳mSize单元的空队列
void Create(Queue* Q, int mSize);
//销毁一个已存在的队列，释放队列占用的数组空间
void Destory(Queue* Q);
//判断队列是否为空，若是，则返回TURE,否则返回FALSE
BOOL IsEmpty(Queue* Q);
//判断队列是否已满，若是，则返回TURE,否则返回FALSE
BOOL IsFull(Queue* Q);
//获取对头元素，并通过x返回。若操作成功，则返回TURE,否则返回FALSE
BOOL Front(Queue* Q, ElemType* x);
//在队列Q的队尾插入元素x(入队操作。若操作成功，则返回TURE,否则返回FALSE
BOOL EnQueue(Queue* Q, ElemType x);
//从队列Q中删除队头元素(出队操作)。若操作成功，则返回TURE,否则返回FALSE
BOOL DeQueue(Queue* Q);
//清除队列中全部元素，使队列恢复到初始状态（Q->front->rear=0),但并不释放空间。
void Clear(Queue* Q);

#endif
