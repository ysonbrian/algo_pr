from sys import stdin
input = stdin.readline
import heapq

numbers = int(input())
heap = []

#Max Heap
for _ in range(numbers):
    num = int(input())
    if num != 0:
        heapq.heappush(heap, (-num))
    else:
        try:
            print(-1 * heapq.heappop(heap))
        except:
            print(0)