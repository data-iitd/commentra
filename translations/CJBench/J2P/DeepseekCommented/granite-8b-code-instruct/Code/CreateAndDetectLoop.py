
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

head = None

def add_node(data):
    global head
    new_node = Node(data)
    if head is None:
        head = new_node
    else:
        temp = head
        while temp.next is not None:
            temp = temp.next
        temp.next = new_node

def print_list():
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

def create_loop(position1, position2):
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

def detect_loop():
    sptr = head
    fptr = head
    while fptr is not None and fptr.next is not None:
        sptr = sptr.next
        fptr = fptr.next.next
        if sptr == fptr:
            return True
    return False

while True:
    command = input().strip()
    if command == "exit":
        break
    try:
        parts = command.split()
        if parts[0] == "add":
            if len(parts) < 2:
                print("Error: Missing value for add")
            else:
                value = int(parts[1])
                add_node(value)
                print("Added:", value)
        elif parts[0] == "createLoop":
            if len(parts) < 3:
                print("Error: Missing positions for createLoop")
            else:
                pos1 = int(parts[1])
                pos2 = int(parts[2])
                create_loop(pos1, pos2)
                print("Loop created between positions", pos1, "and", pos2)
        elif parts[0] == "detectLoop":
            print("Loop detected:", detect_loop())
        elif parts[0] == "print":
            print_list()
        else:
            print("Unknown command:", parts[0])
    except Exception as e:
        print("Error:", e)

