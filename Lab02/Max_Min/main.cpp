#include <iostream>

using namespace std;

int main()
{

   int GroupOfNum, InputNumber, Min, Max = 0;

    cout << "How many numbers would you like to enter?" << endl;
    cin >> GroupOfNum;
    cout << "Enter " << GroupOfNum << " integers, please" << endl;

    for(int Count = 0 ; Count < GroupOfNum; Count++)
    {
            cin >> InputNumber;
            if(InputNumber > Max)
            {
                    Max = InputNumber;
            }
            if(InputNumber < Min)
            {
                    Min = InputNumber;
            }
    }

    cout << "min: " << Min << endl;
    cout << "max: " << Max << endl;

    return 0;
}
