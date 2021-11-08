class ListNode():
  def __init__(self, value):
    self.value = value
    self.next = None

def printAll(node:ListNode):
  tmp_node = node
  while tmp_node is not None:
    print(tmp_node.value, end=" ")
    tmp_node = tmp_node.next

def recursiveMode(node: ListNode):
  print(node.value, end= " ")
  if node.next is not None:
    recursiveMode(node.next)


head_node = ListNode(1)
head_node.next = ListNode(2)
head_node.next.next = ListNode(3)
head_node.next.next.next = ListNode(4)
printAll(head_node)
recursiveMode(head_node)
