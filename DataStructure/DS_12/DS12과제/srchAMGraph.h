#pragma once
#include "AdjListGraph.h"
#include "CircularQueue.h"
using namespace std;

void BFS(int v) {
	visited[v] = true;
	cout << getVertex(v);

	CircularQueue que;
	que.enqueue(v);

	while (!que.isEmpty()) {
		int v = que.dequeue();
		for (int w = 0; w <size; w++)
			if (isLinked(v, w) && visited[w] == false) {
				visited[w] = true;
				cout << getVertex(w);
				que.enque(w)
			}
	}


}
