from collections import deque

def solution():
    time = 0
    while len(data)!=0 or sum(a)!=0:
        a[0] = 0
        a.rotate(-1)

        if len(data)!=0 and (sum(a) + data[0]) <= l:
            number = data.pop(0)
            a[w - 1] = number
        time += 1
    return time

n,w,l = map(int,input().split())
data = list(map(int,input().split()))
a = deque([0]*w)
print(solution())