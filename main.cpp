#include"LinkedQueue.h"
//#include"PriorityQueue.h"

#include<iostream>

using namespace std;

int main() {
	LinkedQueue<int> q1;


	for (int i = -100; i < 100; i++) {
		q1.enqueue(i);
	}
	q1.enqueue(1);

	q1.enqueue(2);

	cout << q1.getSize() <<endl;

	cout << q1.dequeue() <<endl;
	cout << q1.dequeue() <<endl;
	
	cout << q1.getSize();
	return 0;
}
