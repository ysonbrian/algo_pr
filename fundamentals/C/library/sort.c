#include <stdio.h>
#include <stdlib.h>

void SelectSort(int arr[]) {
    int i,j, temp, index;
    int min;
    for(i = 0; i < 10; i++){
        min = 99999;
        for(j = i; j < 10; j++){
            if(arr[j] < min) {
                index = j;
                min = arr[j];
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

    for(i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

}

void BubbleSort(int arr[]) {
    int temp, index,i,j, min;

    for(i = 0; i < 10; i++) {
        for(j = i + 1; j < 10 - i; j++) {
            if(arr[j] < arr[i] ) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

    }

    for(i = 0 ; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void InsertSort(int arr[]) {
    int i, j, temp;

    for(i = 0 ; i < 9; i++) {
        j = i;
        while(arr[j] > arr[j+1]) {
            temp =arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            j--;
        }
    }

    for(i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    printf("\n");

}

int main()
{
    int arr [10] = {1,10,5,8,7,6,4,3,2,9};
    SelectSort(arr);
    BubbleSort(arr);
    InsertSort(arr);
    return 0;

}

