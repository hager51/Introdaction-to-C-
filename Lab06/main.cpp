#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // for gotoXY function
COORD CursorPosition; // for gotoXY function

void gotoXY(int,int);

struct Student
{
    int Id;
    char Name[50];
    int SubNum[5];
};

Student FillStudent ();
void PrintStudents(Student);
void PrintOneStudent(Student , int , int);

int main()
{
    int Size , flag = 1 , Location = 0 , Num = 0;
    cout << "Enter Number of Students , please : ";
    cin >> Size;

    Student* PStu;
    PStu = new Student[Size];

	while(flag)
	{
	    gotoXY(48,5);
        cout << "Main Menu";

        gotoXY(50,7);  cout << "1) Add";
		gotoXY(50,8);  cout << "2) Display";
		gotoXY(50,9);  cout << "3) Display All";
		gotoXY(50,10); cout << "4) Exit";

		switch(getch()){
		    case 49: {
		        gotoXY(0,13);
                system ("CLS");
		        cout << "Add info. of student no." << Location+1 << " : \n";
		        if (Location < Size)
                {
                    PStu[Location] = FillStudent();
                    Location++;
                }
                else
                {
                    cout << "Sorry, You are overstepping your bounds. \n";
                }
                break;
            }

            case 50: {
                gotoXY(0,13);
                system ("CLS");
                cout << "Enter number of student you search for : ";
                cin >> Num;
                PrintOneStudent(PStu[Num-1] , Location , Num);
                break;
            }

            case 51: {
                gotoXY(0,13);
                system ("CLS");
                for (int i=0 ; i<Size ; i++)
                {
                    PrintStudents(PStu[i]);
                }
                break;
            }

            case 52: {
                gotoXY(20,13);
                system ("CLS");
                cout << "You terminate the program .";
                flag = 0;
            }

        }

    }

    return 0;
}

Student FillStudent ()
{
    Student S;
    cout << "Enter Student id : ";
    cin >> S.Id;

    cout << "Enter Student name : ";
    cin >> S.Name;

    for (int i=0 ; i<5 ; i++)
    {
        cout << "Enter student's grade in subject no." << i+1 << ": " ;
        cin >> S.SubNum[i];
    }

    return S;
}

void PrintStudents(Student S)
{
    float Sum = 0.0;
    cout << "ID : " << S.Id << endl;
    cout << "Name : " << S.Name << endl;
    cout << "Grades : " ;
    for (int i=0 ; i < 5 ; i++){
        cout << S.SubNum[i] << " ";
        Sum += S.SubNum[i];
    }
    cout << "\nTotal = " << Sum << endl << endl;
}

void PrintOneStudent(Student S , int Location , int Num)
{
    if (Num < Location)
        {
            cout << "Founded ... \n";
            PrintStudents(S);
        }
}

void gotoXY( int column, int line )
{
	CursorPosition.X = column;
	CursorPosition.Y = line;
	SetConsoleCursorPosition(console,CursorPosition);
}
