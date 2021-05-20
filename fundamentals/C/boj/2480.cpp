#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr[3];
    int max = -9999;
    for(int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    if(arr[0] == arr[1] && arr[0] == arr[2]) cout << 10000 + arr[0] * 1000;
    else if(arr[0] == arr[1] && arr[0] != arr[2])
        cout << 1000 + arr[0] * 100;
    else if(arr[1] == arr[2] && arr[1] != arr[0]){
        cout << 1000 + arr[1] * 100;
    } else if(arr[2] == arr[0] && arr[2] != arr[1]){
        cout << 1000 + arr[2] * 100;
    }
    else {
        for (int i = 0 ; i < 3; i++) {
            if (max < arr[i]) max = arr[i];
        }
        cout << max * 100;
    }
    return 0;
}