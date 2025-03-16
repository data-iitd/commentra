
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def addNode(self, data):
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next
            temp.next = newNode

    def printList(self):
        temp = self.head
        count = 0
        while temp is not None and count < 20:
            print(temp.data, end=" -> ")
            temp = temp.next
            count += 1
        if temp is not None:
            print("... (loop detected)")
        else:
            print("null")

    def createLoop(self, position1, position2):
        if position1 == 0 or position2 == 0:
            return
        node1 = self.head
        node2 = self.head
        count1 = 1
        count2 = 1
        while count1 < position1 and node1 is not None:
            node1 = node1.next
            count1 += 1
        while count2 < position2 and node2 is not None:
            node2 = node2.next
            count2 += 1
        if node1 is not None and node2 is not None:
            node2.next = node1

    def detectLoop(self):
        sptr = self.head
        fptr = self.head
        while fptr is not None and fptr.next is not None:
            sptr = sptr.next
            fptr = fptr.next.next
            if sptr == fptr:
                return True
        return False

if __name__ == "__main__":
    linkedList = LinkedList()
    scanner = input("Enter commands (add <value>, createLoop <pos1> <pos2>, detectLoop, print, exit):\n")
    while scanner != "exit":
        command = scanner.split()
        if len(command) == 0:
            continue
        try:
            if command[0] == "add":
                if len(command) < 2:
                    print("Error: Missing value for add")
                    break
                value = int(command[1])
                linkedList.addNode(value)
                print("Added:", value)
            elif command[0] == "createLoop":
                if len(command) < 3:
                    print("Error: Missing positions for createLoop")
                    break
                pos1 = int(command[1])
                pos2 = int(command[2])
                linkedList.createLoop(pos1, pos2)
                print("Loop created between positions", pos1, "and", pos2)
            elif command[0] == "detectLoop":
                print("Loop detected:", linkedList.detectLoop())
            elif command[0] == "print":
                linkedList.printList()
            else:
                print("Unknown command:", command[0])
        except Exception as e:
            print("Error:", e)
        scanner = input()
    print("