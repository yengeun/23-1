#include "MaxHeap.h"
#include "HeapNode.h"
#include <iostream>
using namespace std;

void heapSort(int a[], int n) {
	MaxHeap h;
	for (int i = 0; i < n; i++)
		h.insert(a[i]);
	for (int i = 0; i <= n; i++)
		a[i] = h.remove().getKey();
}

	
void main()
{
	MaxHeap heap;
	int data[10] = { 0, 10, -3, 7, 22, 33, 39, 4, -9, -5 };

	cout << "정렬 전: ";
	for (int i = 0; i < 10; i++) {
		cout << data[i] << " ";
	}

	heapSort(data, 10);
	cout << endl << "정렬 후: ";
	for (int i = 0; i < 10; i++) {
		cout << data[i] << " ";
	}
	
}