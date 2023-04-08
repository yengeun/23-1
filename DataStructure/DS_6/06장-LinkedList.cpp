// 파일명: 6장-LinkedList.cpp
#include "LinkedList.h"
void main()
{
	LinkedList	list;				

	list.insert( 0, new Node(10) );	
	list.insert( 0, new Node(20) );	
	list.insert( 1, new Node(30) );	
	list.insert( list.size(), new Node(40) );
	list.insert( 2, new Node(50) );	
	list.display();	
	list.sum();
	cout << "리스트 내 30을 갖고 있는 노드의 수: " << list.count(30) << endl;

	list.remove( 2 );		
	list.remove(list.size()-1);		
	list.remove(0);					
	list.replace(1, new Node(90));	
	list.display();
	list.sum();
	cout << "리스트 내 30을 갖고 있는 노드의 수: " << list.count(30) << endl;

	list.clear();					
	list.display();		
	list.sum();
	cout << "리스트 내 30을 갖고 있는 노드의 수: " << list.count(30) << endl;
}

