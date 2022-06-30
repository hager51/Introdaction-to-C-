#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // for gotoXY function
COORD CursorPosition; // for gotoXY function

void gotoXY(int,int);

int main()
{
    int Size , num , row = 0 , col = 0;
    cout << "Please, Enter Odd Number Of Our Magic Box \n" ;
    cin >> Size;
    if (Size % 2 == 0){
        cout << "This is invalid size . \n";
    }
    else {
        for(num=1 ; num<=Size*Size ; num++){
            if(num == 1){
                col = (Size/2) + 1;
                row = 1;
            }
            else {
                if((num-1)%Size == 0){ row++ ;}
                else {
                    row-- ;
                    col-- ;
                    if (row == 0){row=Size;}
                    if (col == 0){col=Size;}
                }
            }
            gotoXY(col*3, row*2);
            cout << num << endl;
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
