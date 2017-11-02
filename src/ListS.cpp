//
// Created by Севастьян on 02.11.2017.
//

#include <cstring>
#include "../include/ListS.h"

ListS::elem::elem(Student d){
    next = prev = NULL;
    field = d;
}

ListS::ListS() {
    lstart=lend=NULL;
}

ListS::~ListS() {
    elem *pv;
    while (lstart != lend)
    {
        pv = lstart;
        lstart = pv->next;
        delete pv;
    }
    delete lstart;
}

void ListS::add(Student d) {
    elem *pv = new elem(d);

    if(lstart == NULL)
    {
        lstart = lend = pv;
        pv->next=pv;
        pv->prev=pv;
    }
    else
    {
        pv->prev = lend;
        pv->prev->next=pv;
        pv->next = lstart;
        lend = pv;
    }
}

void ListS::clear() {
    if (lstart == lend)
    {
        lend = lstart = 0;
    }
    else
    {
        lend->prev->next = lstart;
        lend = lend->prev;
    }
}

void ListS::print() {
    elem *pv;
    pv = lstart;
    if (lend == 0)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        pv->field.Print();
        pv=pv->next;
        while (pv != lstart)
        {
            pv->field.Print();
            pv = pv->next;
        }
    }
}

void ListS::delbynumber(int number) {
    elem *pv = lstart;
    if (lstart == lend)
    {
        lend = lstart = 0;
    }
    else
    {
        for (int i = 0; i!=number; i++)
        {
            pv = pv->next;
        }
        if (pv == lstart)
        {
            lstart = pv->next;
            pv->prev->next = pv->next;
            pv->next->prev = pv->prev;
            lend->next = lstart;
            delete pv;
        }
        else
        {
            pv->prev->next = pv->next;
            pv->next->prev = pv->prev;
            delete pv;
        }
    }
}

void ListS::addbynumber(int number, Student d) {
    elem *pv = new elem(d);
    elem *old = lstart;

    for (int i = 0; i!=number; i++)
    {
        old = old->next;
    }
    if (old == lstart)
    {
        lstart = pv;
        pv->next = old;
        pv->prev = lend;
        old->prev = pv;
        lend->next = pv;
    }
    else
    {
        pv->prev = old->prev;
        pv->next = old;
        old->prev->next = pv;
        old->prev = pv;
    }
}

void ListS::findbyname(const char *name) {
    elem *pv = lstart;
    bool check = 0;
    if (!strcmp(name,pv->field.getName()))
    {
        pv->field.Print();
        check = 1;
    }
    pv=pv->next;

    while (pv != lstart)
    {
        if (!strcmp(name,pv->field.getName() ))
        {
            pv->field.Print();
            check = 1;
        }
        pv=pv->next;
    }
    if (!check)
    {
        cout<<"Nothing found"<<endl;
    }
}

