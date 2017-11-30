#include <iostream>
#include <list>
#include "include/Student.h"
#include "include/StudentAVTF.h"
#include "include/StudentFPMI.h"
#include "include/ListS.h"
#include "include/MyList.h"
#include "queue"
#include <ctime>
#include <utility>
#include <cstdlib>
#include <set>
#include <ctime>
using namespace std;

char * randomString (int sybols = 3) {
    char *str;
    str = new char [sybols+1];
    for (int i = 0; i < sybols; i++)
    {
        str [i]  = static_cast<char>(97 + rand() % 10);
    }
    str[sybols] = '\0';
    return str;
}

set<int>::iterator find_int(set <int> &a, int value) {
    set<int>::iterator it;
    it = a.begin();
    for (it; it!=a.end(); it++)
    {
        if (*it == value)
        {
            cout<<"Found "<<value<<" in set<int> on place:"<<it._M_node<<endl;
            return it;
        }
    }
    cout<<"Not found "<<value<<" in set<int>"<<endl;
}

set<Student>::iterator find_studentset (set <Student> &a, int age = -1, float midp = -1) {
    set<Student>::iterator it;
    it = a.begin();
    for (it; it != a.end(); it++)
    {
        if (it->age == age && it->midPoint == midp)
        {
            cout<<"Found age: "<<age<<" and num_page: "<<midp<<" in set<Student> on place:"<<it._M_node<<endl;
            return it;
        }
        if (age == -1 && it->midPoint == midp)
        {
            cout<<"Found midpoint: "<<midp<<" in set<Student> on place:"<<it._M_node<<endl;
            return it;
        }
        if (midp == -1 && it->age == age)
        {
            cout<<"Found age: "<<age<<" in set<Student> on place:"<<it._M_node<<endl;
            return it;
        }
    }
    cout<<"Nothing found in set<Student>"<<endl;
}

typedef queue <int, list<int>> queint;
typedef queue <Student, list<Student>> quest;
typedef set<int, less<int> > setint;
typedef set<Student, less<Student>> setst;
int main()
{
    //queue<Student> qs;
    srand(static_cast<unsigned int>(time(NULL)));
    unsigned int timer_begin=0;

    cout << "For int" << endl;

    queint qi;

    //запись в queue
    timer_begin = static_cast<unsigned int>(clock());
    for(int i=0; i<500000; i++) {
        qi.push(rand()%100);
    }
    cout << "Write in queue: " << clock()-timer_begin << " ms"<<endl;

    //поиск в queue
    timer_begin = static_cast<unsigned int>(clock());
    int a=5;
    for(int i=0; i<qi.size(); i++){
        qi.pop();
        if(a==qi.front()){
            cout << "Find at " << i << endl;
            break;
        }
    }
    cout <<  "Search in queue: " <<clock()-timer_begin << " ms"<<endl;

    //удаление queue
    timer_begin = static_cast<unsigned int>(clock());
    for(int i=0; i<qi.size(); i++){
        qi.pop();
    }
    cout <<  "Delete queue: " << clock()-timer_begin <<" ms"<<endl;

    setint seti;

    //запись в set
    timer_begin = static_cast<unsigned int>(clock());
    for(int i=0; i<500000; i++) {
        seti.insert(rand()%100);
    }
    cout <<  "Write in set: " << clock()-timer_begin <<" ms"<<endl;

    //поиск в set
    timer_begin = static_cast<unsigned int>(clock());
    find_int(seti, 50);
    cout << "Search in set: " << clock()-timer_begin << " ms"<<endl;

    //удаление set
    timer_begin = static_cast<unsigned int>(clock());
    seti.clear();
    cout << "Clear set: " << clock()-timer_begin << " ms"<<endl;

    cout << "For Student" << endl;

    quest qs;

    //запись в queue
    timer_begin = static_cast<unsigned int>(clock());
    for(int i=0; i<500000; i++) {
        float f = rand()%100;
        Student student(randomString(), rand()%100, f);
        qs.push(student);
    }
    cout << "Write in queue: " << clock()-timer_begin << " ms"<<endl;
    /*

    //поиск в queue
    int age = 45;
    timer_begin = static_cast<unsigned int>(clock());
    for(int i=0; i<qs.size(); i++){
        qs.pop();
        if(age==qs.front().age){
            cout << "Find at " << i << endl;
            break;
        }
    }
    cout <<  "Search in queue: " <<clock()-timer_begin << " ms"<<endl;

    //удаление queue
    timer_begin = static_cast<unsigned int>(clock());
    for(int i=0; i<qs.size(); i++){
        qs.pop();
    }
    cout <<  "Delete queue: " << clock()-timer_begin <<" ms"<<endl;

    setst sets;

    //запись в set
    timer_begin = static_cast<unsigned int>(clock());
    for(int i=0; i<500000; i++) {
        Student student(randomString(), rand()%100, rand()%100);
        sets.insert(student);
    }
    cout <<  "Write in set: " << clock()-timer_begin <<" ms"<<endl;

    //поиск в set
    timer_begin = static_cast<unsigned int>(clock());
    find_studentset(sets, 50, 99);
    cout << "Search in set: " << clock()-timer_begin << " ms"<<endl;

    //удаление set
    timer_begin = static_cast<unsigned int>(clock());
    sets.clear();
    cout << "Clear set: " << clock()-timer_begin << " ms"<<endl;*/
    return 0;
}
