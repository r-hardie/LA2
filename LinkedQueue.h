#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include<iostream>

using namespace std;

template<typename T>
class QueueNode {
public:
	QueueNode() {
	}
	QueueNode(const T& v) {
		value = v;
		next = nullptr;
	}
	T value;
	QueueNode <T>* next;
};

template<typename T>
class ItemWithPriority {
public:
	ItemWithPriority() {}
	ItemWithPriority(T v, int p) : value(v), prio(p) {}
	T getValue() {
		return value;
	}
	void setValue(T v) {
		value = v;
	}
	void setPrio(int p) {
		prio = p;
	}
	int getPrio() {
		return prio;
	}
private:
	T value;
	int prio;
};

template<typename T>
class LinkedQueue {
public:
	LinkedQueue() {
		size = 0;
		front = back = nullptr;
	}
	LinkedQueue(T v) {
		size = 0;
		enqueue(v);
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

		if (front == nullptr) {
			front = nodeToInsert;
		}
		else {
			back = front;
			while (true) {
				if (back->next == nullptr) {
					break;
				}
				back = back->next;
			}
			back->next = nodeToInsert;
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

template<typename T>
class PriorityQueue {
public:
	PriorityQueue() {
		for (int i = 0; i < 10; i++) {
			queues[i] = nullptr;
		}
	}
	~PriorityQueue() {
		for (int i = 0; i < 10; i++) {
			if (queues[i] != nullptr) {
				delete queues[i];
			}
		}
	}

	void enqueue(T& itemP) {
		queues[itemP.getPrio() - 1] = new LinkedQueue<T>(itemP);

		/*	for (int i = 9; i >= 0; i--) {      //Giving up implementing FIFO between equal priorities
				T tempPrio;
				if (queues[i] != nullptr) {

					LinkedQueue<T> comparePrio = *queues[i];
					tempPrio = comparePrio.dequeue();

					if (tempPrio.getPrio() < itemP.getPrio()) {
						for (int j = 0; j < i; j++) {
							if (queues[j + 1] != nullptr) {
								queues[j] = new LinkedQueue<T>(*queues[j + 1]);
							}
						}
						queues[i] = new LinkedQueue<T>(itemP);
						break;
					}
				}
				else {
					queues[i] = new LinkedQueue<T>(itemP);
					break;
				}
			}

	}

	T dequeue() {
		for (int i = 10; i > 0; --i) {
			if (queues[i - 1]->isEmpty() == false) {
				return queues[i - 1]->dequeue();
			}
		}
		/*T result;                           //Giving up implementing FIFO between equal priorities
		for (int i = 10; i > 0; i--) {
			if (queues[i - 1] != nullptr) {
				result = queues[i - 1]->dequeue();
				break;
				//return queues[i - 1]->dequeue();
			}
		}
		for (int i = 9; i > 0; i--) {
			queues[i] = queues[i - 1];
			if (i == 1) {
				queues[i] = nullptr;
			}
			if (queues[i - 1] == nullptr) {
				break;
			}
		}

		return result;*/
	}

private:
	LinkedQueue<T>* queues[10];
};
#endif
