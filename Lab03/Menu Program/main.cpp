#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // for gotoXY function
COORD CursorPosition; // for gotoXY function

void gotoXY(int,int);
int ADD(int,int);
int SUB(int,int);
int MUL(int,int);
float DIV(int,int);

int main()
{
	int menu_item = 0, x = 7 , num1 , num2 ;
	bool running = true;

	gotoXY(18,5); cout << "Main Menu";
	gotoXY(18,7); cout << "__";

	while(running)
	{
        gotoXY(20,7);  cout << "1) Add";
		gotoXY(20,8);  cout << "2) Sub";
		gotoXY(20,9);  cout << "3) Mul";
		gotoXY(20,10); cout << "4) Div";
		gotoXY(20,11); cout << "5) Exit";

		system("pause>nul");


		if(GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "__";
				menu_item++;
				continue;
			}

		if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "__";
				menu_item--;
				continue;
			}

		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed

			switch(menu_item){

				case 0: {
					gotoXY(20,16);
					cout << "Result = " << ADD(num1,num2);
					break;
				}

				case 1: {
					gotoXY(20,16);
					cout << "Result = " << SUB(num1,num2);
					break;
				}

				case 2: {
					gotoXY(20,16);
					cout << "Result = " << MUL(num1,num2);
					break;
				}

				case 3: {
					gotoXY(20,16);
					cout << "Result = " << DIV(num1,num2);
					break;
				}

				case 4: {
					gotoXY(20,16);
					cout << "You terminate the program .";
					running = false;
				}

			}

		}

	}
	return 0;
}

void gotoXY( int column, int line )
{
	CursorPosition.X = column;
	CursorPosition.Y = line;
	SetConsoleCursorPosition(console,CursorPosition);
}

int ADD(int num1, int num2)
{
    system ("CLS");
    cout << "You chose Add Option , Enter 2 numbers you wants to add , \n";
    cout << "Enter First Number : " ;
    cin >> num1 ;
    cout << "Enter Second Number : " ;
    cin >> num2 ;
    return num1 + num2;
}

int SUB(int num1, int num2)
{
    system ("CLS");
    cout << "You chose Subtract Option , Enter 2 numbers you wants to subtract , \n";
    cout << "Enter First Number : " ;
    cin >> num1 ;
    cout << "Enter Second Number : " ;
    cin >> num2 ;
    return num1 - num2;
}

int MUL(int num1, int num2)
{
    system ("CLS");
    cout << "You chose Multiplication Option , Enter 2 numbers you wants to subtract multiple , \n";
    cout << "Enter First Number : " ;
    cin >> num1 ;
    cout << "Enter Second Number : " ;
    cin >> num2 ;
    return num1 * num2;
}

float DIV(int num1, int num2)
{
    system ("CLS");
    cout << "You chose Division Option , Enter 2 numbers you wants to subtract divide , \n";
    cout << "Enter First Number : " ;
    cin >> num1 ;
    cout << "Enter Second Number : " ;
    cin >> num2 ;
    return num1 / num2;
}
