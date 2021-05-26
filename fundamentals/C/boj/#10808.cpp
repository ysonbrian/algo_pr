#include <iostream>

using namespace std;

// 1 번째 방법

// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string s;
//     cin >> s;

//     for(char a = 'a'; a <= 'z'; a++) {
//         int cnt = 0;
//         for(auto c : s) {
//             if(a == c) cnt++;
//         }
//         cout << cnt << " ";
//     }

//     return 0;
// }

// 문제는 무난한 문제였는데 괜히 아스키코드로 접근하여 아스키코드 97~122 까지
// 반복문을 돌려가며 값을 찾으려고 접근했으나 각 환경마다 아스키코드를 변환해주는 시스템이
// 아니라면 포문에 'a'~ 'z'로 접근하는게 깔끔한 접근법이며 전체를 저장하고 출력하는 것 보다
// 각 결과를 바로바로 출력 해주는 것이 코드양을 훨씬 줄일 수 있었다.
// 아주 쉬운 문제를 어렵게 접근하다보니 어렵다고 느꼈지만 중요한걸 배울 수 있었다


// 2 번째 방법

int freq[26];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    for(auto c : s)
        freq[c-'a']++;

    for(int i = 0; i < 26; i++)
        cout << freq[i]<< ' ';

    return 0;
}

// 입력받은 문자에 'a'를 빼주면 freq 배열의 인덱스 값을 대치하여 결과값을 확인 할 수 있기때문에
// 첫 번째 방법보다 더 빠른 O(n)으로 시간복잡도를 줄일 수 있다


