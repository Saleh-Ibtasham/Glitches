#include <stdio.h>

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


    int arr[] = {0,1,2,3,4};

    int arr1=fun1(arr);

    cout << arr1[1] << endl;

    return 0;
}
