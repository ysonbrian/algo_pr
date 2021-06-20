from sys import stdin, stdout
input = stdin.readline

max_value = 0
start = 0
for i in range(4):
    a, b = map(int, input().split())
    start -= a
    start += b
    max_value = max(max_value, start)
print(max_value)