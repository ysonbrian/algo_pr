class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}
class LinkedList {
  constructor(value) {
    (this.head = {
      value: value,
      next: null,
    }),
      (this.tail = this.head);
    this.length = 1;
  }
  append(value) {
    const newNode = new Node(value);
    this.tail.next = newNode;
    this.tail = newNode;
    this.length++;
    console.log(this.tail.value);
    return this;
  }
  prepend(value) {
    const newNode = new Node(value);
    newNode.next = this.head;
    this.head = newNode;
    this.length++;
  }

  insert(index, value) {
    if (index >= this.length) {
      return this.append(value);
    }
    const newNode = new Node(value);
    const leader = this.traverseToIndex(index - 1);
    const holdingPointer = leader.next;
    leader.next = newNode;
    newNode.next = holdingPointer;
    this.length++;
    return this.retrive();
  }
  traverseToIndex(index) {
    let counter = 0;
    let currentNode = this.head;
    while (counter !== index) {
      currentNode = currentNode.next;
      counter++;
    }
    return currentNode;
  }

  remove(index) {
    if (index >= this.length) {
      return null;
    }
    if (index === 0) {
      this.head = this.head.next;
      return this.retrive();
    }
    const leader = this.traverseToIndex(index - 1);
    const unwantedNode = leader.next;
    leader.next = unwantedNode.next;
    this.length--;
    return this.retrive();
  }

  retrive() {
    const array = [];
    let head = this.head;

    while (head !== null) {
      array.push(head.value);
      head = head.next;
    }
    console.log(array);
  }
}

const myLinkedList = new LinkedList(10);

myLinkedList.append(5);
myLinkedList.append(16);
myLinkedList.append(20);
myLinkedList.prepend(100);
myLinkedList.insert(2, 200);
myLinkedList.insert(5, 200);
myLinkedList.remove(5);
myLinkedList.remove(0);
myLinkedList.retrive();
myLinkedList.retrive();
