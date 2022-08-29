#ifndef Stack_H
#define Stack_H
typedef struct stack {
	int top;		//ջ��λ���±�
	int maxSize;	//��ջ�������
	int* element;	//��ջ������׵�ַ
} Stack;

void Create(Stack* S, int maxSize);	//����һ������ܴ洢maxSize��Ԫ�صĿն�ջ��
void Destroy(Stack* S);				//���ٶ�ջ���ͷŶ�ջ��ռ�Ĵ洢�ռ䡣
bool IsEmpty(Stack* S);				//����ջΪ�գ��򷵻�TRUE; ���򷵻�FALSE��
bool IsFull(Stack* S);				//����ջ�������򷵻�TRUE; ���򷵻�FALSE��
bool Top(Stack* S, int*x);			//��ȡ��ջ��ջ��Ԫ�أ���ͨ��x���ء��������ɹ����򷵻�TRUE; ���򷵻�FALSE��
bool Push(Stack* S, int x);			//��ջ��λ�ò���Ԫ��x ����ջ������ ���������ɹ����򷵻�TRUE; ���򷵻�FALSE��
bool Pop(Stack* S);					//�Ӷ�ջ��ɾ��ջ��Ԫ�أ���ջ���������������ɹ����򷵻�TRUE; ���򷵻�FALSE��
void Clear(Stack* S);				//�����ջ��ȫ��Ԫ�ء�

#endif
