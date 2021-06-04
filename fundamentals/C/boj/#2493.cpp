#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int> > stk;
    stack<pair<int, int>> result;
    int n, data, max, idx;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> data;
        while(!stk.empty()){
            if(stk.top().second > data){
                cout << stk.top().first << " ";
                break;
            }
            stk.pop();
        }
        if(stk.empty())
            cout << "0 ";
        stk.push(make_pair(i, data));
    }

    return 0;
}

