from sys import stdin, stdout
input = stdin.readline
n = int(input())
data_list = list(map(int, input().split()))
checked = False
total = 0
extra = 1
for num in data_list:
    if num == 1 and checked == True:
        extra += 1
        total += extra
    elif num == 1 and checked == False:
        checked = True
        total += extra
    else:
        extra = 1
        checked = False
print(total)