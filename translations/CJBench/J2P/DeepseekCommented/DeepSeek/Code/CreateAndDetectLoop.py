class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

head = None

def addNode(data):
    global head
    newNode = Node(data)
    if head is None:
        head = newNode
    else:
        temp = head
        while temp.next is not None:
            temp = temp.next
        temp.next = newNode

def printList():
    global head
    temp = head
    count = 0
    while temp is not None and count < 20:
        print(temp.data, end=" -> ")
        temp = temp.next
        count += 1
    if temp is not None:
        print("... (loop detected)")
    else:
        print("null")

def createLoop(position1, position2):
    global head
    if position1 == 0 or position2 == 0:
        return
    node1 = head
    node2 = head
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

def detectLoop():
    global head
    sptr = head
    fptr = head
    while fptr is not None and fptr.next is not None:
        sptr = sptr.next
        fptr = fptr.next.next
        if sptr == fptr:
            return True
    return False

def main():
    while True:
        command = input().strip()
        if not command:
            continue
        if command.lower() == "exit":
            break
        parts = command.split()
        if parts[0].lower() == "add":
            if len(parts) < 2:
                print("Error: Missing value for add")
                continue
            value = int(parts[1])
            addNode(value)
            print("Added:", value)
        elif parts[0].lower() == "createloop":
            if len(parts) < 3:
                print("Error: Missing positions for createLoop")
                continue
            pos1 = int(parts[1])
            pos2 = int(parts[2])
            createLoop(pos1, pos2)
            print("Loop created between positions", pos1, "and", pos2)
        elif parts[0].lower() == "detectloop":
            print("Loop detected:", detectLoop())
        elif parts[0].lower() == "print":
            printList()
        else:
            print("Unknown command:", parts[0])

if __name__ == "__main__":
    main()
