/**********************************
Experience 1 2018/10/12
Header for the implementation of LinkedList
By ����  201730685202
***********************************/
#pragma once
#ifndef LIST_H
#define LIST_H

template <typename E> class List {
private:
	//void operator =(const List&) {}
	//List(const List&){}
public:
	List() {}
	virtual ~List() {}

	virtual void clear() = 0;
	virtual void insert(const E& item) = 0;
	virtual void append(const E& item) = 0;
	virtual void remove() = 0;
	virtual void moveToPos(int pos) = 0;
	virtual int length() const = 0;
	virtual int currPos() const = 0;
};

#endif
