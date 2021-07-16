from collections import Counter

while True:
  try:
    a, b = map(int, input().split())
    data = [int(i) for i in range(a, b+1)]
    cnt = 0
    for i in data:
      new_data = str(i).split()
      result=''
      for j in new_data:
        result = Counter(j)
        check = False
        for k,v in result.items():
          if v > 1:
            check = True
            break
        if check is not True:
            cnt += 1
    print(cnt)
  except EOFError:
    break