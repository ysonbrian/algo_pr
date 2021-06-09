from sys import stdin, stdout
input = stdin.readline

n = int(input())
total = 0
for i in range(n):
    data = list(input().split())
    total = float(data[0])
    i = 1
    while i < len(data):
        if data[i] == '@':
            total *= 3
            i += 1
        elif data[i] == '%':
            total += 5
            i += 1
        else:
            total -= 7
            i += 1
    print('{:.2f}'.format(total))