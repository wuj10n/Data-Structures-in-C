#include"Queue.h"
#include"LGraph.h"

#include<stdio.h>
#include<stdlib.h>

//1.�ڽӱ�ĳ�ʼ��
Status Init(LGraph* lg, int nSize)
{
	int i;
	lg->n = nSize;
	lg->e = 0;
	lg->a = (ENode**)malloc(nSize * sizeof(ENode*));//��̬���ɳ���Ϊn��һάָ������
	if (!lg->a)
	{
		return ERROR;
	}
	else
	{
		for (i = 0; i < lg->n; i++)
		{
			lg->a[i] = NULL;//��ָ������a�ÿ�
		}
		return OK;
	}
}
//2.�ڽӱ�ĳ���
void DestoryLGraph(LGraph* lg)
{
	int i;
	ENode* p, * q;
	for (i = 0; i < lg->n; i++)
	{
		p = lg->a[i];//ָ��pָ�򶥵�i�ĵ�����ĵ�һ���߽��
		q = p;
		while (p)//�ͷŶ���i�ĵ������е����б߽��
		{
			p = p->nextArc;
			free(q);
			q = p;
		}
	}
	free(lg->a);//�ͷ�һάָ������a�Ĵ洢�ռ�
}
//3.�ߵ�����
Status Exist(LGraph* lg, int u, int v)
{
	ENode* p;
	if (u<0 || v<0 || u>lg->n - 1 || v>lg->n - 1 || u == v)
	{
		return ERROR;
	}
	p = lg->a[u];//ָ��pָ�򶥵�u�ĵ�����ĵ�һ���߽��
	while (p && p->adjVex != v)
	{
		p = p->nextArc;
	}
	if (!p)//��δ�ҵ��˱ߣ�����ERROR
	{
		return ERROR;
	}
	else
	{
		return OK;
	}
}
//4.�ߵĲ���
Status Insert(LGraph* lg, int u, int v, ElemType w)
{
	ENode* p;
	if (u<0 || v<0 || u>lg->n - 1 || v>lg->n - 1 || u == v)
	{
		return ERROR;
	}
	if (Exist(lg, u, v))
	{
		return Duplicate;
	}
	p = (ENode*)malloc(sizeof(ENode));//Ϊ�µı߽�����洢�ռ�
	p->adjVex = v;
	p->w = w;
	p->nextArc = lg->a[u];//���µı߽����뵥�������ǰ��
	lg->a[u] = p;
	lg->e++;
	return OK;
}
//5.�ߵ�ɾ��
Status Remove(LGraph* lg, int u, int v)
{
	ENode* p, * q;
	if (u<0 || v<0 || u>lg->n - 1 || v>lg->n - 1)
	{
		return ERROR;
	}
	p = lg->a[u], q = NULL;
	while (p && p->adjVex != v)//���Ҵ�ɾ���ı��Ƿ����
	{
		q = p;
		p = p->nextArc;
	}
	if (!p)
	{
		return NotPresent;
	}
	if (q)
	{
		q->nextArc = p->nextArc;
	}
	else
	{
		lg->a[u] = p->nextArc;
	}
	free(p);
	lg->e--;
	return OK;
}
//6.DFS
void DFS(int v, int visited[], LGraph g)
{
	ENode* w;
	printf("%d ", v);
	visited[v] = 1;
	for (w = g.a[v]; w; w = w->nextArc)
	{
		if (!visited[w->adjVex])//adjVex�������ⶥ��u���ڽӵĶ���
		{
			DFS(w->adjVex, visited, g);
		}
	}
}
void DFSGraph(LGraph g)
{
	;
	int* visited = (int*)malloc(g.n * sizeof(int));//��ʼ��visited����
	for (int i = 0; i < g.n; ++i)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < g.n; ++i)
	{
		if (!visited[i])
		{
			DFS(i, visited, g);
		}
	}
	printf("\n");
	free(visited);
}
//7.BFS
void BFS(int v, int visited[], LGraph g)
{
	ENode* w;
	Queue q; Create(&q, g.n);
	visited[v] = 1;
	printf("%d ", v);
	EnQueue(&q, v);
	while (!IsEmpty(&q))
	{
		Front(&q, &v);
		DeQueue(&q);
		for (w = g.a[v]; w; w = w->nextArc)
		{
			if (!visited[w->adjVex])
			{
				visited[w->adjVex] = 1;
				printf("%d ", w->adjVex);
				EnQueue(&q, w->adjVex);
			}
		}
	}
}
void BFSGraph(LGraph g)
{
	int i;
	int* visited = (int*)malloc(g.n * sizeof(int));
	for (i = 0; i < g.n; i++)
	{
		visited[i] = 0;
	}
	for (i = 0; i < g.n; i++)
	{
		if (!visited[i])
		{
			BFS(i, visited, g);
		}
	}
	printf("\n");
	free(visited);
}
//���
void Output(LGraph* lg)
{
	int i;
	ENode* p;
	for (i = 0; i < lg->n; i++)
	{
		printf("%d ", i);
		for (p = lg->a[i]; p; p = p->nextArc)
		{
			printf("%d %d,", p->adjVex, p->w);
		}
		printf("\n");
	}
}
//Dijkstra
int choose(int* d, int* s, int n)//ѡ����С��d[i]��i����V-S
{
	int i, minpos;
	ElemType min;
	min = INFTY;
	minpos = -1;
	for (i = 1; i < n; i++)
	{
		if (d[i] < min && !s[i])
		{
			min = d[i];
			minpos = i;
		}
	}
	return minpos;//�����±�λ��
}
Status Dijkstra(int v, ElemType* d, int* path, LGraph g)
{
	int i, k, w, j;
	ElemType wkw[6];
	ENode* p, * q;
	int* s;
	if (v<0 || v>g.n - 1)
	{
		return ERROR;
	}
	s = (int*)malloc(g.n * sizeof(int));
	for (i = 0; i < g.n; i++)
	{
		s[i] = 0;   //��ʼ��
		d[i] = INFTY;
		for (p = g.a[v]; p; p = p->nextArc)
		{
			if (p->adjVex == i)
			{
				d[i] = p->w;
			}
		}
		if (i != v && d[i] < INFTY)
		{
			path[i] = v;
		}
		else
		{
			path[i] = -1;
		}
	}

	s[v] = 1; d[v] = 0;
	printf("%d ", v);
	for (j = 0; j < g.n; j++)
	{
		printf("%d ", d[j]);
	}
	printf("\n");
	for (i = 1; i < g.n - 1; i++)
	{
		k = choose(d, s, g.n);
		s[k] = 1;
		printf("%d ", k);
		for (j = 0; j < g.n; j++)
		{
			wkw[j] = INFTY;
		}
		for (q = g.a[k]; q; q = q->nextArc)
		{
			wkw[q->adjVex] = q->w;
		}
		for (w = 0; w < g.n; w++)
		{
			if (!s[w] && d[k] + wkw[w] < d[w])
			{
				d[w] = d[k] + wkw[w];
				path[w] = k;
			}
		}
		for (j = 0; j < g.n; j++)
		{
			printf("%d ", d[j]);
		}
		printf("\n");
	}
	for (j = 1; j < g.n; j++)
	{
		printf("%d-%d���·�� ", v, j);
		int a[6] = { -2,-2,-2,-2,-2,-2 };
		int m = 4;
		a[5] = j;
		k = j;
		if (path[k] == -1)
		{
			printf("��\n");
		}
		else
		{
			while (path[k] != 0)
			{
				a[m] = path[k];
				k = a[m];
				m--;
			}
			a[m] = 0;
			for (i = 0; i < 6; i++)
			{
				if (a[i] != -2)
					printf("%d ", a[i]);
			}
			printf("\n");
		}
	}
	return OK;
}

