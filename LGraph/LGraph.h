#ifndef LGraph_H
#define LGraph_H

#define ERROR 0
#define OK 1
#define Overflow 2     //Overflow表示上溢
#define Underflow 3    //Underflow表示下溢
#define NotPresent 4   //Notpresent表示元素不存在
#define Duplicate 5    //Duplicate表示有重复元素
#define INFTY 9999
typedef int ElemType;
typedef int WeightType;
typedef int Status;

typedef struct eNode
{
	int adjVex;               //与任意顶点u相邻接的顶点
	ElemType w;               //边的权值
	struct eNode* nextArc;    //指向下一个边结点
}ENode;

typedef struct lGraph
{
	int n;                    //图的当前顶点数
	int e;                    //图的当前边数
	ENode** a;                //指向一维数组的指针
}LGraph;
//1.邻接表的初始化
Status Init(LGraph* lg, int nSize);
//2.邻接表的撤销
void DestoryLGraph(LGraph* lg);
//3.边的搜索
Status Exist(LGraph* lg, int u, int v);
//4.边的插入
Status Insert(LGraph* lg, int u, int v, ElemType w);
//5.边的删除
Status Remove(LGraph* lg, int u, int v);
//6.DFS
void DFS(int v, int visited[], LGraph g);
void DFSGraph(LGraph g);
//7.BFS
void BFS(int v, int visited[], LGraph g);
void BFSGraph(LGraph g);
//输出
void Output(LGraph* lg);
//Dijkstra
int choose(int* d, int* s, int n);
Status Dijkstra(int v, ElemType* d, int* path, LGraph g);

#endif

