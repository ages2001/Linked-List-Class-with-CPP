#include "Student.h"
#pragma once

class Node {

private:
    Student data;
    Node * next;
    Node * prev;

public:
    Student getData();
    void setData(Student *data);

    Node * getNext();
    void setNext(Node * next);

    Node * getPrev();
    void setPrev(Node * prev);

    Node(Student *data);
    Node(Student *data, Node *next, Node *prev);

};
