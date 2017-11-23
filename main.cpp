#include <iostream>
#include "include/Student.h"
#include "include/StudentAVTF.h"
#include "include/StudentFPMI.h"
#include "include/ListS.h"

using namespace std;

int main()
{
    Student student("student1", -18, 0);
    cout << endl;
    ifstream input("out.txt");
    input >> student;
    input.close();
    cout << endl;
    ifstream output_bin("out.bin", std::ios_base::binary);
    student.read(output_bin);
    output_bin.close();
    return 0;
}
