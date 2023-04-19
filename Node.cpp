#include "Node.h"

Student Node::getData() {
    return this->data;
}

void Node::setData(Student *data) {
    this->data = *data;
}

Node * Node::getNext() {
    return this->next;
}

void Node::setNext(Node * next) {
    this->next = next;
}

Node * Node::getPrev() {
    return this->prev;
}

void Node::setPrev(Node * prev) {
    this->prev = prev;
}

Node::Node(Student *data, Node *next, Node *prev) {
    setData(data);
    setNext(next);
    setPrev(prev);
}

Node::Node(Student *data) {
    setData(data);
    setNext(NULL);
    setPrev(NULL);
}
