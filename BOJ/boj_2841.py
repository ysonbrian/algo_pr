import sys

N, P = map(int, sys.stdin.readline().split())
li = [[] for _ in range(6)]
res = 0
for _ in range(N):
    i, p = map(int, sys.stdin.readline().split())
    i -= 1
    if li[i] == [] or li[i][-1] < p:
        li[i].append(p)
        res += 1
    else:
        while li[i] != [] and li[i][-1] > p:
            li[i].pop()
            res += 1
        if li[i] != [] and li[i][-1] == p:
            continue
        li[i].append(p)
        res += 1
print(res)