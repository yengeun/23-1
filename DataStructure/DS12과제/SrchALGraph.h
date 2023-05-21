#pragma once
#include "AdjListGraph.h"
#include "CircularQueue.h"

void BFS(int v) {
	visited[v] = true;
	cout << getVertex(v);

	CircularQueue que;
	que.enqueue(v);

	while (!= que.isEmpty()) {
		int v = que.dequeue();
		for (Node* w = adj[v]) {
			int id = w->getId();
			if (!visited[id]) {
				visited[id] = true;
				cout << getVertex(id);
				que.enqueue(id);
			}
		}
	}
}

