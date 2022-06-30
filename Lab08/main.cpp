#include <iostream>
#include<string.h>

using namespace std;

class Employee
{
private:
    int Id;
    int Salary;
    char* Name;
    int Size;

public:
    void SetId(int i);
    void SetName(char arr[]);
    void SetSalary(int s);

    int GetId();
    char* GetName();
    int GetSalary();

    Employee();
    Employee(int i);
    Employee(int i , char n[]);
    Employee(int i , char n[] , int j);
    Employee(Employee& re); //Copy Constructor

    Employee operator+(int S);
    Employee operator++();
    Employee operator++(int t);
    int operator==(Employee E);
    Employee& operator=(Employee E);

    friend Employee operator+(int x, Employee& E);

   ~Employee ()
    {
        //cout << "\nobject is destroyed" << endl;
        delete(Name);
    }
};

void Employee :: SetId(int i)
{
    Id = i;
}

void Employee :: SetName(char arr[])
{
    delete(Name);
    Size = strlen(arr);
    Name = new char[Size+1];
    strcpy(Name, arr);
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

Employee :: Employee()
    {
        Id = Salary = 0;
        Size = 20;
        Name = new char [Size+1];
        strcpy(Name," ");
        cout<<"Default"<<endl;
    }

Employee :: Employee(int i)
    {
        Id = i;
        Salary = 0;
        Size = 20;
        Name = new char [Size+1];
        strcpy(Name," ");
        cout<<"Constructor 1"<<endl;
    }

Employee :: Employee(int i , char n[])
    {
        Id = i;
        Salary = 0;
        Size = strlen(n);
        Name = new char [Size+1];
        strcpy(this->Name,n);
        cout<<"Constructor 2"<<endl;
    }

Employee :: Employee(int i , char n[] , int j)
    {
        Id = i;
        Salary = j;
        Size = strlen(n);
        Name = new char [Size+1];
        strcpy(this->Name,n);
        cout<<"Constructor 3"<<endl;
    }

Employee :: Employee(Employee& re)
{
    Id = re.Id;
    Salary = re.Salary;
    Size = re.Size;
    Name = new char[Size+1];
    strcpy(Name,re.Name);
}

Employee Employee :: operator+(int S)
{
    Employee temp;
    Salary = Salary+S;
    return temp;
}
Employee Employee :: operator++()
{
    Id++;
    return *this;
}
Employee Employee :: operator++(int t)
{
    Employee temp = *this;
    Id++;
    return temp;
}
int Employee :: operator==(Employee E)
{
    return (Id == E.Id);
}
Employee &Employee :: operator=(Employee E)
{
    Id = E.Id;
    Salary = E.Salary;
    Size = E.Size;
    Name = new char [Size+1];
    strcpy(Name,E.Name);
    return *this;
}

Employee operator+(int x, Employee& E)
{
    E.Salary += x;
    return E;
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

    Emp1 + 1000 ;
    cout<<"\nAfter increase salary using (Employee + Integer) form : " << Emp1.GetSalary() << endl;

    1200 + Emp3;
    cout<<"\nAfter increase salary using (Integer + Employee) form : " << Emp3.GetSalary() << endl;

    ++Emp1;
    cout<<"\nAfter prefix increment operation the value of Id : " << Emp1.GetId() << endl;

    Emp1++;
    cout<<"\nAfter postfix increment operation the value of Id : " << Emp1.GetId() << endl;

    if (Emp1 == Emp) {cout << "\nIds is equal" << endl;}
    else {cout << "\nIds isn't equal" << endl;}

    Emp4 = Emp3;
    cout << "\nAfter using equal operator : "<< Emp4.GetName() << endl;

    return 0;
}
