#ifndef STUDENTAVTF_H
#define STUDENTAVTF_H

#include "Student.h"
class StudentAVTF: public Student
{
public:
    StudentAVTF();
    void Print();
    StudentAVTF(const StudentAVTF &student);
    StudentAVTF(char* v, int Age, float MidPoint, int hours);
protected:

private:
    int hoursOfProg;
};

#endif // STUDENTAVTF_H
