#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include<iostream>

using namespace std;

template<typename T>
class QueueNode {
public:
	QueueNode(){
	}
	QueueNode(const T& v) {
		value = v;
		next = nullptr;
	}
	T value;
	QueueNode <T>* next;
};

template<typename T>
class LinkedQueue {
public:
	LinkedQueue() {
		size = 0;
		front = back = nullptr;
	}

	~LinkedQueue() {
		while (front != nullptr) {
			QueueNode<T>* nextNode = front->next;
			delete front;
			front = nextNode;
		}
	}

	void enqueue(const T& item) {
		QueueNode<T>* nodeToInsert = new QueueNode<T>(item);
		back = nodeToInsert;
		back->next = nodeToInsert;
		

		if (front == nullptr) {
			front = nodeToInsert;
		}

		size++;
	}

	T dequeue() {
		if (isEmpty()) {
			throw runtime_error("Queue is empty");
		}

		T value = front->value;
		QueueNode<T>* nodeToDelete = front;
		front = front->next;
		delete nodeToDelete;

		size--;

		if (size == 0) {
			back = nullptr;
		}
		return value;
	}

	bool isEmpty() {
		return front == nullptr;
	}
	int getSize() {
		return size;
	}
private:
	QueueNode<T>* front;
	QueueNode<T>* back;
	int size;

};
#endif