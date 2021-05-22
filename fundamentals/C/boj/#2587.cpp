#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sum = 0;
    vector<int> v(5);

    for (int i = 0; i < 5; i++) cin >> v[i], sum += v[i];
    sort(v.begin(), v.end());
    cout << sum / 5 << '\n' << v[2];

    return 0;
}

