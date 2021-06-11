class Node:
    def __init__(self,value):
        self.value = value
        self.left = None
        self.right = None

class NodeMgmt:
    def __init__(self, head):
        self.head = head

    def insert(self, value):
        self.current_node = self.head
        while True:
            if value < self.current_node.value:
                if self.current_node.left != None:
                    self.current_node = self.current_node.left
                else:
                    self.current_node.left = Node(value)
                    break
            else:
                if self.current_node.right != None:
                    self.current_node = self.current_node.right
                else:
                    self.current_node.right = Node(value)
                    break

    def search(self, value):
        self.current_node = self.head
        while self.current_node:
            if self.current_node.value == value:
                return True
            elif value < self.current_node.value:
                self.current_node = self.current_node.left
            else:
                self.current_node = self.current_node.right
        return False

    #     삭제 경우의수
    #     삭제 할 노드가 자식노드로써 한개일때
    #     삭제할 노드가 자식 노드를 2개 가지고 있을 경우
    #     삭제할 노드가 자식 노드를 2개 가지고 있는경우 -> 삭제할 노드의 오른쪽 자식중 가장 작은 노드를 고른다 / 삭제할 도드의 왼쪽 자식중 가장 큰 노드를 고른다


    def delete(self, value):
        searched = False
        self.current_node = self.head
        self.parent = self.head
        while self.current_node:
            if self.current_node.value == value:
                searched = True
                break
            elif value < self.current_node.value:
                self.parent = self.current_node
                self.current_node = self.current_node.left
            else:
                self.parent = self.current_node
                self.current_node = self.current_node.right
        if searched == False:
            return False

        ### 여기부터 self.current_node는 삭제할 노드이고 self.parent는 삭제할 노드의 부모노드가 됨

        #  1. 삭제할 노드가 자식노드가 없는경우
        if  self.current_node.left == None and self.current_node.right == None:
            if value < self.parent.value:
                self.parent.left = None
            else:
                self.parent.right = None

        #  2. 삭제할 노드의 자식이 왼쪽만 있는경우
        elif self.current_node.left != None and self.current_node.right == None:
            if value < self.parent.value:
                self.parent.left = self.current_node.left
            else:
                self.parent.right = self.current_node.left
        elif self.current_node.left == None and self.current_node.right != None:
            if value < self.parent.value:
                self.parent.left = self.current_node.right
            else:
                self.parent.right = self.current_node.right

        #  3. 삭제할 노드가 2개의 자식노드를 모두 가지고 있는경우 -> '삭제할 노드의 오른쪽 자식중 가장 작은 노드를 고른다' 이방법을 사용
        # 삭제할 노드가 2개의 자식노드를 모두 가지고 있는경우
        elif self.current_node.left != None and self.current_node.right != None:
            if value < self.parent.value:
                # 여기 전 까지는 self.current_node가 삭제할 노드를 가리키고 있고 이 이후부터 삭제할 노드의 자리를 다른 노드로 바꿔줘야 하기 때문에 right로 이동후에 값을 찾는 과정이 필요
                self.change_node = self.current_node.right
                self.change_node_parent = self.current_node.right
                while self.change_node.left != None:
                    self.change_node_parent = self.change_node
                    self.change_node = self.change_node.left
                # 삭제할 노드가 부모노드의 왼쪽에 있고 삭제할 노드의 오른쪽 자식중 가장 작은 값을 가진 노드의 자식노드가 없을경우
                if self.cahnge_node.right != None:
                    self.change_node_parent.left = self.change_node.right
                else:
                    self.change_node_parent.left = None
                # 삭제하고 바뀐 자리의 노드를 삭제한 노드가 연결된 왼쪽 오른쪽과 연결시켜준다
                self.parent.left = self.change_node
                self.change_node.right = self.current_node.right
                self.change_node.left = self.change_node.left

                # 삭제할 노드가 있고 삭제할 노드의 오른쪽 자식중 가장 작은 값을 찾기위해 자식 노드로 이동후 왼쪽으로 계속 이동 한다
            else:
                self.change_node = self.current_node.right
                self.change_node_parent = self.current_node.right
                while self.change_node.left != None:
                    self.change_node_parent = self.change_node
                    self.change_node = self.chasnge_node.left
                # 삭제할 노드의 자식노드중에 가장 작은 노드를 찾고 찾은 위치의 노드가 왼쪽 또는 오른쪽 자식이 있는경우의 자리를 옮기는 과정
                if self.change_node.right != None:
                    self.change_node_parent.left = self.change_node.right
                else:
                    self.change_node_parent.left = None
                # 삭제할 노드를 가장 작은 노드로 교체 하는 과정
                self.parent.right = self.change_node
                self.change_node.right = self.current_node.right
                self.change_node.left = self.current_node.left

        return True


# 0 ~ 999 숫자 중에서 임의로 100개를 추출해서, 이진 탐색 트리에 입력, 검색, 삭제
import random

# 0 ~ 999 중, 100 개의 숫자 랜덤 선택
bst_nums = set()
while len(bst_nums) != 100:
    bst_nums.add(random.randint(0, 999))
# print (bst_nums)

# 선택된 100개의 숫자를 이진 탐색 트리에 입력, 임의로 루트노드는 500을 넣기로 함
head = Node(500)
binary_tree = NodeMgmt(head)
for num in bst_nums:
    binary_tree.insert(num)

# 입력한 100개의 숫자 검색 (검색 기능 확인)
for num in bst_nums:
    if binary_tree.search(num) == False:
        print ('search failed', num)

# 입력한 100개의 숫자 중 10개의 숫자를 랜덤 선택
delete_nums = set()
bst_nums = list(bst_nums)
while len(delete_nums) != 10:
    delete_nums.add(bst_nums[random.randint(0, 99)])

# 선택한 10개의 숫자를 삭제 (삭제 기능 확인)
for del_num in delete_nums:
    if binary_tree.delete(del_num) == False:
        print('delete failed', del_num)