class Node(object):
    def __init__(self, value=None, pointer=None):
        self.value = value
        self.pointer = pointer



class LinkedQueue(object):
    def __init__(self):
        self.head = None
        self.tail = None
        self.count = 0

    def isEmpty(self):
        return not bool(self.head)

    def enqueue(self, value):
        node = Node(value)
        if not self.head:
            self.head = node
            self.tail = node
        else:
            if self.tail:
                self.tail.pointer = node
            self.tail =node
        self.count += 1

    def dequeue(self):
        if self.head:
            value= self.head.value
            self.head = self.head.pointer
            self.count -= 1
            return value
        else:
            print("Queue is Empty")

    def size(self):
        return self.count

    def peek(self):
        return self.head.value

    def print(self):
        node = self.head
        while node:
            print(node.value, end=" ")
            node = node.pointer
        print()


queue = LinkedQueue()
print("IS Queue Empty? {0}".format(queue.isEmpty()))
print("Add some numbers")
for i in range(10):
    queue.enqueue(i)
print("IS Queue Empty? {0}".format(queue.isEmpty()))
queue.print()

print("Queue size = {0}".format(queue.size()))
print(f'peek = {queue.peek()}')
print(f'pop = {queue.dequeue()}')
print(f'peek = {queue.peek()}')
queue.print()