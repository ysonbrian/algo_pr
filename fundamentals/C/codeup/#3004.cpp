#include <iostream>
using namespace std;
int partition(int arr[],int low, int high)
{
    int pivot=low;
    int L=low+1;
    int R=high;
    while(L < R)
    {
        while(arr[pivot] > arr[L] && L<R) L++;
        while(arr[pivot] <= arr[R] && L<R) R--;
        if(L < R)
        {
            int temp = arr[L];
            arr[L] = arr[R];
            arr[R] = temp;
        }
    }
    if(arr[pivot] > arr[R])
    {
        int temp = arr[pivot];
        arr[pivot] = arr[R];
        arr[R] = temp;
    }
    return R;
}

void quickSort(int arr[],int left,int right)
{
    if(left<right)
    {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot, right);
    }
}
int main()
{
    int n,min,max,flag;
    cin>>n;
    int arr1[n+1]={0},arr2[n+1]={0};
    for(int i=0; i<n; i++)
    {
        cin>>arr1[i];
        arr2[i]=arr1[i];
    }
    quickSort(arr2, 0,  n-1);
    for(int i=0; i<n; i++)
    {
        min=0;
        max=n;
        flag=(min+max)/2;
        for(;;){
            if(arr1[i] == arr2[flag])
            {
                cout<<flag<<' ';
                break;
            }
            else if(arr1[i] > arr2[flag])
            {
                min=flag+1;
                flag=(max+min)/2;
            }
            else
            {
                max=flag;
                flag=(max+min)/2;
            }
        }
    }
}