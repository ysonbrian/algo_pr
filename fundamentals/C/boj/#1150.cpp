#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    int left, right, x;
} input;

typedef struct
{
    int left, right, len;
} pqelem;

struct compare
{
    bool operator () (pqelem a, pqelem b)
    {
        return a.len > b.len;
    }
};

int main()
{
    input in[100002];
    int n, k, ans = 0;
    int length[100002];
    priority_queue < pqelem, vector<pqelem>, compare > pq;

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++)
    {
    	scanf("%d", &in[i].x);
    	in[i].left = i-1;
    	in[i].right = i+1;
    }

    for (int i = 1; i < n; i++)
    {
        pqelem tmp;
        tmp.left = i;
        tmp.right = i+1;
        tmp.len = in[i+1].x - in[i].x;
        pq.push(tmp);
        length[i] = tmp.len;
    }

    while (k--)
    {
        pqelem tmp = pq.top();
        pq.pop();

        int left = tmp.left, right = tmp.right, len = tmp.len;

        if (left < 1 || right > n || right != in[left].right || left != in[right].left)
        {
            k++;
            continue;
        }

        ans += len;
        int nextLeft = in[left].left, nextRight = in[right].right;

        tmp.left = nextLeft;
        tmp.right = nextRight;
        length[nextLeft] = length[nextLeft] + length[right] - len;
        tmp.len = length[nextLeft];
        pq.push(tmp);

        in[nextLeft].right = nextRight;
        in[nextRight].left = nextLeft;
    }

    printf("%d", ans);
    return 0;
}