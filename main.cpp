#include"LinkedQueue.h"
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
	cout << q1.getSize() << endl;
}


void testPriorityQueue() {
	PriorityQueue<ItemWithPriority<int>> q;

	ItemWithPriority<int> i1;
	ItemWithPriority<int> i2;
	ItemWithPriority<int> i3;
	ItemWithPriority<int> i4;
	ItemWithPriority<int> i5;
	ItemWithPriority<int> i6;
	ItemWithPriority<int> i7;
	ItemWithPriority<int> i8;
	ItemWithPriority<int> i9;
	ItemWithPriority<int> i10;
	i1.setValue(1);
	i1.setPrio(1);

	i2.setValue(10);
	i2.setPrio(10);

	i3.setValue(9);
	i3.setPrio(9);

	i4.setValue(8);
	i4.setPrio(8);

	i5.setValue(7);
	i5.setPrio(7);

	i6.setValue(6);
	i6.setPrio(6);

	i7.setValue(4);
	i7.setPrio(4);

	i8.setValue(5);
	i8.setPrio(5);

	i9.setValue(3);
	i9.setPrio(3);

	i10.setValue(2);
	i10.setPrio(2);

	q.enqueue(i1);
	q.enqueue(i2);
	q.enqueue(i3);
	q.enqueue(i4);
	q.enqueue(i5);
	q.enqueue(i6);
	q.enqueue(i7);
	q.enqueue(i8);
	q.enqueue(i9);
	q.enqueue(i10);

	for (int i = 0; i < 10; i++) {
		i1 = q.dequeue();
		cout << i1.getValue() << endl;
	}
}
void testErr() {
	LinkedQueue<int> q1;
	q1.dequeue();
}

int main() {
	try {
		testLinkedQueue();
		testPriorityQueue();
		testErr();
	}
	catch ( runtime_error err) {
		cout << err.what() << endl;
	}
	

	return 0;
}
