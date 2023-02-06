#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
#include"LinkedQueue.h"
#include<iostream>


template<typename T>
class ItemWithPriority {
public:
	ItemWithPriority(){}
	ItemWithPriority(T v, int p) {
		value = v;
		prio = p;
	}
	ItemWithPriority(T v) {
		value = v;
		prio = 1;
	}
	~ItemWithPriority() {

	}
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

	void enqueue(const T& obj) {
		if (isFull()) {
			throw ("Priority Queue is full");
		}
		ItemWithPriority<T>* itemToInsert = new ItemWithPriority<T>(obj);
		for (int i = 0; i < 10; i++) {
			if (queues[i] == nullptr) {
				queues[i] = itemToInsert;
				break;
			}
		}
		ItemWithPriority<T>* temp;
		while (true) {
			bool lFinish = true;
			for (int i = 0; i < 10; i++) {
				if(queues[i + 1] == nullptr){
					break;
				}
				if (queues[i]->getPrio() < queues[i + 1]->getPrio()) {
					temp = queues[i];
					queues[i] = queues[i + 1];
					queues[i + 1] = queues[i];

					lFinish = false;
				}
			}

			if (lFinish == true) {
				break;
			}
		}
	}

	T dequeue() {
		if (isEmpty()) {
			throw runtime_error("Priority Queue is empty");
		}

		T value = queues[0]->getValue();
		
		ItemWithPriority<T>* itemToDelete = queues[0];
		for (int i = 0; i < 10; i++) {
			if (i == 9) {
				queues[i] = nullptr;
				break;
			}
			if (queues[i + 1] == nullptr) {
				queues[i] = nullptr;
				break;
			}

			queues[i] = queues[i + 1];
		}

		delete itemToDelete;

		return value;

	}

	bool isEmpty() {
		int count = 0;
		for (int i = 0; i < 10; i++) {
			if (this->queues[i] == nullptr) {
				count++;
			}
		}
		return count == 10;
	}

	bool isFull() {
		int count = 0;
		for (int i = 0; i < 10; i++) {
			if (this->queues[i] != nullptr) {
				count++;
			}
		}
		return count == 10;
	}
	

private:
	//LinkedQueue<T>* queues[10];
	ItemWithPriority<T>* queues[10];
};
#endif
	int prio;
};

#endif
