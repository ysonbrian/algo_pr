#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    int cnt = 0;

    cin >> n;
    vector<int> freq(n);
    for(int i = 0 ; i < n; i++) {
        cin >> freq[i];
    }

    sort(freq.begin(), freq.end());

    cin >> x;

    int head = 0, tail = n - 1;

    while (head < tail) {
        int sum = freq[head] + freq[tail];
        if (sum == x) {
            head++;
            tail--;
            cnt++;
        } else if (sum < x) {
            head++;
        } else {
            tail--;
        }
    }


    cout << cnt << "\n";
    return 0;

}