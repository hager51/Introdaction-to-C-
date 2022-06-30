#include <iostream>

using namespace std;

int main()
{
    int arr[3][4] ;

    for(int i=0 ; i < 3 ; i++)
    {
        int Sum = 0 ;

        for(int j=0 ; j < 4 ; j++)
        {
            cout << "\nEnter the degree of subject " << j+1 << " for student " << i+1 << " : ";
            cin >> arr[i][j];
            Sum += arr[i][j];
        }
        cout << "\nStudent no." << i+1 << " get : " << Sum << " as a total. \n" ;
    }

    for(int i=0 ; i < 3 ; i++)
    {
        int total = 0 ;
        float Avg = 0 ;

        for(int j=0 ; j < 3 ; j++)
        {
            total += arr[i][j];
        }

        Avg = total / 3;
        cout << "\nAverage degree of subject no." << i+1 << "  is " << Avg << " . \n" ;
    }

    return 0;
}
