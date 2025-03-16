
import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Main:
    head = None

    def addNode(self, data):
        newNode = Node(data)
        if self.head == None:
            self.head = newNode
        else:
            temp = self.head
            while temp.next!= None:
                temp = temp.next
            temp.next = newNode

    def printList(self):
        temp = self.head
        count = 0
        while temp!= None and count < 20:
            print(temp.data, end=" -> ")
            temp = temp.next
            count += 1
        if temp!= None:
            print("... (loop detected)")
        else:
            print("null")
        print()

    def createLoop(self, position1, position2):
        if position1 == 0 or position2 == 0:
            return

        node1 = self.head
        node2 = self.head

        count1 = 1
        count2 = 1

        while count1 < position1 and node1!= None:
            node1 = node1.next
            count1 += 1

        while count2 < position2 and node2!= None:
            node2 = node2.next
            count2 += 1

        if node1!= None and node2!= None:
            node2.next = node1

    def detectLoop(self):
        sptr = self.head
        fptr = self.head

        while fptr!= None and fptr.next!= None:
            sptr = sptr.next
            fptr = fptr.next.next
            if sptr == fptr:
                return True
        return False

if __name__ == "__main__":
    main = Main()
    scanner = sys.stdin
    print("Enter commands (add <value>, createLoop <pos1> <pos2>, detectLoop, print, exit):")

    while True:
        command = scanner.readline().strip()

        if command.strip() == "":
            continue

        if command.strip().lower() == "exit":
            break

        try:
            parts = command.split(" ")
            if parts[0].strip().lower() == "add":
                if len(parts) < 2:
                    print("Error: Missing value for add")
                    continue
                value = int(parts[1])
                main.addNode(value)
                print("Added: " + str(value))
            elif parts[0].strip().lower() == "createLoop":
                if len(parts) < 3:
                    print("Error: Missing positions for createLoop")
                    continue
                pos1 = int(parts[1])
                pos2 = int(parts[2])
                main.createLoop(pos1, pos2)
                print("Loop created between positions " + str(pos1) + " and " + str(pos2))
            elif parts[0].strip().lower() == "detectLoop":
                print("Loop detected: " + str(main.detectLoop()))
            elif parts[0].strip().lower() == "print":
                main.printList()
            else:
                print("Unknown command: " + parts[0])
        except Exception as e:
            print("Error: " + str(e))

    scanner.close()

