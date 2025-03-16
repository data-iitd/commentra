
class Main:
    class MainNode:
        def __init__(self, val):
            self.val = val
            self.next = None
            self.prev = None
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    def addFirst(self, val):
        newNode = Main.MainNode(val)
        if self.isEmpty():
            self.head = newNode
            self.tail = newNode
        else:
            newNode.next = self.head
            self.head.prev = newNode
            self.head = newNode
        self.size += 1
    def addLast(self, val):
        newNode = Main.MainNode(val)
        if self.tail == None:
            self.head = newNode
            self.tail = newNode
        else:
            newNode.prev = self.tail
            self.tail.next = newNode
            self.tail = newNode
        self.size += 1
    def pollFirst(self):
        if self.head == None:
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
        if self.tail == None:
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
        return self.head!= None and self.head.val or None
    def peekLast(self):
        return self.tail!= None and self.tail.val or None
    def size(self):
        return self.size
    def isEmpty(self):
        return self.size == 0
    def __str__(self):
        dequeString = "Head -> "
        currNode = self.head
        while currNode!= None:
            dequeString += str(currNode.val)
            if currNode.next!= None:
                dequeString += " <-> "
            currNode = currNode.next
        dequeString += " <- Tail"
        return dequeString

if __name__ == "__main__":
    import sys
    import java.util.NoSuchElementException
    import java.util.Scanner
    scanner = Scanner(sys.stdin)
    deque = Main()
    print("Enter commands (addFirst <value>, addLast <value>, pollFirst, pollLast, peekFirst, peekLast, size, isEmpty, print, exit):")
    while scanner.hasNextLine():
        command = scanner.nextLine().trim()
        if command.equalsIgnoreCase("exit"):
            break
        try:
            parts = command.split(" ")
            if parts[0] == "addFirst":
                addFirstValue = Integer.parseInt(parts[1])
                deque.addFirst(addFirstValue)
                print("Added to front: " + addFirstValue)
            elif parts[0] == "addLast":
                addLastValue = Integer.parseInt(parts[1])
                deque.addLast(addLastValue)
                print("Added to rear: " + addLastValue)
            elif parts[0] == "pollFirst":
                print("Removed from front: " + deque.pollFirst())
            elif parts[0] == "pollLast":
                print("Removed from rear: " + deque.pollLast())
            elif parts[0] == "peekFirst":
                print("Front element: " + deque.peekFirst())
            elif parts[0] == "peekLast":
                print("Rear element: " + deque.peekLast())
            elif parts[0] == "size":
                print("Size: " + deque.size())
            elif parts[0] == "isEmpty":
                print("Is empty: " + deque.isEmpty())
            elif parts[0] == "print":
                print(deque)
            else:
                print("Unknown command: " + parts[0])
        except Exception as e:
            print("Error: " + e.getMessage())
    scanner.close()

