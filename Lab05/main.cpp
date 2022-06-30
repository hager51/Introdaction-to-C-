#include <conio.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

#define KEY_HOME 71
#define KEY_END 79
#define KEY_LEFT 75
#define KEY_RIGHT 77

#define KEY_Enter 13
#define KEY_Esc 27

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // for gotoXY function
COORD CursorPosition; // for gotoXY function

void gotoXY(int,int);

int main()
{
    int Size , flag = 1 , c = 0;

    cout << "Please, Enter the length of the line : ";
    cin >> Size ;

    char* St , *Curr , *End;
    St = new char[Size];
    if (St != NULL)
    {
        Curr = End = St ;
        delete(St);
    }
    cout << endl << "Enter your line : ";

    while(flag)
    {
        c = getch();
        if (c == 224)
        {
            switch(getch()) {
            case KEY_HOME: //key Home
                Curr = St;
                break;
            case KEY_END: // key End
                Curr = End;
                break;
            case KEY_LEFT: // key left
                Curr -- ;
                if (Curr < St) {Curr = St;}
                break;
            case KEY_RIGHT: // key right
                Curr ++;
                if (Curr > End) {Curr = End;}
                break;
            }
            gotoXY((Curr-St)+18,2);
        }

        else
        {
            if (isprint(c))
            {
                if ((Curr - St) < Size)
                {
                    *Curr = c;
                    cout << (char)c;
                    Curr ++ ;
                    if (Curr>End) {End++;}
                }
            }
            switch(c) {
            case KEY_Enter: // Key Enter
                End = '\0';
                flag = 0;
                cout << endl << endl << "You Write : " << St << endl;
                break;
            case KEY_Esc: // Key Esc
                St = '\0';
                flag = 0;
                cout << endl  << endl << "You terminate the program and delete content." << endl;
                break;
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
