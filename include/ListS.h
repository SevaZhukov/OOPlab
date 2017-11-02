//
// Created by Севастьян on 02.11.2017.
//

#ifndef CPROJ_LISTS_H
#define CPROJ_LISTS_H

#include <iostream>
#include "Student.h"

using namespace std;

class ListS {

    class elem {
    public:
        elem(Student d);

        Student field; // поле данных
        elem *next; // указатель на следующий элемент
        elem *prev; // указатель на предыдущий элемент

    };
    elem *lstart, *lend;
public:
    ListS();

    ~ListS();
    void add(Student d);
    void clear();
    void print();
    void delbynumber(int number = 0);
    void addbynumber(int number, Student d);
    void findbyname(const char name[]);
    void findbydescription(const char name[]);
};


#endif //CPROJ_LISTS_H
