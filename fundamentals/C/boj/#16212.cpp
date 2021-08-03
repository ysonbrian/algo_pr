#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,data;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> data;
        v.push_back(data);
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
        cout << v[i] << " ";

    cout <<"\n";


    return 0;
}