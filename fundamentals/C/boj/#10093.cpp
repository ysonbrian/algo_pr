#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        long long A, B;
        cin >> A >> B;
        if (A > B)
          swap(A, B);
        if (A != B)
        {
          cout << B - A - 1 << "\n";
          for (long long i = A + 1; i < B; i++)
            cout << i << " ";
          cout << "\n";
        }
        else cout << 0 << "\n";
        return 0;
}