#include <iostream>

using namespace std;

int main()
{
    int arr[10];
    for (int i=0 ; i < 10 ; i++)
    {
        cout << "Please, Enter the element number (" << i+1 << ") in our integer array :\n" ;
        cin >> arr[i];
    }

    cout <<"\n\nYou Enter : \n";

    for (int i = 0 ; i < 10 ; i++)
    {
        cout << arr[i] << "  ";
    }

    cout << "\n\n" ;
    return 0;
}
