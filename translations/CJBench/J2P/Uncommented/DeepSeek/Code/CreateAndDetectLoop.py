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

def main():
    linked_list = LinkedList()
    print("Enter commands (add <value>, createLoop <pos1> <pos2>, detectLoop, print, exit):")
    while True:
        command = input().strip()
        if command == "":
            continue
        if command.lower() == "exit":
            break
        parts = command.split()
        if parts[0].lower() == "add":
            if len(parts) < 2:
                print("Error: Missing value for add")
                continue
            value = int(parts[1])
            linked_list.addNode(value)
            print("Added:", value)
        elif parts[0].lower() == "createLoop":
            if len(parts) < 3:
                print("Error: Missing positions for createLoop")
                continue
            pos1 = int(parts[1])
            pos2 = int(parts[2])
            linked_list.createLoop(pos1, pos2)
            print("Loop created between positions", pos1, "and", pos2)
        elif parts[0].lower() == "detectLoop":
            print("Loop detected:", linked_list.detectLoop())
        elif parts[0].lower() == "print":
            linked_list.printList()
        else:
            print("Unknown command:", parts[0])

if __name__ == "__main__":
    main()

