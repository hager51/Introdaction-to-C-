#include <iostream>
#include<string.h>

using namespace std;

class Person
{
protected:
    int Id;
    char Name[50];

public:
    Person()
    {
        Id = 0;
        strcpy(Name, " ");
    }

    Person(int id)
    {
        Id = id;
        strcpy(Name, " ");
    }

    Person(int id , char p[])
    {
        Id = id;
        strcpy(Name, p);
    }

    void SetId(int id) {Id = id;}
    void SetName(char p[]) {strcpy(Name, p);}

    int GetId() {return Id;}
    char* GetName() {return Name;}

    void Print()
    {
        cout<<"Id = "<<Id<<endl;
        cout<<"Name = "<<Name<<endl;
    }
};

class Employee : public Person
{
private:
    int Salary;

public:
    Employee() {Salary = 0;}

    Employee(int id , char n[] , int s) : Person(id,n)
    {
        Salary = s;
    }

    void SetSalary(int S) {Salary = S;}

    int GetSalary() {return Salary;}

    void Print()
    {
        cout<<"Salary = "<<Salary<<endl;
    }
};

class Customer : public Person
{
private:
    int Contact;

public:
    Customer() {Contact = 0;}

    Customer(int id , char n[] , int c) : Person(id,n)
    {
        Contact = c;
    }

    void SetContact(int C) {Contact = C;}

    int GetContact() {return Contact;}

    void Print()
    {
        cout<<"Contact = "<<Contact<<endl;
    }
};

int main()
{
    Employee Emp(1, "Mohamed Ali", 1000);
    cout << Emp.GetName() << endl;
    Emp.Print();
    return 0;
}
