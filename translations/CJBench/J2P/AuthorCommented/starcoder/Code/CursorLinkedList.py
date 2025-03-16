
import java.util.Scanner;
import java.util.Objects;

class Main:
    def __init__(self):
        self.os = 0
        self.count = 0
        self.head = -1
        self.cursorSpace = [None] * 100
        for i in range(100):
            self.cursorSpace[i] = Node(None, i + 1)
        self.cursorSpace[99].next = 0

    def printList(self):
        if self.head!= -1:
            start = self.head
            while start!= -1:
                element = self.cursorSpace[start].element
                print(element, end=" -> ")
                start = self.cursorSpace[start].next
            print("null")

    def indexOf(self, element):
        if element is None:
            raise Exception("Element cannot be null")
        current = self.head
        index = 0
        while current!= -1:
            if Objects.equals(self.cursorSpace[current].element, element):
                return index
            current = self.cursorSpace[current].next
            index += 1
        return -1

    def get(self, position):
        if position >= 0 and position < self.count:
            start = self.head
            counter = 0
            while start!= -1:
                if counter == position:
                    return self.cursorSpace[start].element
                start = self.cursorSpace[start].next
                counter += 1
        return None

    def removeByIndex(self, index):
        if index >= 0 and index < self.count:
            element = self.get(index)
            self.remove(element)

    def remove(self, element):
        if element is None:
            raise Exception("Element cannot be null")
        if self.head == -1:
            return
        if Objects.equals(self.cursorSpace[self.head].element, element):
            self.free(self.head)
            self.head = self.cursorSpace[self.head].next
        else:
            prev = self.head
            current = self.cursorSpace[prev].next
            while current!= -1:
                if Objects.equals(self.cursorSpace[current].element, element):
                    self.cursorSpace[prev].next = self.cursorSpace[current].next
                    self.free(current)
                    break
                prev = current
                current = self.cursorSpace[prev].next
        self.count -= 1

    def alloc(self):
        availableNodeIndex = self.cursorSpace[self.os].next
        if availableNodeIndex == 0:
            raise Exception("Out of memory")
        self.cursorSpace[self.os].next = self.cursorSpace[availableNodeIndex].next
        self.cursorSpace[availableNodeIndex].next = -1
        return availableNodeIndex

    def free(self, index):
        self.cursorSpace[index].element = None
        self.cursorSpace[index].next = self.cursorSpace[self.os].next
        self.cursorSpace[self.os].next = index

    def append(self, element):
        if element is None:
            raise Exception("Element cannot be null")
        availableIndex = self.alloc()
        self.cursorSpace[availableIndex].element = element
        if self.head == -1:
            self.head = availableIndex
        else:
            iterator = self.head
            while self.cursorSpace[iterator].next!= -1:
                iterator = self.cursorSpace[iterator].next
            self.cursorSpace[iterator].next = availableIndex
        self.count += 1

if __name__ == "__main__":
    list = Main()
    scanner = Scanner(System.in)

    print("Enter commands (append <value>, get <index>, removeByIndex <index>, indexOf <value>, print, exit):")
    while scanner.hasNextLine():
        command = scanner.nextLine().trim()

        if command.isEmpty():
            continue

        if command.equalsIgnoreCase("exit"):
            break

        try:
            parts = command.split(" ")
            if parts[0] == "append":
                if len(parts) < 2:
                    print("Error: Missing value for append")
                    break
                list.append(parts[1])
                print("Appended: " + parts[1])
            elif parts[0] == "get":
                if len(parts) < 2:
                    print("Error: Missing index for get")
                    break
                index = Integer.parseInt(parts[1])
                value = list.get(index)
                print("Value at index " + index + ": " + value)
            elif parts[0] == "removeByIndex":
                if len(parts) < 2:
                    print("Error: Missing index for removeByIndex")
                    break
                removeIndex = Integer.parseInt(parts[1])
                list.removeByIndex(removeIndex)
                print("Removed value at index " + removeIndex)
            elif parts[0] == "indexOf":
                if len(parts) < 2:
                    print("Error: Missing value for indexOf")
                    break
                idx = list.indexOf(parts[1])
                print("Index of " + parts[1] + ": " + idx)
            elif parts[0] == "print":
                list.printList()
            else:
                print("Unknown command: " + parts[0])
        except Exception as e:
            print("Error: " + e.getMessage())

    scanner.close()

