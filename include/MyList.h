//
// Created by Севастьян on 23.11.2017.
//

#ifndef CPROJ_MYLIST_H
#define CPROJ_MYLIST_H

#include <iostream>
using namespace std;

template <class Data, int kol=0> class MyList {
    class elem
    {
    public:
        Data d;
        elem *next;
        elem *prev;
        elem(Data dat = 0){
            d = dat;
            next = prev = 0;
        }
    };
    elem *lstart, *lend;
public:
    MyList(){
        lstart = lend = 0;
    }

    virtual ~MyList() {
        elem *pv;
        while (lstart != lend)
        {
            pv = lstart;
            lstart = pv->next;
            delete pv;
        }
        delete lstart;
    }

    void add(Data d) {
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

    void addByNumber(int number, Data d){
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
    void delByNumber(int number) {
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
    Data get(int num){
        int rnum=1;
        elem *pv;
        pv = lstart;

        if (lend == 0)
        {
            cout<<"Spisok pust"<<endl;
        }
        else
        {
            pv=pv->next;
            if(num==1){
                return pv->d;
            }
            if(num==0){
                return pv->prev->d;
            }
            while (pv != lstart)
            {
                if(rnum == num){
                    return pv->d;
                }
                pv = pv->next;
                rnum++;
            }
        }
    }
    void print() {
        elem *pv;
        pv = lstart;
        if (lend == 0)
        {
            cout<<"Spisok pust"<<endl;
        }
        else
        {
            cout << pv->d << " ";
            pv=pv->next;
            while (pv != lstart)
            {
                cout << pv->d << " ";
                pv = pv->next;
            }
        }
    }
};


#endif //CPROJ_MYLIST_H
