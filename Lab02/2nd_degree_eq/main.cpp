#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c, x1, x2, discriminant, realPart, imaginPart;
    cout << "Enter the three coefficients of the equation : \n";
    cin >> a >> b >> c;
    discriminant = b*b - 4*a*c;

    if (discriminant >= 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }

    else {
        realPart = -b/(2*a);
        imaginPart =sqrt(-discriminant)/(2*a);
        cout << "x1 = " << realPart << "+" << imaginPart << "i" << endl;
        cout << "x2 = " << realPart << "-" << imaginPart << "i" << endl;
    }

    return 0;
}
