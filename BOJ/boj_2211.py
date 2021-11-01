from heapq import heappush, heappop
import sys
input = sys.stdin.readline
def dijkstra(start):
    heap = []
    heappush(heap, [0, start])
    ck = [0 for i in range(n + 1)]
    dp = [100000000 for i in range(n + 1)]
    dp[start] = 0
    while heap:
        we, nu = heappop(heap)
        for ne, nw in s[nu]:
            wei = we + nw
            if dp[ne] > wei:
                dp[ne] = wei
                ck[ne] = nu
                heappush(heap, [wei, ne])
    return ck
n, m = map(int, input().split())
s = [[] for i in range(n + 1)]
for i in range(m):
    a, b, c = map(int, input().split())
    s[a].append([b, c])
    s[b].append([a, c])
ck = dijkstra(1)
print(n - 1)
for i in range(2, n + 1):
    print(i, ck[i])