#pragma once
#include "Node.h"
#define MAX_VTXS 256
using namespace std;
class AdjListGraph {
protected:
	int size;
	char vertices[MAX_VTXS];
	Node* adj[MAX_VTXS];
public:
	AdjListGraph() : size(0) {}
	~AdjListGraph() { reset(); }
	void reset(void) {
		for (int i = 0; i < size; i++) {
			if (adj[i] != NULL) delete adj[i];
		}
		size = 0;
	}

	bool isEmpty() { return (size == 0); }
	bool isFull() { return (size >= MAX_VTXS); }
	char getVertex(int i) { return vertices[i]; }

	void insertVertex(char val) {
		if (!isFull()) {
			vertices[size] = val;
			adj[size++] = NULL;
		}
		else cout << "Error: 그래프 정점 개수 초과" << endl;
	}

	void insertEdge(int u, int v) {
		adj[u] = new Node(v, adj[u]);
		adj[v] = new Node(u, adj[v]);
	}

	void display() {
		cout << endl << size;
		for (int i = 0; i < size; i++) {
			cout << "  " << getVertex(i);
			for (Node* v = adj[i]; v != NULL; v = v->getLink())
				cout << "  " << getVertex(v->getId());
			cout << endl;
		}
	}
	Node* adjacent(int v) { return adj[v]; }
	void load(char* filename) {
		FILE* fp = fopen(filename, "r");
		if (fp != NULL) {
			int n;
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				char str[80];
				cin >> str;
				insertVertex(str[0]);
				for (int j = 0; j < n; j++) {
					int val;
					cin >> val;
					if (val != 0)
						insertEdge(i, j);
				}
			}
			fclose(fp);
		}
	}

	void store(char* filename) {
		FILE* fp = fopen(filename, "w");
		if (fp != NULL) {
			display(fp);
			fclose(fp);
		}
	}
};