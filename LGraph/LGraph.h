#ifndef LGraph_H
#define LGraph_H

#define ERROR 0
#define OK 1
#define Overflow 2     //Overflow��ʾ����
#define Underflow 3    //Underflow��ʾ����
#define NotPresent 4   //Notpresent��ʾԪ�ز�����
#define Duplicate 5    //Duplicate��ʾ���ظ�Ԫ��
#define INFTY 9999
typedef int ElemType;
typedef int WeightType;
typedef int Status;

typedef struct eNode
{
	int adjVex;               //�����ⶥ��u���ڽӵĶ���
	ElemType w;               //�ߵ�Ȩֵ
	struct eNode* nextArc;    //ָ����һ���߽��
}ENode;

typedef struct lGraph
{
	int n;                    //ͼ�ĵ�ǰ������
	int e;                    //ͼ�ĵ�ǰ����
	ENode** a;                //ָ��һά�����ָ��
}LGraph;
//1.�ڽӱ�ĳ�ʼ��
Status Init(LGraph* lg, int nSize);
//2.�ڽӱ�ĳ���
void DestoryLGraph(LGraph* lg);
//3.�ߵ�����
Status Exist(LGraph* lg, int u, int v);
//4.�ߵĲ���
Status Insert(LGraph* lg, int u, int v, ElemType w);
//5.�ߵ�ɾ��
Status Remove(LGraph* lg, int u, int v);
//6.DFS
void DFS(int v, int visited[], LGraph g);
void DFSGraph(LGraph g);
//7.BFS
void BFS(int v, int visited[], LGraph g);
void BFSGraph(LGraph g);
//���
void Output(LGraph* lg);
//Dijkstra
int choose(int* d, int* s, int n);
Status Dijkstra(int v, ElemType* d, int* path, LGraph g);

#endif

