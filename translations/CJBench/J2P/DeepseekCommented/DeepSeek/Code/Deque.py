class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None

class Main:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def addFirst(self, val):
        newNode = Node(val)
        if self.isEmpty():
            self.head = newNode
            self.tail = newNode
        else:
            newNode.next = self.head
            self.head.prev = newNode
            self.head = newNode
        self.size += 1

    def addLast(self, val):
        newNode = Node(val)
        if self.tail is None:
            self.head = newNode
            self.tail = newNode
        else:
            newNode.prev = self.tail
            self.tail.next = newNode
            self.tail = newNode
        self.size += 1

    def pollFirst(self):
        if self.head is None:
            raise NoSuchElementException("Main is empty")
        oldHeadVal = self.head.val
        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
        self.size -= 1
        return oldHeadVal

    def pollLast(self):
        if self.tail is None:
            raise NoSuchElementException("Main is empty")
        oldTailVal = self.tail.val
        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        self.size -= 1
        return oldTailVal

    def peekFirst(self):
        return self.head.val if self.head is not None else None

    def peekLast(self):
        return self.tail.val if self.tail is not None else None

    def size(self):
        return self.size

    def isEmpty(self):
        return self.size == 0

    def __str__(self):
        dequeString = ["Head -> "]
        currNode = self.head
        while currNode is not None:
            dequeString.append(str(currNode.val))
            if currNode.next is not None:
                dequeString.append(" <-> ")
            currNode = currNode.next
        dequeString.append(" <- Tail")
        return ''.join(dequeString)

def main():
    deque = Main()
    while True:
        command = input().strip()
        if command == "exit":
            break
        try:
            parts = command.split()
            if parts[0] == "addFirst":
                addFirstValue = int(parts[1])
                deque.addFirst(addFirstValue)
                print(f"Added to front: {addFirstValue}")
            elif parts[0] == "addLast":
                addLastValue = int(parts[1])
                deque.addLast(addLastValue)
                print(f"Added to rear: {addLastValue}")
            elif parts[0] == "pollFirst":
                print(f"Removed from front: {deque.pollFirst()}")
            elif parts[0] == "pollLast":
                print(f"Removed from rear: {deque.pollLast()}")
            elif parts[0] == "peekFirst":
                print(f"Front element: {deque.peekFirst()}")
            elif parts[0] == "peekLast":
                print(f"Rear element: {deque.peekLast()}")
            elif parts[0] == "size":
                print(f"Size: {deque.size()}")
            elif parts[0] == "isEmpty":
                print(f"Is empty: {deque.isEmpty()}")
            elif parts[0] == "print":
                print(deque)
            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    main()
