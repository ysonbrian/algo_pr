#include <stdio.h>
#include <stdlib.h>

void Merge(int arr[], int tempArray[] , int lowerIndex, int middleIndex, int upperIndex) {
    int lowerStart = lowerIndex;
    int lowerStop = middleIndex;
    int upperStart = middleIndex + 1;
    int upperEnd = upperIndex;
    int count = lowerIndex;

    while(lowerStart <= lowerStop && upperStart <= upperEnd) {
        if (arr[lowerStart] < arr[upperStart]) {
            tempArray[count++] = arr[lowerStart++];
        }
        else{
            tempArray[count++] = arr[upperStart++];
        }
    }
    while (lowerStart <= lowerStop) {
        tempArray[count++] = arr[lowerStart++];
    }
    while(upperStart <= upperEnd) {
        tempArray[count++] = arr[upperStart++];
    }

    for(int i = lowerIndex;  i <= upperIndex; i++){
        arr[i] = tempArray[i];
    }
}

void MergeSortUtil(int arr[], int tempArray[], int lowerIndex, int upperIndex) {
    if(lowerIndex >= upperIndex)
        return;
    int middleIndex = (lowerIndex + upperIndex) / 2;
    MergeSortUtil(arr, tempArray, lowerIndex, middleIndex);
    MergeSortUtil(arr, tempArray, middleIndex + 1, upperIndex);
    Merge(arr, tempArray, lowerIndex, middleIndex, upperIndex);
}

void MergeSort(int arr[], int size) {
    int *tempArray = (int *)malloc(size * sizeof(int));
    MergeSortUtil(arr, tempArray, 0, size - 1);
}

int main() {
    int arr[10];
    int len = sizeof(arr) / sizeof(int);
    for(int i = 0; i < len; i++)
        scanf("%d", &arr[i]);

    MergeSort(arr, len);

    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);

    return 0;
}