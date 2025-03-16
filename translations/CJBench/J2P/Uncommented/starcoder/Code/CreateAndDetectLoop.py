
import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

head = None

def addNode(data):
    newNode = Node(data)
    if head == None:
        head = newNode
    else:
        temp = head
        while temp.next!= None:
            temp = temp.next
        temp.next = newNode

def printList():
    temp = head
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

def createLoop(position1, position2):
    if position1 == 0 or position2 == 0:
        return
    node1 = head
    node2 = head
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

def detectLoop():
    sptr = head
    fptr = head
    while fptr!= None and fptr.next!= None:
        sptr = sptr.next
        fptr = fptr.next.next
        if sptr == fptr:
            return True
    return False

def main():
    while True:
        command = input("Enter commands (add <value>, createLoop <pos1> <pos2>, detectLoop, print, exit): ")
        if command.strip() == "":
            continue
        if command.strip().lower() == "exit":
            break
        parts = command.split(" ")
        if parts[0].strip().lower() == "add":
            if len(parts) < 2:
                print("Error: Missing value for add")
                continue
            value = int(parts[1])
            addNode(value)
            print("Added: " + str(value))
        elif parts[0].strip().lower() == "createLoop":
            if len(parts) < 3:
                print("Error: Missing positions for createLoop")
                continue
            pos1 = int(parts[1])
            pos2 = int(parts[2])
            createLoop(pos1, pos2)
            print("Loop created between positions " + str(pos1) + " and " + str(pos2))
        elif parts[0].strip().lower() == "detectLoop":
            print("Loop detected: " + str(detectLoop()))
        elif parts[0].strip().lower() == "print":
            printList()
        else:
            print("Unknown command: " + parts[0])

if __name__ == "__main__":
    main()

# 