#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
int dp[100000];

int main() {
    for(int i = 0; i < 9; i++)
      cin >> arr[i];
    dp[0] = arr[0];
    int result = dp[0];
    for(int i = 1; i< 9; i++){
      dp[i] = max(dp[i-1] + arr[i], arr[i]);
      result = max(result, dp[i]);
    }
    cout << result << endl;
}
