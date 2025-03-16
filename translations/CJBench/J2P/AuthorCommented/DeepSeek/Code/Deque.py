class MainNode:
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
        newNode = MainNode(val)
        if self.isEmpty():
            self.head = newNode
            self.tail = newNode
        else:
            newNode.next = self.head
            self.head.prev = newNode
            self.head = newNode
        self.size += 1

    def addLast(self, val):
        newNode = MainNode(val)
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
            raise Exception("Main is empty")
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
            raise Exception("Main is empty")
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
        dequeString = "Head -> "
        currNode = self.head
        while currNode is not None:
            dequeString += str(currNode.val)
            if currNode.next is not None:
                dequeString += " <-> "
            currNode = currNode.next
        dequeString += " <- Tail"
        return dequeString


def main():
    deque = Main()
    print("Enter commands (addFirst <value>, addLast <value>, pollFirst, pollLast, peekFirst, peekLast, size, isEmpty, print, exit):")
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break
        parts = command.split()
        try:
            if parts[0].lower() == "addFirst":
                value = int(parts[1])
                deque.addFirst(value)
                print(f"Added to front: {value}")
            elif parts[0].lower() == "addLast":
                value = int(parts[1])
                deque.addLast(value)
                print(f"Added to rear: {value}")
            elif parts[0].lower() == "pollFirst":
                print(f"Removed from front: {deque.pollFirst()}")
            elif parts[0].lower() == "pollLast":
                print(f"Removed from rear: {deque.pollLast()}")
            elif parts[0].lower() == "peekFirst":
                print(f"Front element: {deque.peekFirst()}")
            elif parts[0].lower() == "peekLast":
                print(f"Rear element: {deque.peekLast()}")
            elif parts[0].lower() == "size":
                print(f"Size: {deque.size()}")
            elif parts[0].lower() == "isEmpty":
                print(f"Is empty: {deque.isEmpty()}")
            elif parts[0].lower() == "print":
                print(deque)
            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")


main()
