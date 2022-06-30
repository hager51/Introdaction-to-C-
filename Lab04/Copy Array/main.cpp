#include <iostream>

using namespace std;

int main()
{
    char arr[50] , Copy_Arr[50] ;
    cout << "Please, Enter the elements you want in the array : ";

    cin.get(arr, 50);
    cout << "\n\nYou Enter : " << arr << endl;

    for (int i=0 ; i < 50 ; i++){
        Copy_Arr[i] = arr[i] ;
    }

    cout << "\n\nThe Copied array is : " << Copy_Arr << endl;

    return 0;
}
