#include "Node.h"
#include "DoublyLinkedList.h"

bool DoublyLinkedList::isEmpty() {
    return head == NULL;
}

void DoublyLinkedList::addSortByOgrenciNo(Student *data) {

    Node * addNode;

    if (isEmpty()) {

        addNode = new Node(data);
        head = addNode;
        tail = addNode;

        return;
    }

    Node * current = head;

    while (current != NULL) {

        if (current->getData().getOgrenciNo() <= data->getOgrenciNo()) {
            current = current->getNext();
        }

        else {

            if (current == head) {

                addNode = new Node(data, head, NULL);
                head->setPrev(addNode);
                head = head->getPrev();
            }

            else {

                addNode = new Node(data, current, current->getPrev());
                current->getPrev()->setNext(addNode);
                current->setPrev(addNode);
            }

            return;
        }
    }

    addNode = new Node(data, NULL, tail);
    tail->setNext(addNode);
    tail = tail->getNext();
}

void DoublyLinkedList::searchOgrenciAdSoyad(string ogrenciAdSoyad) {

    if (isEmpty()) {
        cout << "\nStudent list is empty!\n";
        return;
    }

    Node * current = head;
    int count = 0;

    while (current != NULL) {

        if (ogrenciAdSoyad.compare(current->getData().getOgrenciAdSoyad()) == 0) {
            cout << "\nStudent " << count+1 << ": " << endl;
            cout << "------------" << endl;

            Student printStudent = current->getData();
            cout << printStudent;

            count++;
        }

        current = current->getNext();
    }

    if (count == 0)
        cout << "\nCould not find student!\n";

    else {
        cout << "***********************" << endl;
        cout << "Number of " << ogrenciAdSoyad << " student(s): " << count << endl;
        cout << "***********************" << endl;
    }
}

void DoublyLinkedList::deleteStudent(int ogrenciNo) {

    if (isEmpty()) {
        cout << "\nStudent list is empty!\n";
        return;
    }

    Node * current = head;

    while (current != NULL) {

        if (ogrenciNo == current->getData().getOgrenciNo()) {
            break;
        }

        current = current->getNext();
    }

    if (current == NULL) {
        cout << "\nCould not find student!\n";
        return;
    }

    else if (current == head && current == tail) {
        head = NULL;
        tail = NULL;
        current = NULL;

        cout << "\nStudent deleted successfully!\n";
        return;
    }

    else if (current == head) {
        head->getNext()->setPrev(NULL);
        head = head->getNext();
    }

    else if (current == tail) {
        tail->getPrev()->setNext(NULL);
        tail = tail->getPrev();
    }

    else {
        current->getNext()->setPrev(current->getPrev());
        current->getPrev()->setNext(current->getNext());
    }

    current->setNext(NULL);
    current->setPrev(NULL);
    current = NULL;

    cout << "\nStudent deleted successfully!\n";
}

void DoublyLinkedList::printStudents() {

    int count = 0;

    if (isEmpty()) {
        cout << "\nStudent list is empty!\n";
        return;
    }

    Node * current = head;

    while (current != NULL) {
        cout << "\nStudent " << count+1 << ": " << endl;
        cout << "------------" << endl;

        Student printStudent = current->getData();
        cout << printStudent;

        current = current->getNext();

        count++;
    }

    cout << "***********************" << endl;
    cout << "Number of students: " << count << endl;
    cout << "***********************" << endl;
}

void DoublyLinkedList::reversePrintStudents() {

    int count = 0;

    if (isEmpty()) {
        cout << "\nStudent list is empty!\n";
        return;
    }

    Node * current = tail;

    while (current != NULL) {
        cout << "\nStudent " << count+1 << ": " << endl;
        cout << "------------" << endl;

        Student printStudent = current->getData();
        cout << printStudent;

        current = current->getPrev();

        count++;
    }

    cout << "***********************" << endl;
    cout << "Number of students: " << count << endl;
    cout << "***********************" << endl;
}
