#include <iostream>
using namespace std;

long Power_Factor(int , int);

int main()
{
    int base , exp ;
    cout << "\n Please, Enter Base : " ;
    cin >> base;
    cout << "\n Please, Enter exponent : " ;
    cin >> exp;

    cout << "\n The Result = " << Power_Factor(base , exp) << endl ;

    return 0;
}

long Power_Factor(int base, int exp)
{
    long result = 1;

    if (exp >= 1)
    {
        result = base * Power_Factor(base , --exp);
    }
    return result;
}
