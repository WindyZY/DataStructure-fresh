/****************
*Author:Zhou Yao(201730685202)
*Date:2018-09-27
*Description:这是Fibonacci序列的栈实现(Exercise 4.16)
****************/
#include<stack>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct Node
{
	int num = 0;//node nnumber
	int dir = 0;//direction:left is 1,right is 0;
};

int Fibnacci(int n)
{
	int sum = 0;
	stack<Node> s;
	Node fib;
	do
	{
		while (n > 1)//push elements into stack
		{
			fib.num = n;
			fib.dir = 1;
			s.push(fib);
			n--;
		}
		//when n=1,loop ends
		sum = sum + n;//add all the deepest subtree(fib(0)and fib(1))

		while (!s.empty())
		{
			fib = s.top();
			s.pop();

			if (fib.dir == 1)//if it is left subtree,then push fib(n-2) to the right.
			{
				fib.dir = 0;
				s.push(fib);
				n = fib.num - 2;
				break;
			}//right subtree has been added.
		}
	} while (!s.empty());
	return sum;
}

int main()
{
	int n;
	while (cin >> n)
		cout << Fibnacci(n) << endl;
	return 0;
}