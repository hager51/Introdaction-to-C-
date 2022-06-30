#include <iostream>

using namespace std;

int main()
{
    int arr[10] , Min , Max ;

    for (int i=0 ; i < 10 ; i++)
    {
        cout << "Please, Enter the element number (" << i+1 << ") in our integer array :\n" ;
        cin >> arr[i];
    }

    Min = Max = arr[0] ;

    for (int j=0 ; j < 10 ; j++)
    {
        if (arr[j] > Max) {Max = arr[j] ;}
        if (arr[j] < Min) {Min = arr[j] ;}
    }

    cout << "\nThe Maximum Value in Array Is : " << Max << endl  ;
    cout << "\nThe Minimum Value in Array Is : " << Min << endl  ;

    return 0;
}
