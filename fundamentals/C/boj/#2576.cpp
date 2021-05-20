#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    int total = 0;
    int min = 99999;

    for(int i = 0; i < 7; i++)
    {
        cin >> a;
        if(a % 2 == 1) {
            total += a;
            if(min > a) min = a;
        }
    }
    if(total == 0) cout << -1;
    else cout << total << "\n" << min ;

    return 0;
}
