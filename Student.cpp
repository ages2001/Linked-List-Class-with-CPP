#include "Student.h"

int Student::getOgrenciNo() {
    return this->ogrenciNo;
}

void Student::setOgrenciNo(int ogrenciNo) {
    this->ogrenciNo = ogrenciNo;
}

string Student::getOgrenciAdSoyad() {
    return this->ogrenciAdSoyad;
}

void Student::setOgrenciAdSoyad(string ogrenciAdSoyad) {
    this->ogrenciAdSoyad = ogrenciAdSoyad;
}

string Student::getOgrenciTelNo() {
    string telNos = "";

    for (string telNo : ogrenciTelNo) {
        telNos.append(telNo);
        telNos.append("\n");
    }

    return telNos;
}

void Student::setOgrenciTelNo(vector<string> ogrenciTelNo) {
    this->ogrenciTelNo = ogrenciTelNo;
}

void Student::addTelNo(string telNo) {
    this->ogrenciTelNo.emplace_back(telNo);
}

Student::Student() {
    setOgrenciNo(NULL);
    setOgrenciAdSoyad("");
}

Student::Student(int ogrenciNo, string ogrenciAdSoyad) {
    setOgrenciNo(ogrenciNo);
    setOgrenciAdSoyad(ogrenciAdSoyad);
}

Student::Student(Student *copyStudent) {
    vector<string> copyOgrenciTelNo;

    for (string telNo : this->ogrenciTelNo)
        copyOgrenciTelNo.emplace_back(telNo);

    setOgrenciNo(copyStudent->getOgrenciNo());
    setOgrenciAdSoyad(copyStudent->getOgrenciAdSoyad());
    setOgrenciTelNo(copyOgrenciTelNo);
}

ostream & operator << (ostream &out, Student &student)
{
    out << "\nOgrenci No: " << student.getOgrenciNo() << "\nOgrenci Ad Soyad: " << student.getOgrenciAdSoyad() << "\nOgrenci Telefon No(lar): \n" << student.getOgrenciTelNo() << endl;
    return out;
}
