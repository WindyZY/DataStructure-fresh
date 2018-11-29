#pragma once
#ifndef ASTACK_H
#define ASTACK_H

template <typename E> class Stack {
private:
	void operator=(const Stack&);
	Stack(const Stack&){}
public:
	Stack(){}
	virtual ~Stack() {}
	virtual void clear() = 0;
	virtual void push(const E& it) = 0;
	virtual E pop() = 0;
	virtual const E& topValue() const = 0;
	virtual iint length() const = 0;
};

template <typename E> class AStack :public Stack<E> {
private:
	int maxSize;
	int top;
	E *listArray;
public:
	AStack(int size = defaultsize) { maxSize = size; top = 0; listArray = new E[size]; }
	~AStack() { delete[] listArray; }
	void clear() { top = 0; }
	void push(const E& it) {
		Assert(top != maxSize, "Stack is full");
		listArray[top++] = it;
	}
	E pop() {
		Assert(top != 0, "Stack is empty");
		return listArray[--top];
	}
	//E pop(Astack s) { s.pop(); }
	const E& topValue() const {
		Assert(top != 0, "Stack is empty");
		return listArray[top - 1];
	}
	int length() const { return top; }
};
#endif