/****************
*Author:������201730685202��
*Date��2018-09-26
*Description:�����ܺϲ�����˳����������ĺ�����Exercise 4.7��
****************/

#define MaxL 100
typedef struct
{
	int data[MaxL];
	int len;
}LList;

void combine(LList *A, LList *B, LList *C)//to combine the two linked list
{
	int a = 0, b = 0, c = 0;
	while (a < A->len&&b < B->len)
	{
		if (A->data[a] == B->data[b])
		{
			C->data[c++] = A->data[a++];
			C->data[c++] = B->data[b++];
		}
		else if (A->data[a] < B->data[b])
			C->data[c++] = A->data[a++];
		else C->data[c++] = B->data[b++];
	}
	while (a<A->len&&b>=B->len) C->data[c++] = A->data[a++];
	while (b<B->len&&a>=A->len) C->data[c++] = B->data[b++];
	C->len = c;
}
