from sys import stdin
from collections import defaultdict

N = int(stdin.readline())
for _ in range(N):
    # 설계도를 입력 받을 때 테두리를 빈 칸 . 으로 채우기
    h, w = map(int, stdin.readline().split())
    h_arr, w_arr = h + 2, w + 2
    arr = [["." for j in range(w_arr)] for i in range(h_arr)]
    for i in range(h) :
        arr[i+1][1:-2] = stdin.readline().strip()

    # 상근이가 이미 가지고 있는 열쇠
    keys = list(stdin.readline().strip())
    keys.append(".")

    stack = [(0, 0)] # 탐색할 노드를 저장
    ans = 0  # 상근이가 훔친 문서의 수
    unlock = defaultdict(list) # 열리지 않은 문을 저장 {필요한 키:[(r1, c1), (r2, c2)...]}

    while stack:
        r, c = stack.pop()
        candidate = [(r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]  # 좌우 상하 4개의 절점을 탐색 가능
        item = arr[r][c]

        if item == "$": ans += 1  # 문서를 얻습니다.

        elif item.lower() in keys: pass  # 문을 열 수 있습니다.

        elif item.islower():
            keys.append(item)  # 키를 얻습니다.
            candidate += unlock[item]  # 탐색 범위에 추가
            unlock[item] = list()  # 초기화

        elif item != "*":  # 문을 열지 못합니다.
            unlock[item.lower()].append((r, c))  # 필요한 키를 저장합니다.
            continue

        else: continue

        arr[r][c] = "*"  # 지나갈 수 없음

        for r1, c1 in candidate:
            if 0 <= r1 < h_arr and 0 <= c1 < w_arr:
                if arr[r1][c1] != "*":
                    stack.append((r1, c1))
    print(ans)