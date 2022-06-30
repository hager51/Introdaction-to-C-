#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int InpNum, Sum = 0;
    while (Sum <= 100){
        cout << "Enter the Number, please" << endl;
        cin >> InpNum;
        Sum += InpNum;
    }
    cout << "Sorry , the sum exceeds 100 !" << endl;

    return 0;
}
