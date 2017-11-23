#include <iostream>
#include "include/Student.h"
#include "include/StudentAVTF.h"
#include "include/StudentFPMI.h"
#include "include/ListS.h"
#include "include/MyList.h"

using namespace std;

int main()
{
    //lab6
    /*Student student("student1", -18, 0);
    cout << endl;
    ifstream input("out.txt");
    input >> student;
    input.close();
    cout << endl;
    ifstream output_bin("out.bin", std::ios_base::binary);
    student.read(output_bin);
    output_bin.close();*/

    MyList<string> myList;
    myList.add("lol");
    myList.add("kek");
    myList.add("qwe");
    myList.print();
    cout << endl;
    myList.addByNumber(1, "insert");
    myList.print();
    cout << endl;
    myList.delByNumber(2);
    myList.print();
    cout << endl;
    string str = myList.get(2);
    cout << str;
    return 0;
}
