from sys import stdin, stdout
input = stdin.readline

n = list(input())
new_data = [int(n[i]) for i in range(len(n) - 1) ]
new_data.sort(reverse=True)
print(''.join(map(str, new_data)))