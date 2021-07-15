iA = 'AAAA'
iB = 'BB'
data = input().strip()
new_data = data[:].split('.')
new_data = [i for i in new_data if i]
for i in range(len(new_data)):
  word = ''
  if len(new_data[i]) == len(iA):
    new_data[i] = iA
  elif len(new_data[i]) == len(iB):
    new_data[i] = iB
  else:
    if len(new_data[i]) % 2 != 0:
      print(-1)
      break
    count_iA = len(new_data[i]) // 4
    count_iB = (len(new_data[i]) % 4) // 2
    word = (iA*count_iA) + (iB*count_iB)
    new_data[i] = word
print(data)
print(new_data)
# C 방식으로 하면 전체를 다 바꿔줘야하지만
# 파이썬은 간단히 replace 함수를 쓰면 문자의 앞부분부터 차례대로 원하는 값으로 치환해준다
data = input().strip()
data = data.replace('XXXX', 'AAAA')
data = data.replace('XX', 'BB')
if 'X' in data:
  print(-1)
else:
  print(data)