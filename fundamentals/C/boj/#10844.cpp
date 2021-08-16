#include<iostream>

#define endl "\n"
#define MAX 100 + 1
#define Moduler 1000000000
typedef long long ll;
using namespace std;

int N;
ll Answer;
ll DP[MAX][11];

void Input()
{
    cin >> N;
}

void Solution()
{
    //DP[a][b] == 길이가 a 일때 마지막 수가 b일 경우의 계단의 수
    for (int i = 1; i <= 9; i++)
    {
        DP[1][i] = 1;    // 0을 제외한 한자리 숫자는 모두 계단 수
    }
    DP[1][0] = 0;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0) DP[i][j] = DP[i - 1][j + 1] % Moduler;
            else if (j == 9) DP[i][j] = DP[i - 1][j - 1] % Moduler;
            else DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % Moduler;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        Answer = Answer + DP[N][i];
    }
    cout << Answer % 1000000000 << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}
