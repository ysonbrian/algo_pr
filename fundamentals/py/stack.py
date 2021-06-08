class Node(object):
    def __init__(self, value=None, pointer=None):
        self.value = value
        self.pointer = pointer



class Stack(object):
    def __init__(self):
        self.head = None
        self.count = 0

    def isEmpty(self):
        return not bool(self.head)

    def push(self, item):
        self.head = Node(item, self.head)
        self.count += 1

    def pop(self):
        if self.count > 0 and self.head:
            node= self.head
            self.head = node.pointer
            self.count -= 1
            return node.value
        else:
            print("Stack is Empty")

    def size(self):
        return self.count

    def peek(self):
        if self.count > 0 and self.head:
            return self.head.value
        else:
            print("Stack is Empty")

    def _printList(self):
        node = self.head
        while node:
            print(node.value, end=" ")
            node = node.pointer
        print()


stack = Stack()
print("IS Stack Empty? {0}".format(stack.isEmpty()))
print("Add some numbers")
for i in range(10):
    stack.push(i)

print("Stack size = {0}".format(stack.size()))
print(f'peek = {stack.peek()}')
print(f'pop = {stack.pop()}')
print(f'peek = {stack.peek()}')
print(f'Is stack empty? {stack.isEmpty()}')
print(stack._printList())