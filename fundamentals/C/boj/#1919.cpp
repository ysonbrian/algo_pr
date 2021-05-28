#include <iostream>
#include <string>

using namespace std;

int freq1[26];
int freq2[26];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1;
    string str2;

    cin >> str1 >> str2;


    for(int i = 0 ; i < str1.length(); i++) {
        freq1[str1[i] - 'a']++;
    }
    for(int i = 0; i < str2.length(); i++){
        freq2[str2[i] - 'a']++;
    }

    int count = 0;
    for(int i = 0; i < 26; i++){
        if(freq1[i] != freq2[i])
            count += abs(freq1[i] - freq2[i]);
    }

    cout << count << "\n";

    return 0;

}
