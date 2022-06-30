#include <iostream>

using namespace std;

class Shape
{
protected:
    int dim1, dim2;
public:
    Shape() {dim1 = dim2 = 0;}
    Shape(int num) {dim1 = dim2 = num;}
    Shape(int num1 , int num2)
    {
        dim1 = num1;
        dim2 = num2;
    }

    void SetDim1(int num1) {dim1 = num1;}
    void SetDim2(int num2) {dim2 = num2;}

    int GetDim1() {return dim1;}
    int GetDim2() {return dim2;}

    virtual float Area() = 0;
};

class Circle : public Shape
{
public:
    Circle() {};
    Circle(int r):Shape(r) {};
    float Area() {return 3.14*dim1*dim2;}
};

class Rectangle : public Shape
{
public:
    Rectangle() {};
    Rectangle(int L , int W):Shape(L , W) {};
    float Area() {return 1.0*dim1*dim2;}
};

class Triangle : public Shape
{
public:
    Triangle() {};
    Triangle(int B , int H):Shape(B , H) {};
    float Area() {return 0.5*dim1*dim2;}
};

class Square : public Rectangle
{
public:
    Square(){};
    Square(int x):Rectangle(x,x){};
};

class GeoShape
{
private:
    Shape *Ptr[4];
public:
    GeoShape(Shape *P1 , Shape *P2 , Shape *P3 , Shape *P4)
    {
        Ptr[0] = P1;
        Ptr[1] = P2;
        Ptr[2] = P3;
        Ptr[3] = P4;
    }

    float TotalArea()
    {
        float total = 0;
        for (int i=0 ; i<4 ; i++)
        {
            total += Ptr[i]->Area();
        }
        return total;
    }
};

int main()
{
    Circle C(3);
    Rectangle R(6,9);
    Triangle T(4,7);
    Square S(5);
    GeoShape G(&C , &R , &T , &S);
    cout << "\nCircle Area = " << C.Area() << endl;
    cout << "Rectangle Area = " << R.Area() << endl;
    cout << "Triangle Area = " << T.Area() << endl;
    cout << "Square Area = " << S.Area() << endl;
    cout << "\nTotal Area = " << G.TotalArea() << endl;
    return 0;
}
