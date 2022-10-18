#include"LGraph.h"
int main()
{
	LGraph M;
	Init(&M, 6);
	Insert(&M, 0, 1, 50);
	Insert(&M, 0, 2, 10);
	Insert(&M, 0, 4, 80);
	Insert(&M, 1, 2, 15);
	Insert(&M, 1, 4, 20);
	Insert(&M, 2, 3, 15);
	Insert(&M, 3, 1, 20);
	Insert(&M, 3, 4, 45);
	Insert(&M, 5, 3, 9);
	Insert(&M, 5, 4, 10);
	Output(&M);
	printf("É¾³ý<5,4>\n");
	Remove(&M, 5, 4);
	Output(&M);
	/*printf("\n");
	printf("DFS: ");
	DFSGraph(M);
	printf("BFS: ");
	BFSGraph(M);
	int d[6];
	int path[6];
	Dijkstra(0, d, path, M);*/
}