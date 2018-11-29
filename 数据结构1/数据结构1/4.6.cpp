/****************
*Author:Zhou Yao(201730685202)
*Date:2018-09-26
*Description:这是倒置链表中元素的函数(Exercise 4.6)
****************/
template <typename E> class LList :public List<E>
{
private:
	Link<E>* head;
	Link<E>* tail;
	Link<E>* curr;

	void init()
	{
		curr = tail = head = new Link<E>;
		cnt = 0;
	}
	void removeall()
	{
		while (head != NULL)
		{
			curr = head;
			head = head->next;
			delete curr;
		}
	}
public:
	LList(int size = defaultSize) { init(); }
	~LList() { removeall(); }
	void clear{ removeall(); init(); }

	void reverse()//to reverse the linked list.
	{
		//to judge whether the LList is empty 
		if (head == tail)
			cout << "Empty List!";
		
		//to create two pointers to the two elements to be reversed
		Link<E>* temp1 = head->next;
		Link<E>* temp2 = temp1->next;
		//to reverse temp1 and temp2
		while (temp1 != tail)
		{
			Link<E>* temp3 = temp2->next;//to remember the previous position of temp2->next;
			temp2->next = temp1;//to change the direction of temp2
			temp1 = temp2;
			temp2 = temp3;//temp1 and temp2 move one step right
		}
		head->next = temp1;//to determine the position of head pointer
	}
};