#include "Node.h"

class DoublyLinkedList {

private:
    Node * head = NULL;
    Node * tail = NULL;

public:
    bool isEmpty();

    void addSortByOgrenciNo(Student *data);
    void searchOgrenciAdSoyad(string ogrenciAdSoyad);
    void deleteStudent(int ogrenciNo);
    void printStudents();
    void reversePrintStudents();
};
