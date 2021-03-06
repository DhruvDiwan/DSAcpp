#pragma once
#include<SinglyLinkedLinear.h>
template<typename T>
class tNode {
public:
	T data;
	tNode<T>* leftChild, *parent, * rightSibling;
	tNode() {
		leftChild = NULL;
		parent = NULL;
		rightSibling = NULL;
	}
	tNode(T val) {
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
	T lastAdded();
	int Size();
	SinglyLinkedLinear<T> Elements();
	void displayElements();
	bool isIn(T data);
	bool isRoot(T data);
	void insert(T data);
	T getRoot();
	bool test(T data); // tests the search function
	tNode<T>* search(tNode<T>* ptr, T data);
	T getParent(T data);
	tNode<T>* getChildrenPtr(T data);
	void printChildren(T data);
	void insert(T parent, T data);
  	bool isInternal(T data);

private:
	int size;
	SinglyLinkedLinear<T> elements;
	tNode<T>* root, * last;
};

template<typename T>
tree<T>::tree()
{
	SinglyLinkedLinear<T> elements;
	size = 0;
	root = NULL;
	last = NULL;
}

template<typename T>
T tree<T>::lastAdded() {
	if (!size) {
		throw invalid_argument("No element added");
	}
	return last->data;
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
void tree<T>::insert(T data) {
	size++;
	elements.insertRear(data);
	if (!root) {
		root = new tNode<T>(data);
		last = root;
		return;
	}
	if (last == root) {
		root->leftChild = new tNode<T>(data);
		root->leftChild->parent = root;
		last = root->leftChild;
		return;
	}
	last->rightSibling = new tNode<T>(data);
	last->rightSibling->parent = last->parent;
	last = last->rightSibling;
}

template <typename T>
T tree<T> ::getRoot() {
	if (!root) {
		throw invalid_argument("Empty tree");
	}
	return root->data;
}

template <typename T>
bool tree<T> ::test(T data) {
	bool present = isIn(data);
	tNode<T>* add = search(root, data);
	bool found = bool(add);
	//if (found) cout << "data is " << add->data << endl;
	if ((!present && !found) || (present && found && add->data == data)) return true;
	return false;
}
template<typename T>
void tree<T>::insert(T parent, T data) {
	if (!isIn(parent)) {
		cout << "'" << parent << "' Not found\nUse insert(data) function to add randomly" << endl;
		return;
	}
	size++;
	elements.insertRear(data);
	tNode<T>* ptr = search(root, parent);
	//if (!ptr) {
	//	cout << "Could not locate data , check the code"; // precautionary statement
	//	return;
	//}
	if (!ptr->leftChild) {
		ptr->leftChild = new tNode<T>(data);
		ptr->leftChild->parent = ptr;
		last = ptr;
		return;
	}
	ptr = ptr->leftChild;
	while (ptr->rightSibling) ptr = ptr->rightSibling;
	ptr->rightSibling = new tNode<T>(data);
	ptr->rightSibling->parent = ptr->parent;
	last = ptr;
}

template<typename T>
bool tree<T>::isInternal(T data)
{
	tNode<T>* ptr = search(root, data);
	if (ptr->leftChild) return true;
	return false;
}

template<typename T>
tNode<T>* tree<T>::search(tNode<T>* ptr, T data) {
	if (!ptr) return NULL;
	if (ptr->data == data) return ptr;
	tNode<T>* curr = ptr->leftChild;
	while (curr) {
		tNode<T>* result = search(curr, data);
		if (result) return result;
		curr = curr->rightSibling;
	}
	return NULL;
}

template<typename T>
T tree<T>::getParent(T data) {
	tNode<T>* address = search(root, data);
	if (!address) {
		throw invalid_argument("Data not present");
	}
	if (address == root) {
		throw invalid_argument("Root does not have a parent");
	}
	return address->parent->data;
}

template<typename T>
tNode<T>* tree<T>::getChildrenPtr(T data)
{
	tNode<T>* ptr = search(root, data);
	if (!ptr) {
		throw invalid_argument("Data not present");
	}
	if (!ptr->leftChild) {
		throw invalid_argument("Children not present");
	}
	return ptr->leftChild;
}

template<typename T>
void tree<T>::printChildren(T data)
{
	tNode<T>* ptr = getChildrenPtr(data);
	while (ptr) {
		cout << ptr->data << " ";
		ptr = ptr->rightSibling;
	}
	cout << endl;
}

