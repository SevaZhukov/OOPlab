#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
using namespace std;
class Student
{
public:
    Student(char* v, int Age, float MidPoint);
    Student();
    Student(const Student &student);
    ~Student();
    void Print();
    void EditAll();
    Student operator + (Student student);
    Student operator = (Student student);
    Student operator ++ (int);//post
    Student& operator ++ ();//pre
    friend ostream& operator << (ostream& os, Student &student);
    friend istream& operator >> (istream& is, Student &student);
    void write(ofstream &os);
    void read(ifstream &is);
    operator int() const;
    friend Student operator - (Student first, Student second);

    char* name;
    int age;
    float midPoint;

    const char *getName();
};

#endif // STUDENT_H
