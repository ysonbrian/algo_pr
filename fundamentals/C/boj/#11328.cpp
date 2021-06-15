#include <iostream>
#include <algorithm>

using namespace std;

int freq[26];
int freq2[26];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    string first;
    string second;
    cin >> N ;
    bool flag = true;
    for(int i = 0; i < N; i++) {

        cin >> first >> second;

        for(int i = 0; i < first.length(); i++){
            freq[first[i] - 'a']++;
            freq2[second[i] - 'a']++;
        }

        flag = true;

        for(int i = 0; i < 26; i++) {
            if(freq[i] != freq2[i]) {
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "Possible" << "\n";
        else
            cout << "Impossible" << "\n";

        fill(freq, freq+26, 0);
        fill(freq2, freq2+26, 0);
    }

    return 0;
}