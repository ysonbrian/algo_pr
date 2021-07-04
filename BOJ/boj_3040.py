from sys import stdin, stdout
input = stdin.readline

data = [int(input()) for _ in range(9)]

for i in range(8):
    for j in range(i+1, len(data)):
        if sum(data) - data[i] - data[j] == 100:
            del data[i]
            del data[j-1]
            print(*data, sep="\n")
            break


#