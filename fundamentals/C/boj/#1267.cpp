#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int arr[21];
    int k;
    int totalm = 0, totaly = 0;
    int total = 0;
    for(int i = 0; i < n ; i++){
        cin >>arr[i];
        totalm += (arr[i] / 60 + 1) * 15;
        totaly += (arr[i] / 30 + 1) * 10;
    }

    if(totalm < totaly)
        cout<< "M " << totalm << "\n";
    else if(totalm > totaly)
        cout <<"Y " << totaly << "\n";
    else
        cout<< "Y M " << totaly <<"\n";

    return 0;
}

