#include <iostream>
#include "include/Student.h"
#include "include/StudentAVTF.h"
#include "include/StudentFPMI.h"
#include "include/ListS.h"

using namespace std;

int main()
{
    /*StudentAVTF stpi("qqq", 1, 3, 1);
    StudentAVTF st(stpi);
    Student *p;
    p = new StudentAVTF(st);
    p->Print();
    //st.Print();

    cout << endl;
    StudentFPMI stpmi("www", 2, 4, 5);
    stpmi.Print();*/
    Student student("student1", 18, 4.5);
    StudentAVTF studentAVTF("student2", 19, 3.5, 24);
    StudentFPMI studentFPMI("student3", 20, 3.0, 12);
    //Объявление списка
    ListS listS;
    //Добавляем элементы
    listS.add(student);
    listS.add(studentAVTF);
    listS.add(studentFPMI);
    listS.add(studentAVTF);
    //Вывод
    listS.print();
    cout << endl;
    //Удаление по номеру
    listS.delbynumber(0);
    listS.print();
    cout << endl;
    //Вставка по номеру
    listS.addbynumber(1, student);
    listS.print();
    cout << endl;
    listS.findbyname("student2");
    cout << endl;
    listS.clear();
    listS.clear();
    listS.print();
    return 0;
}
