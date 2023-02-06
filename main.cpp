#include"LinkedQueue.h"
#include"PriorityQueue.h"
#include<iostream>

using namespace std;
void testLinkedQueue() {
	LinkedQueue<int> q1;

	for (int i = -100; i < 100; i++) {
		q1.enqueue(i);
	}
	q1.enqueue(1);

	q1.enqueue(2);

	cout << q1.getSize() << endl;

	cout << q1.dequeue() << endl;
	cout << q1.dequeue() << endl;
	cout << q1.getSize();
}

int main() {

	LinkedQueue<int> q1;
	LinkedQueue<int> q2;
	ItemWithPriority<LinkedQueue<int>> item1(q1,10);
	PriorityQueue<ItemWithPriority<LinkedQueue<int>>> pQ;
	pQ.enqueue(item1);
	ItemWithPriority<LinkedQueue<int>> nextLinkedQueue = pQ.dequeue();
	
	
	/*LinkedQueue<char> q1;
	LinkedQueue<char> q2;
	char c = '1';
	q1.enqueue(c);
	ItemWithPriority<LinkedQueue<char>> item1(q1, 10);
	ItemWithPriority<LinkedQueue<char>> item2(q2, 9);
	q2.enqueue(4);
	PriorityQueue<ItemWithPriority<LinkedQueue<int>>> pQ;
	pQ.enqueue(item2);
	pQ.enqueue(item1);
	item2 = pQ.dequeue();
	q1 = item1.getValue();
	cout << q1.dequeue();
	*/
	return 0;
}
