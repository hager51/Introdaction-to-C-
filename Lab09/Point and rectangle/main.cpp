#include <iostream>
#include <cstdlib>

using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point()
    {
        x = y = 0;
    }

    Point(int num)
    {
        x = y = num;
    }

    Point(int num1 , int num2)
    {
        x = num1;
        y = num2;
    }

    void SetX(int num)
    {
        x = num;
    }

    void SetY(int num)
    {
        y = num;
    }

    int GetX()
    {
        return x;
    }

    int GetY()
    {
        return y;
    }
};

class RectComp
{
private:
    Point P1;
    Point P2;
    int Length;
    int Width;
public:
    RectComp()
    {
        Length = Width = 0;
    }

    RectComp(int x1, int y1, int x2, int y2)
    {
        P1.SetX(x1);
        P1.SetY(y1);
        P2.SetX(x2);
        P2.SetY(y2);

        Length = abs(x2 - x1);
        Width = abs(y2 - y1);
    }

    void SetP1(int X, int Y)
    {
        P1.SetX(X);
        P1.SetY(Y);
        Length = abs(P2.GetX() - X);
        Width = abs(P2.GetY() - Y);
    }

    void SetP2(int X, int Y)
    {
        P2.SetX(X);
        P2.SetY(Y);
        Length = abs(P2.GetX() - X);
        Width = abs(P2.GetY() - Y);
    }

    int Area()
    {
        return (Length*Width);
    }
};

class RectAssoc
{
private:
    Point *P1;
    Point *P2;
    int Length;
    int Width;

public:
    RectAssoc()
    {
        P1 = P2 = NULL;
        Length = Width = 0;
    }

    void SetP1(Point *P)
    {
        P1 = P;
        if (P1 != NULL && P2 != NULL)
        {
            Length = abs(P1->GetX() - P2->GetX());
            Width = abs(P1->GetY() - P2->GetY());
        }
        else
        {
            Length = Width = 0;
        }
    }

    void SetP2(Point *P)
    {
        P2 = P;
        if (P1 != NULL && P2 != NULL)
        {
            Length = abs(P1->GetX() - P2->GetX());
            Width = abs(P1->GetY() - P2->GetY());
        }
        else
        {
            Length = Width = 0;
        }
    }

    int Area()
    {
        return (Length*Width);
    }
};
int main()
{
    RectComp R(2,5,7,6);
    cout << "\nArea = " << R.Area() << endl;

    RectAssoc Rect;
    Point P1(8) , P2(4,5);
    Rect.SetP1(&P1);
    Rect.SetP2(&P2);
    cout << "\nArea = " << Rect.Area() << endl;

    R.SetP1(3,4);
    cout << "\nArea = " << R.Area() << endl;
    return 0;
}
