#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#pragma once

using namespace std;

class Student {

private:
    int ogrenciNo;
    string ogrenciAdSoyad;
    vector<string> ogrenciTelNo;

public:
    int getOgrenciNo();
    void setOgrenciNo(int ogrenciNo);

    string getOgrenciAdSoyad();
    void setOgrenciAdSoyad(string ogrenciAdSoyad);

    string getOgrenciTelNo();
    void setOgrenciTelNo(vector<string> ogrenciTelNo);

    void addTelNo(string telNo);

    Student();
    Student(int ogrenciNo, string ogrenciAdSoyad);
    Student(Student *copyStudent);

    void toString();

    friend ostream & operator << (ostream &out, Student &student);

};
