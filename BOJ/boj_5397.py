from sys import stdin, stdout
input = stdin.readline


t = int(input())

for _ in range(t):
    left_stack = []
    right_stack = []
    data = input().rstrip()
    for i in data:
        if i == '-':
            if left_stack:
                left_stack.pop()
        elif i == '<':
            if left_stack:
                right_stack.append(left_stack.pop())
        elif i == '>':
            if right_stack:
                left_stack.append(right_stack.pop())
        else:
            left_stack.append(i)
    left_stack+=right_stack[::-1]
    print(''.join(left_stack))