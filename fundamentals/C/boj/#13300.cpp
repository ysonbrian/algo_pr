#include <iostream>

using namespace std;

int freq[2][7];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    int S,Y;

    for(int i = 0; i < N; i++) {
        cin >> S >> Y;
        freq[S][Y]++;
    }

    int count = 0;

    for(int i = 0; i < 2; i++) {
        for(int j = 1; j <= 6; j++){
            if(!freq[i][j]) continue;

            if(freq[i][j] < K) count++;
            else{
                if(freq[i][j] % K == 0){
                    count = count + freq[i][j] / K;
                }
                else {
                    count = count + freq[i][j] / K + 1;
                }
            }

        }

    }
    cout << count << "\n";
    return 0;
}
