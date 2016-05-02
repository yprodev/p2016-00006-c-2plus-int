#include <iostream>

using namespace std;

#include "EmployeeOverview.h"

int main()
{
    Employee worker;

    worker.SetName("Simon");
    worker.SetEmpNo(12345);
    worker.SetExtension(9999);

    cout << worker.GetName() << " " << worker.GetEmpNo() << " " << worker.GetExtension() << endl;


    return 0;
}
