#include "../include/StudentAVTF.h"
#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
StudentAVTF::StudentAVTF():Student()
{
    hoursOfProg=0;
}

void StudentAVTF::Print()
{
    cout << hoursOfProg << " ";
    Student::Print();
}
StudentAVTF::StudentAVTF(const StudentAVTF &student):Student(student)
{
    hoursOfProg=student.hoursOfProg;
}
StudentAVTF::StudentAVTF(char* v, int Age, float MidPoint, int hours):Student(v, Age, MidPoint)
{
    hoursOfProg=hours;
}
