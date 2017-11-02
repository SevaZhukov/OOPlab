#include "../include/StudentFPMI.h"
#include <string.h>
#include <cstring>
using namespace std;
StudentFPMI::StudentFPMI():Student()
{
    hoursOfMatan=0;
}

void StudentFPMI::Print()
{
    cout << hoursOfMatan << " ";
    Student::Print();
}
StudentFPMI::StudentFPMI(const StudentFPMI &student):Student(student)
{
    hoursOfMatan=student.hoursOfMatan;
}
StudentFPMI::StudentFPMI(char* v, int Age, float MidPoint, int hours):Student(v, Age, MidPoint)
{
    hoursOfMatan=hours;
}

