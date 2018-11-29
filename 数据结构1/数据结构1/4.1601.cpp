/****************
*Author:Zhou Yao(201730685202)
*Date:2018-09-27
*Description:这是Fibonacci序列的栈实现(Exercise 4.16)
****************/
/*#include"AStack.h"
enum FIBOP{IN,OUT};

class Fibr
{
public:
	int val;
	FIBOP op;
	Fibr(int v, FIBOP o) { val = v; op = o; }
};

long fibs(int n)
{
	AStack<Fibr> S;
	Fibr fib(n,IN);
	S.push(fib);//push n into the Stack
	int val;
	while(S.length() > 0)//when S.length()<=0,then the element have been used.
	{
		S.pop();
		val = fib.val;
		FIBOP op = fib.op;
		if (op == IN) {//to push elements
			if (val <= 2) {
				fib.val = 1;
				fib.op = OUT;
				S.push(fib);
			}
			else {
				fib.val = val - 1;
				fib.op = IN;
				S.push(fib);
				fib.val = val - 2;
				S.push(fib);
			}
		}
		else {//op==OUT;
			if (S.length() > 0) {//Else do nothing,loop ends
				S.pop();
				if (fib.op == OUT) {
					fib.val += val;
					S.push(fib);
				}
				else {
					Fibr temp(val,OUT);
					S.push(fib);
					S.push(temp);
				}
			}
		}
	}
	return val;
}*/