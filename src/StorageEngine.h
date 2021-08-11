#pragma once

template <typename DataType>
class Node {
private:
	DataType data;
	Node* rightChild;
	Node* belowChile;
public:
	Node();
	~Node();
};

template <typename DataType>
Node<DataType>::Node() {}

template<typename DataType>
Node<DataType>::~Node() {
}
