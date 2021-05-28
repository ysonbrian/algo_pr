#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    int arr[10] = {0};

    for(int i=0; i< str.size(); i++){
        arr[str[i] - '0']++;
    }

    int num =0;
    for(int i=0; i< 10; i++){
        if(i!=9 && i!=6) num = max(num, arr[i]);
    }

    cout << max(num, (arr[6] + arr[9] + 1) /2);

    return 0;
}