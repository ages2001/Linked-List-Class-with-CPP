#include "Student.h"
#include "DoublyLinkedList.h"

int main() {
    cout << "\nWelcome to the program!\n";
    cout << "Please choose operation: \n\n";
    cout << "1 - Add student from file\n";
    cout << "2 - Add student by entering informations\n";
    cout << "3 - Find student by student name and surname\n";
    cout << "4 - Delete student by student number\n";
    cout << "5 - List students by sort\n";
    cout << "6 - List students by reverse sort\n";
    cout << "7 - Exit\n";

    int operation;

    DoublyLinkedList *studentList = new DoublyLinkedList();

    while (true) {

        cout << "\nChoose (1-7): ";
        cin >> operation;

        switch (operation) {

            case 1: {
                ifstream file;

                file.open("/home/ages2001/Documents/ogrenciler.txt");

                if (!file) {
                    cout << "\nCould not find file or file is damaged/corrupted!\n";
                    break;
                }

                int ogrNo;
                string str, ogrAdSoyad;
                Student *student;

                getline(file, str, ',');

                do{

                    ogrNo = stoi(str);

                    getline(file, str, ',');

                    ogrAdSoyad = str;

                    student = new Student(ogrNo, ogrAdSoyad);

                    getline(file, str);

                    char cstr[250], *ptr;
                    strcpy(cstr, str.c_str());

                    ptr = strtok(cstr, ",");

                    while (ptr != NULL) {
                        student->addTelNo(ptr);
                        ptr = strtok(NULL, ",");
                    }

                    studentList->addSortByOgrenciNo(student);

                    getline(file, str, ',');

                } while (str != "");

                cout << "\nFile read and studens added to list succesfully!" << endl;
                file.close();

                break;
            }

            case 2: {
                int ogrNo;
                string ogrAdSoyad, ogrTelNo;

                cout << "\nEnter student's number to add student: ";
                cin >> ogrNo;

                cout << "Enter student name-surname: ";
                cin.ignore();
                getline(cin, ogrAdSoyad);

                cout << "Enter student's phone number(s) (if more than one, please delimit with ','): ";
                cin.ignore();
                getline(cin, ogrTelNo);

                Student *student = new Student(ogrNo, ogrAdSoyad);

                char str[250], *ptr;
                strcpy(str, ogrTelNo.c_str());

                ptr = strtok(str, ", ");

                while (ptr != NULL) {
                    student->addTelNo(ptr);
                    ptr = strtok(NULL, ", ");
                }

                studentList->addSortByOgrenciNo(student);

                break;
            }

            case 3: {
                string ogrAdSoyad;

                cout << "Enter student's name-surname to search student in list: ";
                cin.ignore();
                getline(cin, ogrAdSoyad);

                studentList->searchOgrenciAdSoyad(ogrAdSoyad);
                break;
            }

            case 4: {
                int ogrNo;

                cout << "Enter student's number to delete student from list: ";
                cin >> ogrNo;

                studentList->deleteStudent(ogrNo);
                break;
            }

            case 5: {
                studentList->printStudents();
                break;
            }

            case 6: {
                studentList->reversePrintStudents();
                break;
            }

            case 7: {
                cout << "\nThanks for using program!\n";
                cout << "Terminating program...\n";
                return 0;
            }

            default: {
                cout << "\nPlease enter a valid operation!\n";
            }
        }
    }
}
