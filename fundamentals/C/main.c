#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Binary_Search(int arr[], int size, int target){
    int start = 0;
    int end = size - 1;
    int mid;
    while(start < size) {
        mid = (start + size) / 2;
        if(arr[mid] == target) return 1;
        if(target < arr[mid])
            mid -= 1;
        else
            mid += 1;
    }

    return -1;

}


int main() {
    int arr = {1,2,3,4,5,6,7,8,9};
    int idx;
    idx = Binary_Search(arr, sizeof(arr) / sizeof(int), 8);
    if(idx == -1) {
        printf("Not found!\n");
    } else{
        printf("Found it!");
    }

    return 0;


}
