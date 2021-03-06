import sys
read = lambda : sys.stdin.readline().strip()
write = lambda x: sys.stdout.write(str(x)+ "\n")

a = read()
n = len(a)

dp = [[0 for i in range(n + 1)]for j in range(n + 1)]
result = [sys.maxsize] * (n+1)
result[0] = 0

for i in range(1, n+1):
    dp[i][i] = 1

for i in range(1, n):
    if a[i-1] == a[i]:
        dp[i][i+1] = 1

for i in range(2, n):
    for j in range(1, n+1-i):
        if a[j-1] == a[j+i-1] and dp[j+1][i+j-1] == 1:
            dp[j][i+j] = 1

for i in range(1, n+1):
    result[i] = min(result[i], result[i-1] + 1)
# result[i-1]+1인 이유는 result[i-1]까지의 팰린드롭에 j부터 i까지의 팰린드롭 한개를 더하는 것이기 때문이다
    for j in range(i+1, n+1):
        if dp[i][j] != 0:
          # 팰린드롭이면
            result[j] = min(result[j], result[i-1] + 1)

print(result[n])