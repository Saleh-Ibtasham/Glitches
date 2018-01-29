#include <iostream>

using namespace std;

int *fun1(int *arr)
{
    int arr1[3] = {};

    for(int i=0; i<3; i++)
    {
        arr[i] = i;
    }

    return arr1;
}

int main()
{

    int i=5;
    int z;
    for(int x=10;x>=1;x++)
    {
        z=50/(x-i);
        cout << z << endl;
    }

    return 0;
}
