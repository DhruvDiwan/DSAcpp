#pragma once
#include<SinglyLinkedLinear.h>
template<typename T>
class Node {
public:
	T data;
	Node<T>* leftChild; *parent, * rightSibling;
	Node() {
		leftChild = NULL;
		parent = NULL;
		rightSibling = NULL;
	}
	Node(T val) {
		data = val;
		leftChild = NULL;
		parent = NULL;
		rightSibling = NULL;
	}
};


template<typename T>
class tree
{
public:
	tree();
	int Size();
	SinglyLinkedLinear<T> Elements();
	void displayElements();
	bool isIn(T data);
	bool isRoot(T data);
	bool isInternal(T data);
	void insert(T parent, T data);
	void del(T data);

private:
	int size;
	SinglyLinkedLinear<T> elements;
	Node<T>* root;
};

template<typename T>
tree<T>::tree()
{
	SinglyLinkedLinear elements;
	size = 0;
	Node<T>* root = new Node<T>;
}

template<typename T>
int tree<T>::Size() {
	return size;
}

template<typename T>
SinglyLinkedLinear<T> tree<T>::Elements() {
	return elements;
}

template<typename T>
void tree<T>::displayElements() {
	elements.display();
}

template<typename T>
bool tree<T>::isIn(T data) {
	return elements.isIn(data);
}

template<typename T>
bool tree<T>::isRoot(T data) {
	if (!isIn(data)) return false;
	return bool(root->data == data);
}

template<typename T>
bool tree<T>::isInternal(T data) {
	if (!isIn(data)) return false;
	return bool(!(root->data == data));
}

template<typename T>
void tree<T>::insert(T parent, T data) {
	if (!isIn(parent)) {
		cout << "'" << parent << "' Not found" << endl;
		return;
	}

}