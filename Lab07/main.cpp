#include <iostream>
#include<string.h>

using namespace std;

class Employee
{
private:
    int Id;
    char Name[21];
    int Salary;

public:
    void SetId(int i);
    void SetName(char arr[21]);
    void SetSalary(int s);

    int GetId();
    char* GetName();
    int GetSalary();

    Employee()
    {
        Id = Salary = 0;
        strcpy(Name," ");
        cout<<"Default"<<endl;
    }

    Employee(int i)
    {
        Id = Salary = i;
        strcpy(Name," ");
        cout<<"Constructor 1"<<endl;
    }

    Employee(int i , char* a)
    {
        Id = Salary = i;
        strcpy(Name,a);
        cout<<"Constructor 2"<<endl;
    }

    Employee(int i , char* a , int j)
    {
        Id = i;
        strcpy(Name,a);
        Salary = j;
        cout<<"Constructor 3"<<endl;
    }

    ~Employee ()
    {
        cout << "object is destroyed" << endl;
    }
};

void Employee :: SetId(int i)
{
    Id = i;
}

void Employee :: SetName(char arr[21])
{
    for (int i=0 ; i<21; i++)
        {
            Name[i] = arr[i];
        }
}

void Employee :: SetSalary(int s)
{
    Salary = s;
}

int Employee :: GetId()
{
    return Id;
}
char* Employee :: GetName()
{
    return Name;
}
int Employee :: GetSalary()
{
    return Salary;
}

int main()
{
    Employee Emp1, Emp(1), Emp3(2, "Mohamed Ali"), Emp4(3, "Ahmed", 1500);

    cout << "First Constructor : \n" ;
    cout << "Employee id : "<< Emp1.GetId() << "\nEmployee Name : " << Emp1.GetName() << "\nEmployee Salary : " << Emp1.GetSalary() << endl;

    cout << "\nSecond Constructor : \n" ;
    cout << "Employee id : "<< Emp.GetId() << "\nEmployee Name : " << Emp.GetName() << "\nEmployee Salary : " << Emp.GetSalary() << endl;

    cout << "\nThird Constructor : \n" ;
    cout << "Employee id : "<< Emp3.GetId() << "\nEmployee Name : " << Emp3.GetName() << "\nEmployee Salary : " << Emp3.GetSalary() << endl;

    cout << "\nFourth Constructor : \n" ;
    cout << "Employee id : "<< Emp4.GetId() << "\nEmployee Name : " << Emp4.GetName() << "\nEmployee Salary : " << Emp4.GetSalary() << endl;

    Emp1.SetId(1);
    Emp1.SetName("Mohamed Ali");

    cout << "\nGetter" << endl;
    cout << Emp1.GetId() << endl;
    cout << Emp1.GetName() << endl;

    return 0;
}
