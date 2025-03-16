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
        result = "Head -> "
        currNode = self.head
        while currNode is not None:
            result += str(currNode.val)
            if currNode.next is not None:
                result += " <-> "
            currNode = currNode.next
        result += " <- Tail"
        return result

# Main class to run the deque operations based on user input
class Main:
    def __init__(self):
        self.deque = Main()
        self.scanner = Scanner(System.in)

    def run(self):
        while self.scanner.hasNextLine():
            command = self.scanner.nextLine().strip()
            if command == "exit":
                break
            try:
                parts = command.split()
                if parts[0] == "addFirst":
                    value = int(parts[1])
                    self.deque.addFirst(value)
                    print("Added to front: " + value)
                elif parts[0] == "addLast":
                    value = int(parts[1])
                    self.deque.addLast(value)
                    print("Added to rear: " + value)
                elif parts[0] == "pollFirst":
                    print("Removed from front: " + self.deque.pollFirst())
                elif parts[0] == "pollLast":
                    print("Removed from rear: " + self.deque.pollLast())
                elif parts[0] == "peekFirst":
                    print("Front element: " + self.deque.peekFirst())
                elif parts[0] == "peekLast":
                    print("Rear element: " + self.deque.peekLast())
                elif parts[0] == "size":
                    print("Size: " + self.deque.size())
                elif parts[0] == "isEmpty":
                    print("Is empty: " + self.deque.isEmpty())
                elif parts[0] == "print":
                    print(self.deque)
                else:
                    print("Unknown command: " + parts[0])
            except Exception as e:
                print("Error: " + str(e))
        self.scanner.close()

# Create an instance of Main and run it
main = Main()
main.run()
