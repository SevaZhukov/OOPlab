#include "../include/Student.h"
#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
Student::Student(char* v, int Age, float MidPoint)
{
    name = new char[strlen(v)+1];
    strcpy(name, v);
    age=Age;
    midPoint=MidPoint;
}
Student::Student()
{
    name = NULL;
    age=0;
    midPoint=0;
}
Student::Student(const Student &student)
{
    name = new char[strlen(student.name)+1];
    strcpy(name, student.name);
    age=student.age;
    midPoint=student.midPoint;
}
void Student::EditAll()
{
    char *v;
    v = new char[100];
    int Age;
    float MidPoint;
    cin >> v >> Age >> MidPoint;
    name = new char[strlen(v)+1];
    strcpy(name, v);
    delete v;
    age=Age;
    midPoint=MidPoint;

}
void Student::Print()
{
    if(name!=NULL)
    {
        cout << name << " ";
    }
    cout <<age << " " << midPoint << endl;

}
Student Student::operator+(Student student)
{
    //cout << age << " " << student.age;
    Student newStudent("1", 2, 3);
    delete [] newStudent.name;
    newStudent.name = new char[strlen(student.name)+1];
    //name = new char[strlen(student.name)+1];
    strcpy(newStudent.name, student.name);
    newStudent.age=this->age+student.age;
    newStudent.midPoint=this->midPoint+student.midPoint;
    return newStudent;
}
Student operator - (Student first, Student second)
{
    Student newStudent("111", 2, 3);
    strcpy(newStudent.name, first.name);
    newStudent.age=first.age-second.age;
    newStudent.midPoint=first.midPoint-second.midPoint;
    return newStudent;
}
Student Student::operator=(Student student)
{
    if(&student == this) return *this;
    if(name) delete [] name;
    if(student.name)
    {
        name = new char[strlen(student.name)+1];
        strcpy(name,student.name);
    }
    age=student.age;
    midPoint=student.midPoint;
    return *this;
}
Student Student::operator++(int)
{
    Student newst(*this);
    this->age++;
    this->midPoint++;
    return newst;
}
Student& Student::operator++()
{
    this->age++;
    this->midPoint++;
    return *this;
}
Student:: operator int() const
{
    return(int) midPoint;
}
ostream& operator << (ostream& os, Student &student)
{
    os << student.name<<" "<<student.age<<" "<<student.midPoint;
    return os;

}
istream& operator >> (istream& is, Student &student)
{
    is >>student.name>>student.age>>student.midPoint;
    return is;
}
void Student::write(ofstream &os)
{
    os.write(name, strlen(name) + 1);
    os.write(reinterpret_cast<char *>(&age), sizeof(age));
    os.write(reinterpret_cast<char *>(&midPoint), sizeof(midPoint));
}

void Student::read(ifstream &is)
{
    char ch;
    int i=0;
    streampos s = is.tellg();//текущая поззиция get в потоке
    while ((ch = is.get()) !='\0')
    {
        i++;
    }
    is.seekg(s);//перемещаем указатель ввода
    if (name != '\0')
    {
        delete[] name;
    }
    name = new char[i + 1];
    is.read(name, i + 1);
    is.read(reinterpret_cast<char *>(&age), sizeof(age));
    is.read(reinterpret_cast<char *>(&midPoint), sizeof(midPoint));
}

Student::~Student()
{
    delete name;
}

const char *Student::getName() {
    return name;
}
