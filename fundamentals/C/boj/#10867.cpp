#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> num;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    for (int i = 0; i < num.size(); i++)
        cout << num[i] << ' ';

    return 0;
}