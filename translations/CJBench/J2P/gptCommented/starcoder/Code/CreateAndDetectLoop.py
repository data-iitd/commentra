import sys

# Node class representing each element in the linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# Head of the linked list
head = None

# Method to add a new node with the specified data to the end of the list
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


# Method to print the linked list up to 20 nodes or indicate a loop
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
    print()


# Method to create a loop in the linked list between two specified positions
def createLoop(position1, position2):
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


# Method to detect if there is a loop in the linked list using Floyd's cycle-finding algorithm
def detectLoop():
    sptr = head
    fptr = head
    while fptr is not None and fptr.next is not None:
        sptr = sptr.next
        fptr = fptr.next.next
        if sptr == fptr:
            return True
    return False


# Main method to execute the program
def main():
    scanner = sys.stdin
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
                addNode(value)
                print("Added: " + str(value))
            elif parts[0].strip().lower() == "createloop":
                if len(parts) < 3:
                    print("Error: Missing positions for createLoop")
                    continue
                pos1 = int(parts[1])
                pos2 = int(parts[2])
                createLoop(pos1, pos2)
                print("Loop created between positions " + str(pos1) + " and " + str(pos2))
            elif parts[0].strip().lower() == "detectloop":
                print("Loop detected: " + str(detectLoop()))
            elif parts[0].strip().lower() == "print":
                printList()
            else:
                print("Unknown command: " + parts[0])
        except Exception as e:
            print("Error: " + str(e))
    scanner.close()


if __name__ == "__main__":
    main()

