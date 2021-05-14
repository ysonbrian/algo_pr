#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100

int Sum(int *arr) {
  int total = 0;
  for (int i = 0; i < 9; i++){
    total += arr[i];
  }

  return total;
}

int Solution(int *arr, int total) {
  for(int i = 0; i<9; i++) {
    for(int j = i+1; j < 9; j++) {
      if(total - (arr[i]+arr[j]) == MAX){
        arr[i] = -1;
        arr[j] = -1;
        return 0;
      }
    }
  }
  return -1;
}

int main() {
  int arr[9];
  int total_sum;
  for(int i = 0; i < 9; i++)
    cin >> arr[i];
  total_sum = Sum(arr);
  Solution(arr, total_sum);

  sort(arr, arr+9);
  for(int i = 2; i < 9; i++) {
    cout << arr[i] << endl;
  }

  return 0;
}
