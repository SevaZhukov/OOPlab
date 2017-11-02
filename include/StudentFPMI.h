#ifndef STUDENTFPMI_H
#define STUDENTFPMI_H

#include "Student.h"
class StudentFPMI: public Student
{
public:
    StudentFPMI();
    void Print();
    StudentFPMI(char* v, int Age, float MidPoint, int hours);
    StudentFPMI(const StudentFPMI &student);
protected:

private:
    int hoursOfMatan;
};

#endif // STUDENTFPMI_H
