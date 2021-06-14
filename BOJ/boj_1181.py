# 단어 길이 기준 정렬 하는 문제
# 조건 : 중복 x
from sys import stdin, stdout
input = stdin.readline

n = int(input())

data_word = []
input_data = []
new_data = []
for i in range(n):
    data = input()
    if data not in input_data:
        input_data.append(data)

for i in input_data:
    new_data.append(i[:-1])

for i in new_data:
    data_word.append([i, len(i)])

data_word.sort(key=lambda x: (x[1], x[0]))

for i in data_word:
    print(i[0])


### 다른 사람 코드
from sys import stdin, stdout
input = stdin.readline

n = int(input())

word = set()
for _ in range(n):
    word.add(input())
word = list(word)
word.sort(key=lambda x:len(x))
print(''.join(word))

# 단어를 입력받고 리스트에 길이를 굳이 넣을 필요없이 정렬을 단어길이로 설정해주면 단어 길이순으로 정렬해줌
# 개행 문자를 없애려고 개행문자를 지우고 리스트에 추가했으나 join 함수를 사용하면 for문을 안쓰더라도 모든 문장을 출력해줌
