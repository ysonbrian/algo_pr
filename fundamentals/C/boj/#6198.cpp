#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    vector<int> data(80001);
    int n;
    long long result = 0;
    cin >> n;

    for(int i = 0; i < n ; i++)
        cin >> data[i];

    for(int i = 0; i < n; i++){
        while(!s.empty() && s.top() <= data[i])
            s.pop();

        result += s.size();
        s.push(data[i]);
    }

    cout << result << "\n";


    return 0;
}

