# y좌표 기준 정렬

from sys import stdin, stdout
input = stdin.readline

n = int(input())
data = []

for i in range(n):
    data.append(list(map(int, input().split())))

data.sort(key=lambda x: (x[1], x[0]))

for i in range(n):
    print(data[i][0], data[i][1])