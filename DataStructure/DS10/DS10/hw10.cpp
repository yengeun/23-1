#include <iostream>
using namespace std;
#define MAX_QUEUE_SIZE 100
class BinaryNode {
	int data; // key ���� �˴ϴ�. 
	BinaryNode* left; // ���� �ڽ� ��� ��ũ
	BinaryNode* right; // ������ �ڽ� ��� ��ũ
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
		if (isFull()) cout << "error: ť�� ��ȭ�����Դϴ�" << endl;
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}
	BinaryNode* dequeue() {
		if (isEmpty()) cout << "error: ť�� ��������Դϴ�" << endl;
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
};

class BinaryTree
{
protected: // Binary Search Tree class�� ����� �ִ� ��� �����Դϴ�.
	BinaryNode* root;
public:
	BinaryTree() : root(NULL) {}
	~BinaryTree() {}

	void setRoot(BinaryNode* node) { root = node; } // ���� ���ϴ� node�� root�� ����� �ݴϴ�.
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }
	int getCount() { return isEmpty() ? 0 : getCount(root); }; // �ܺο��� ����ϴ� �Լ�
	void inorder() { // �ܺο��� ����ϸ�
		cout << "inorder: "; // ������ȸinorder�� ����ߴٰ� �ܼ�â�� ����� �ڿ�, 
		inorder(root);		// root���� inorder �Լ��� recursion�� �����մϴ�. 
	}
	int getCount(BinaryNode* node) { 
		/* �ܺο��� ���� getCount() ����ϸ�, root�� ĸ��ȭ�Ǿ� �ֱ� ������,
		root���� �����ؼ� getCount() recursion�� ������ �� �ֽ��ϴ�. */
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft())
			+ getCount(node->getRight());
	}
	int getHeight();
	int getHeight(BinaryNode* node);
	int calcLevel(int n);
	int calcLevel(BinaryNode* node, int n, int level);
	void levelorder(); // Circular Queue�� �̿��� ��ȸ(traversal) �մϴ�. 
	void inorder(BinaryNode* node);
};

class BinSrchTree : public BinaryTree // BinaryTree class�� ��� �޾� �ɴϴ�. 
{	// root�� ��� ��� �Լ����� ��ӵ˴ϴ�.
public:
	BinSrchTree(void) {}
	~BinSrchTree(void) {}

	BinaryNode* search(int key); // �ܺο��� ���� �Լ�
	BinaryNode* search(BinaryNode* n, int key); // ���ο��� recursion�� ���� �Լ�

	void insert(BinaryNode* n);
	void insert(BinaryNode* r, BinaryNode* n);

	void remove(int key);
	void remove(BinaryNode* parent, BinaryNode* node);
};

void BinaryTree::inorder(BinaryNode* node) {
	if (node != NULL) {
		if (node->getLeft() != NULL) inorder(node->getLeft());
		cout << " [" << node->getData() << "] "; // node �� ������ ��ü�ϱ� -> �Ἥ ��� �Լ��� ȣ���մϴ�.
		if (node->getRight() != NULL) inorder(node->getRight());
	}
}
void BinaryTree::levelorder() {
	cout << endl << "levelorder: "; // level order�� �����Ѵٰ� �˷��ְ�,
	if (!isEmpty()) { // ���� Ʈ���� ������� ������,
		CircularQueue q; // ť�� ����
		q.enqueue(root); // ť�� ��Ʈ�� ���� ��
		while (!q.isEmpty()) { // ť�� �����Ͱ� �ִ� ����
			BinaryNode* n = q.dequeue(); // ť���� ���� �ͼ� 
			if (n != NULL) {			// �Ʒ� ������ �����մϴ�. 
				cout << " [" << n->getData() << "] ";
				q.enqueue(n->getLeft());
				q.enqueue(n->getRight());
			}
		}
	}
	cout << endl;
}

//���� search�Լ� �κ�
BinaryNode* BinSrchTree::search(BinaryNode* n, int key) {
	if (n == NULL) return NULL;
	if (key == n->getData()) return n;
	else if (key < n->getData()) return search(n->getLeft(), key);
	else return search(n->getRight(), key);
}

//Ʈ���� ����:��Ʈ���1��+���� ��Ʈ���� ������ ��Ʈ�� �� �� ū ��Ʈ���� ����
int BinaryTree::getHeight() { return isEmpty() ? 0 : getHeight(root); }
int BinaryTree::getHeight(BinaryNode* node)
{
	if (node == nullptr)return 0;
	int hLeft = getHeight(node->getLeft());
	int hRight = getHeight(node->getRight());
	return (hLeft > hRight) ? 1 + hLeft : 1 + hRight;
}

//� ��尡 ���� ���� ���
//: left �Ǵ� right�� ������ ������ ������ 1�� ����
//: �����Ͱ� n�� ��带 ã���� �ش� level ��ȯ
int BinaryTree::calcLevel(int n) { return isEmpty() ? 0 : calcLevel(root, n, 1); }
//root node�� ����1���� �����ؼ� �����Ͱ� n�� ����� ���� ã��
//1�� ������. ���⼭ ������ �ϳ��� ������
//root�κ��� n ã��
int BinaryTree::calcLevel(BinaryNode* node, int n, int level)
{
	if (node == nullptr)return 0;
	if (node->getData() == n)return level;
	//�������� ������ �׷� ����1���� 
	int ll = calcLevel(node->getLeft(), n, level + 1);
	//ll�� 0�� �ƴϸ� ã�� ll return 
	if (ll != 0)return ll;
	//���������� ������ �׸��� ���� 1 ����
	ll = calcLevel(node->getRight(), n, level + 1);
	return ll;

}
void BinSrchTree::insert(BinaryNode* n) { // n ������ ��ü ����
	if (n == NULL) return;
	if (isEmpty()) root = n; // Ʈ���� ��� ������ root���� �ְ�, 
	else insert(root, n);	// root�� �ƴϸ� insert �Լ� recursion
}

void BinSrchTree::insert(BinaryNode* r, BinaryNode* n) {
	if (n->getData() == r->getData()) return; // key���� unique�ϱ� ������
	else if (n->getData() < r->getData()) { 
		// ���� �ְ��� �ϴ� ��� n�� key ���� ���� recursion�� �ϰ� �ִ� ��� r�� Ű������ ������,
		if (r->getLeft() == NULL) r->setLeft(n); // ���� �ڽ��� ��������� ���ʿ� n�� �ְ�(������ �ְ�)
		else insert(r->getLeft(), n);	// ��� ���� ������, ���� �ڽ� ��带 �Ű������� recursion
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
	if (node->isLeaf()) { // leaf ����� ���� ���� ���� �ٷ� ����� �˴ϴ�. 
		if (parent == NULL) root = NULL;
		else { // ���� ��尡 parent ����� ���� �ڽ����� ������ �ڽ����� �Ǵ��ؼ� �ش� ��ġ�� null�� �ٲ� �ݴϴ�.
			if (parent->getLeft() == node)
				parent->setLeft(NULL);
			else
				parent->setRight(NULL);
		}
	}
	// �� �� �� �ڽ� ��尡 ��� ���� ��, ���� ���ϰ� �����մϴ�. 
	else if (node->getLeft() == NULL || node->getRight() == NULL) {
		BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight(); // �ڽ� ��带 �ӽ÷� ��ü �ϳ� ���� �ڿ�, 
		if (node == root) // root�� ����� ���� �ڽ��� ��ٷ� root�� �ٲ� �ݴϴ�.
			root = child;
		else {			// root�� �ƴ� ���, 
			if (parent->getLeft() == node) // ������� �ϴ� node�� node�� �θ��� ��������, ���������� �Ǵ��ؼ� 
				parent->setLeft(child);		// �ӽ÷� ������ child�� �θ� ��忡 ������ �� �ָ�, ���� �����Ϸ��� �ϴ� node�� �θ�κ��� ��ũ�� ����� �˴ϴ�. 
			else
				parent->setRight(child);
		}
	}

	else { // ����, ������ ���� ��带 ���� subtree�� ���� ��, 
		BinaryNode* succp = node;				// ������ subtree�� leftmost (subtree.first)�� �ٲ� �ֱ� ���� ����
		BinaryNode* succ = node->getRight();	// �̷��� �Ǹ� successor�� �ٲ� �ݴϴ�. 
		BinaryNode* succp2 = node;				// ���� subtree�� rightmost�� �ٲ� �ֱ� ���� ����
		BinaryNode* succ2 = node->getLeft();	// �̷��� �Ǹ� �����ϴ� ���� �����ϴ� ����� predecessor 
		int leftmost, rightmost;

		while (succ->getLeft() != NULL) {// �����ϰ��� �ϴ� ��庸�� �ٷ� �ڿ� �ִ�(ū) ���
			succp = succ;
			succ = succ->getLeft();
		}

		while (succ2->getRight() != NULL) { // �����ϰ��� �ϴ� ��庸�� �ٷ� �տ� �ִ�(����) ���
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
	BinSrchTree tree; // Binary Tree class�� ��� �޾� �ɴϴ�. Base class�� �ش��ϴ� Binary Tree class�� ��ü�� �ڵ����� �����˴ϴ�.

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

	cout << "���� ������ �����Ͽ� ����Ž��Ʈ���� ����ϴ�." << endl;
	cout << "[���Կ���] : ";
	for (int i = 0; i < num_of_nodes; i++) {
		tree.insert(new BinaryNode(arr[i])); // �������� �����մϴ�. �� ���� ��带 �������� �𸣴ϱ��.
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	tree.inorder();
	tree.levelorder();

	cout << endl << "BST ���� ���" << endl;
	cout << "��� ����: " << tree.getCount() << endl;

	/*cout << endl << "26�� ã���ϴ�. " << endl;
	tree.search(26);
	cout << endl << "25�� ã���ϴ�. " << endl;
	tree.search(25);*/

	cout << endl << "Original BST ���� ���" << endl;
	tree.levelorder(); 
	cout << "3 ����" << endl;
	tree.remove(3);
	tree.levelorder();
	cout << "���� �� BST ���� ���" << endl;
	cout << "��� ����: " << tree.getCount() << endl;
	cout << "68 ����" << endl;
	tree.remove(68);
	tree.levelorder();
	cout << "���� �� BST ���� ���" << endl;
	cout << "��� ����: " << tree.getCount() << endl;
	cout << "18 ����" << endl;
	tree.remove(18);
	tree.levelorder();
	cout << "���� �� BST ���� ���" << endl;
	cout << "��� ����: " << tree.getCount() << endl;

	return 0;
}