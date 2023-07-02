#include <iostream>
using namespace std;
#define MAX_QUEUE_SIZE 100
class BinaryNode {
	int data; // key 값이 됩니다. 
	BinaryNode* left; // 왼쪽 자식 노드 링크
	BinaryNode* right; // 오른쪽 자식 노드 링크
public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		: data(val), left(l), right(r) {}
	~BinaryNode() {}

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }

	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }
};
class CircularQueue {
	int front;
	int rear;
	BinaryNode* data[MAX_QUEUE_SIZE];
public:
	CircularQueue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return(rear + 1) % MAX_QUEUE_SIZE == front; }
	void enqueue(BinaryNode* n) {
		if (isFull()) cout << "error: 큐가 포화상태입니다" << endl;
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}
	BinaryNode* dequeue() {
		if (isEmpty()) cout << "error: 큐가 공백상태입니다" << endl;
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
};

class BinaryTree
{
protected: // Binary Search Tree class에 상속해 주는 멤버 변수입니다.
	BinaryNode* root;
public:
	BinaryTree() : root(NULL) {}
	~BinaryTree() {}

	void setRoot(BinaryNode* node) { root = node; } // 내가 원하는 node로 root를 만들어 줍니다.
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }
	int getCount() { return isEmpty() ? 0 : getCount(root); }; // 외부에서 사용하는 함수
	void inorder() { // 외부에서 사용하면
		cout << "inorder: "; // 중위순회inorder를 사용했다고 콘솔창에 출력한 뒤에, 
		inorder(root);		// root부터 inorder 함수의 recursion을 시작합니다. 
	}
	int getCount(BinaryNode* node) { 
		/* 외부에서 위의 getCount() 사용하면, root가 캡슐화되어 있기 때문에,
		root부터 시작해서 getCount() recursion을 시작할 수 있습니다. */
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft())
			+ getCount(node->getRight());
	}
	int getHeight();
	int getHeight(BinaryNode* node);
	int calcLevel(int n);
	int calcLevel(BinaryNode* node, int n, int level);
	void levelorder(); // Circular Queue를 이용해 순회(traversal) 합니다. 
	void inorder(BinaryNode* node);
};

class BinSrchTree : public BinaryTree // BinaryTree class를 상속 받아 옵니다. 
{	// root와 모든 멤버 함수들이 상속됩니다.
public:
	BinSrchTree(void) {}
	~BinSrchTree(void) {}

	BinaryNode* search(int key); // 외부에서 쓰는 함수
	BinaryNode* search(BinaryNode* n, int key); // 내부에서 recursion을 위한 함수

	void insert(BinaryNode* n);
	void insert(BinaryNode* r, BinaryNode* n);

	void remove(int key);
	void remove(BinaryNode* parent, BinaryNode* node);
};

void BinaryTree::inorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL) inorder(node->getLeft());
		cout << " [" << node->getData() << "] "; // node 가 포인터 객체니까 -> 써서 멤버 함수를 호출합니다.
		if (node->getRight() != NULL) inorder(node->getRight());
	}
}
void BinaryTree::levelorder() {
	cout << endl << "levelorder: "; // level order를 시작한다고 알려주고,
	if (!isEmpty()) { // 지금 트리가 비어있지 않으면,
		CircularQueue q; // 큐를 만들어서
		q.enqueue(root); // 큐에 루트를 넣은 뒤
		while (!q.isEmpty()) { // 큐에 데이터가 있는 동안
			BinaryNode* n = q.dequeue(); // 큐에서 꺼내 와서 
			if (n != NULL) {			// 아래 연산을 수행합니다. 
				cout << " [" << n->getData() << "] ";
				q.enqueue(n->getLeft());
				q.enqueue(n->getRight());
			}
		}
	}
	cout << endl;
}

//과제 search함수 부분
BinaryNode* BinSrchTree::search(BinaryNode* n, int key) {
	if (n == NULL) return NULL;
	if (key == n->getData()) return n;
	else if (key < n->getData()) return search(n->getLeft(), key);
	else return search(n->getRight(), key);
}

//트리의 높이:루트노드1개+왼쪽 섭트리와 오른쪽 섭트리 중 더 큰 섭트리의 높이
int BinaryTree::getHeight() { return isEmpty() ? 0 : getHeight(root); }
int BinaryTree::getHeight(BinaryNode* node)
{
	if (node == nullptr)return 0;
	int hLeft = getHeight(node->getLeft());
	int hRight = getHeight(node->getRight());
	return (hLeft > hRight) ? 1 + hLeft : 1 + hRight;
}

//어떤 노드가 속한 레벨 계산
//: left 또는 right로 내려갈 때마다 레벨을 1씩 증가
//: 데이터가 n인 노드를 찾으면 해당 level 반환
int BinaryTree::calcLevel(int n) { return isEmpty() ? 0 : calcLevel(root, n, 1); }
//root node의 레벨1부터 시작해서 데이터가 n인 노드의 레벨 찾기
//1은 레벨임. 저기서 레벨이 하나씩 증가함
//root로부터 n 찾아
int BinaryTree::calcLevel(BinaryNode* node, int n, int level)
{
	if (node == nullptr)return 0;
	if (node->getData() == n)return level;
	//왼쪽으로 내려가 그럼 레벨1증가 
	int ll = calcLevel(node->getLeft(), n, level + 1);
	//ll이 0이 아니면 찾은 ll return 
	if (ll != 0)return ll;
	//오른쪽으로 내려가 그리고 레벨 1 증가
	ll = calcLevel(node->getRight(), n, level + 1);
	return ll;

}
void BinSrchTree::insert(BinaryNode* n) { // n 포인터 객체 삽입
	if (n == NULL) return;
	if (isEmpty()) root = n; // 트리가 비어 있으면 root에다 넣고, 
	else insert(root, n);	// root가 아니면 insert 함수 recursion
}

void BinSrchTree::insert(BinaryNode* r, BinaryNode* n) {
	if (n->getData() == r->getData()) return; // key값이 unique하기 때문에
	else if (n->getData() < r->getData()) { 
		// 내가 넣고자 하는 노드 n의 key 값이 지금 recursion을 하고 있는 노드 r의 키값보다 작으면,
		if (r->getLeft() == NULL) r->setLeft(n); // 왼쪽 자식이 비어있으면 왼쪽에 n을 넣고(연결해 주고)
		else insert(r->getLeft(), n);	// 비어 있지 않으면, 왼쪽 자식 노드를 매개변수로 recursion
	}
	else {
		if (r->getRight() == NULL) r->setRight(n);
		else insert(r->getRight(), n);
	}
}

void BinSrchTree::remove(int key) {
	if (isEmpty()) return;

	BinaryNode* parent = NULL;
	BinaryNode* node = root;

	while (node != NULL && node->getData() != key) {
		parent = node;
		node = (key < node->getData()) ? node->getLeft() : node->getRight();
	}
	if (node == NULL) {
		cout << "Error: key is not in the tree!" << endl;
		return;
	}
	else remove(parent, node);
}

void BinSrchTree::remove(BinaryNode* parent, BinaryNode* node) {
	if (node->isLeaf()) { // leaf 노드일 때는 생각 없이 바로 지우면 됩니다. 
		if (parent == NULL) root = NULL;
		else { // 지금 노드가 parent 노드의 왼쪽 자식인지 오른쪽 자식인지 판단해서 해당 위치를 null로 바꿔 줍니다.
			if (parent->getLeft() == node)
				parent->setLeft(NULL);
			else
				parent->setRight(NULL);
		}
	}
	// 둘 중 한 자식 노드가 비어 있을 때, 역시 편하게 삭제합니다. 
	else if (node->getLeft() == NULL || node->getRight() == NULL) {
		BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight(); // 자식 노드를 임시로 객체 하나 만든 뒤에, 
		if (node == root) // root를 지우는 경우는 자식을 곧바로 root로 바꿔 줍니다.
			root = child;
		else {			// root가 아닌 경우, 
			if (parent->getLeft() == node) // 지우고자 하는 node가 node의 부모의 왼쪽인지, 오른쪽인지 판단해서 
				parent->setLeft(child);		// 임시로 저장한 child를 부모 노드에 연결을 해 주면, 지금 삭제하려고 하는 node는 부모로부터 링크가 끊기게 됩니다. 
			else
				parent->setRight(child);
		}
	}

	else { // 왼쪽, 오른쪽 많은 노드를 가진 subtree가 있을 때, 
		BinaryNode* succp = node;				// 오른쪽 subtree의 leftmost (subtree.first)로 바꿔 주기 위한 변수
		BinaryNode* succ = node->getRight();	// 이렇게 되면 successor로 바꿔 줍니다. 
		BinaryNode* succp2 = node;				// 왼쪽 subtree의 rightmost로 바꿔 주기 위한 변수
		BinaryNode* succ2 = node->getLeft();	// 이렇게 되면 삭제하는 노드는 삭제하는 노드의 predecessor 
		int leftmost, rightmost;

		while (succ->getLeft() != NULL) {// 삭제하고자 하는 노드보다 바로 뒤에 있는(큰) 노드
			succp = succ;
			succ = succ->getLeft();
		}

		while (succ2->getRight() != NULL) { // 삭제하고자 하는 노드보다 바로 앞에 있는(작은) 노드
			succp2 = succ2;
			succ2 = succ2->getRight();
		}

		leftmost = succ->getData() - node->getData();
		rightmost = node->getData() - succ2->getData();
		if (leftmost < rightmost) {
			if (succp->getLeft() == succ)
				succp->setLeft(succ->getRight());
			else
				succp->setRight(succ->getRight());

			node->setData(succ->getData());
			node = succ;
		}
		else if (leftmost > rightmost) {
			if (succp2->getRight() == succ2)
				succp2->setRight(succ2->getLeft());
			else
				succp2->setLeft(succ2->getLeft());

			node->setData(succ2->getData());
			node = succ2;
		}
	}
	delete node;
}

int main()
{
	BinSrchTree tree; // Binary Tree class를 상속 받아 옵니다. Base class에 해당하는 Binary Tree class의 객체는 자동으로 생성됩니다.

	int temp_in = 0;
	int num_of_nodes = 10;
	int arr[10];
	arr[0] = 35;
	arr[1] = 18;
	arr[2] = 7;
	arr[3] = 26;
	arr[4] = 12;
	arr[5] = 3;
	arr[6] = 68;
	arr[7] = 22;
	arr[8] = 30;
	arr[9] = 99;

	cout << "삽입 연산을 수행하여 이진탐색트리를 만듭니다." << endl;
	cout << "[삽입연산] : ";
	for (int i = 0; i < num_of_nodes; i++) {
		tree.insert(new BinaryNode(arr[i])); // 동적으로 생성합니다. 몇 개의 노드를 생성할지 모르니까요.
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	tree.inorder();
	tree.levelorder();

	cout << endl << "BST 정보 출력" << endl;
	cout << "노드 개수: " << tree.getCount() << endl;

	/*cout << endl << "26을 찾습니다. " << endl;
	tree.search(26);
	cout << endl << "25를 찾습니다. " << endl;
	tree.search(25);*/

	cout << endl << "Original BST 정보 출력" << endl;
	tree.levelorder(); 
	cout << "3 삭제" << endl;
	tree.remove(3);
	tree.levelorder();
	cout << "삭제 후 BST 정보 출력" << endl;
	cout << "노드 개수: " << tree.getCount() << endl;
	cout << "68 삭제" << endl;
	tree.remove(68);
	tree.levelorder();
	cout << "삭제 후 BST 정보 출력" << endl;
	cout << "노드 개수: " << tree.getCount() << endl;
	cout << "18 삭제" << endl;
	tree.remove(18);
	tree.levelorder();
	cout << "삭제 후 BST 정보 출력" << endl;
	cout << "노드 개수: " << tree.getCount() << endl;

	return 0;
}