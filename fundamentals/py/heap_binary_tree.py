# 힙 트리
# 힙 트리는 배열로 구현하면 쉽게 구현가능
# 부모노드 인덱스 = 자식노드 인덱스 // 2
# 왼쪽자식 노드 인덱스 = 부모 노드 인덱스 * 2
# 오른쪽 자식 노드 인덱스 = 부모 노드 인덱스 * 2 + 1

class Heap:
    def __init__(self, data):
        self.heap_array = list()
        # 첫 인덱스는 1 부터 시작해야 계산하기 편하므로 첫번째는 아무것도 안넣음
        self.heap_array.append(None)
        self.heap_array.append(data)

    def move_up(self, inserted_idx):
        # root node 인경우
        if inserted_idx <= 1:
            return False

        parent_idx = inserted_idx // 2
        if self.heap_array[inserted_idx] > self.heap_array[parent_idx]:
            return True
        else:
             return False


    def insert(self, data):
        if len(self.heap_array) == 0:
            self.heap_array.append(None)
            self.heap_array.append(data)
            return True

        self.heap_array.append(data)

        inserted_idx = len(self.heap_array) - 1

        while self.move_up(inserted_idx):
            # move_up 함수를 통해 부모노드보다 새로 만든 노드보다 작다면 밑의 과정을 통해 노드 자리를 바꿔줌
            parent_idx = inserted_idx // 2
            self.heap_array[inserted_idx], self.heap_array[parent_idx] = self.heap_array[parent_idx], self.heap_array[inserted_idx]
            inserted_idx = parent_idx

        return True

    def move_down(self, popped_idx):

        left_child_popped_idx = popped_idx * 2
        right_child_popped_idx = popped_idx * 2 + 1

        # 1 왼쪽 자식 노드가 없을때
        if left_child_popped_idx >= len(self.heap_array):
            return False
        # 2 왼쪽 자식 노드는 있지만 오른쪽 자식 노드는 없을때
        elif right_child_popped_idx >= len(self.heap_array):
            if self.heap_array[popped_idx] < self.heap_array[left_child_popped_idx]:
                return True
            else:
                return False
        # 3 왼쪽, 오른쪽 자식 노드가 있을때
        else:
            # 왼쪽 자식 노드가 더 클때
            if self.heap_array[left_child_popped_idx] >self.heap_array[right_child_popped_idx]:
                if self.heap_array[popped_idx] < self.heap_array[left_child_popped_idx]:
                    return True
                else:
                    return False
            # 오른쪽 자식 노드가 더 클때
            else:
                if self.heap_array[popped_idx] < self.heap_array[right_child_popped_idx]:
                    return True
                else:
                    return False

    def pop(self):
        if len(self.heap_array) <= 1:
            return None

        # 마지막 노드를 첫번째로 옮김
        returned_data = self.heap_array[1]
        self.heap_array[1] = self.heap_array[-1]
        del self.heap_array[-1]

        popped_idx = 1

        while self.move_down(popped_idx):
            left_child_popped_idx = popped_idx * 2
            right_child_popped_idx = popped_idx * 2 + 1

            # 2 왼쪽 자식 노드는 있지만 오른쪽 자식 노드는 없을때
            if right_child_popped_idx >= len(self.heap_array):
                if self.heap_array[popped_idx] < self.heap_array[left_child_popped_idx]:
                    self.heap_array[popped_idx], self.heap_array[left_child_popped_idx] = self.heap_array[left_child_popped_idx], self.heap_array[popped_idx]
                    popped_idx = left_child_popped_idx
            # 3 왼쪽, 오른쪽 자식 노드가 있을때
            else:
                # 왼쪽 자식 노드가 더 클때
                if self.heap_array[left_child_popped_idx] >self.heap_array[right_child_popped_idx]:
                    if self.heap_array[popped_idx] < self.heap_array[left_child_popped_idx]:
                        self.heap_array[popped_idx], self.heap_array[left_child_popped_idx] = self.heap_array[left_child_popped_idx], self.heap_array[popped_idx]
                        popped_idx = left_child_popped_idx
                # 오른쪽 자식 노드가 더 클때
                else:
                    if self.heap_array[popped_idx] < self.heap_array[right_child_popped_idx]:
                        self.heap_array[popped_idx], self.heap_array[right_child_popped_idx] = self.heap_array[right_child_popped_idx], self.heap_array[popped_idx]
                        popped_idx = right_child_popped_idx

        return returned_data