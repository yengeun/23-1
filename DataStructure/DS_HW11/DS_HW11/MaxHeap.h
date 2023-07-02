#pragma once
#include "HeapNode.h"
#define MAX_ELEMENT 200
using namespace std;

class MaxHeap
{
	HeapNode node[MAX_ELEMENT];
	int size;
public:
	MaxHeap() :size(0) {}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT; }

	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getleft(int i) { return node[i * 2]; }
	HeapNode& getright(int i) { return node[i* 2+1]; }

	void insert(int key) {
		if (isFull()) return;
		int i = ++size;

		while (i != 1 && key > getParent(i).getKey()) {
			node[i] = getParent(i);
			i /= 2;
		}
		node[i].setKey(key);
	}
	HeapNode remove() {
		if (isEmpty()) return NULL;
		HeapNode item = node[1];
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while (child <= size) {
			if (child < size && getleft(parent).getKey() < getright(parent).getKey())
				child++;
			if (last.getKey() >= node[child].getKey())
				break;

			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		node[parent] = last;
		return item;
	}

	HeapNode find() { return node[1]; }

	void display() {
		for (int i = 1, level = 1; i <= size; i++) {
			if (i == level) {
				cout << "\n";
				level *= 2;
			}
			node[i].display();
		}
		cout << "\n------------------------------------------------";
	}

};