/****************
*Author:Zhou Yao(201730685202)
*Date:2018-09-26
*Description:这是使用独立的布尔成员记录队列是否为空的4.26的新定义(Exercise 4.14)
****************/
template<typename E>class AQueue :public Queue<E>
{
private:
	int maxSize;
	int front;
	int rear;
	E *listArray;
	bool isEmpty;
public:
	AQueue(int size = dafaultSize)
	{
		maxSize = size + 1;
		rear = 0;
		front = 1;
		listArray = new E[maxSize];
		isEmpty = true;
	}
	~AQueue() { delete[] listArray; }
	void clear() { rear = 0; front = 1; }
	void enqueue(const E& it) {
		if ((isEmpty != true) && (((rear + 1) % maxSize) == front))continue;//to judge whether there is space
		rear = (rear + 1) % maxSize;//Circular increment
		listArray[rear] = it;//enqueue
		isEmpty = false;//this position is not empty
	}
	E dequeue() {
		if (isEmpty == true) continue;//this position is empty
		E it = listArray[front];
		front = (front + 1) % maxSize;//Circular increment
		if ((rear + 1)&maxSize) == front) isEmpty = true;
		return it;
	}
	bool frontValue(E& it) const {
		Assert(length() != 0, "Queue is empty!");
		if (isEmpty == true)return false;//Empty
		it = listArray[front];
		return true;
	}
	virtual int length() const
	{
		if (isEmpty == true)return 0;
		return((rear + maxSize) - front + 1) % maxSize;
	}
};