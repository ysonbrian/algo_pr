from sys import stdin, stdout
input = stdin.readline

n = int(input())
data = []
for i in range(1, n + 1):
    a, b = input().split()
    data.append([int(a), b, i])

data.sort(key=lambda x: (x[0],x[2]))

for i in range(n):
    print(data[i][0], data[i][1])