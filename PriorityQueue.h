#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
#include"LinkedQueue.h"


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
		/*int findPrio = 0;
		int findHighIndex = 0;
		for (int i = 0; i < size; i++) {
			if (queues[i]->getPrio() > findHighPrio) {
				findHighPrio = queues[i]->getPrio();//가장 나중에 되어야할 pri 
				findIndex = i; // 가장나중에 되어야 pri의 인덱스
			}
		}

		for (int i = 1; i <= findPrio; i++) {
			ItemWithPriority<T> nextIndex = 
		}*/
	}

	void enqueue(const ItemWithPriority<T>& obj) {
		ItemWithPriority<T>* itemToInsert = new ItemWithPriority(obj);
		for (int i = 0; i < 10; i++) {
			if (queues[i] == nullptr) {
				queues[i] =
			}
		}
	}

	T dequeue() {
		if (isEmpty()) {
			throw runtime_error("Priority Queue is empty");
		}
		int highPrio = 0;
		int index;

		for (int i = 0; i < 10; i++) {
			if (queues[i]->getprio() > highPrio) {
				highPrio = queues[i]->getprio();
				index = i;
			}
		}

		T value = queues[index]->value;
		ItemWithPriority<T>* itemToDelete = queues[index];
		queues[index] = nullptr;
		delete itemToDelete;

		return value;

	}

	bool isEmpty() {
		/*int lowPrio = 10;
		int lowPrioIndex;
		for (int i = 0; i < 10; i++) {
			if (queues[i].getPrio() < lowPrio) {
				lowPrio = queues[i].getPrio();
				lowPrioIndex = i;
			}
		}

		return queues[lowPrioIndex] = nullptr;*/
		int count = 0;
		for (int i = 0; i < 10; i++) {
			if (queues[i] == nullptr) {
				count++;
			}
		}
		return count == 10;
	}
	

private:
	LinkedQueue<T>* queues[10];
};

template<typename T>
class ItemWithPriority {
public:
	ItemWithPriority() : value(0), prio(0) {}
	ItemWithPriority(T value, int p) : value(value), prio(p) {}
	
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

#endif
