class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Main:
    head = None

    @staticmethod
    def addNode(data):
        newNode = Node(data)
        if Main.head is None:
            Main.head = newNode
        else:
            temp = Main.head
            while temp.next is not None:
                temp = temp.next
            temp.next = newNode

    @staticmethod
    def printList():
        temp = Main.head
        count = 0
        while temp is not None and count < 20:
            print(temp.data, end=" -> ")
            temp = temp.next
            count += 1
        if temp is not None:
            print("... (loop detected)", end="")
        else:
            print("null", end="")
        print()

    @staticmethod
    def createLoop(position1, position2):
        if position1 == 0 or position2 == 0:
            return

        node1 = Main.head
        node2 = Main.head

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

    @staticmethod
    def detectLoop():
        sptr = Main.head
        fptr = Main.head

        while fptr is not None and fptr.next is not None:
            sptr = sptr.next
            fptr = fptr.next.next
            if sptr == fptr:
                return True
        return False

# Main class for command-line interaction
class CommandLineInterface:
    @staticmethod
    def main():
        while True:
            command = input("Enter commands (add <value>, createLoop <pos1> <pos2>, detectLoop, print, exit):").strip()

            if command == "":
                continue

            if command.lower() == "exit":
                break

            parts = command.split()
            try:
                if parts[0].lower() == "add":
                    if len(parts) < 2:
                        print("Error: Missing value for add")
                        continue
                    value = int(parts[1])
                    Main.addNode(value)
                    print(f"Added: {value}")
                elif parts[0].lower() == "createLoop":
                    if len(parts) < 3:
                        print("Error: Missing positions for createLoop")
                        continue
                    pos1 = int(parts[1])
                    pos2 = int(parts[2])
                    Main.createLoop(pos1, pos2)
                    print(f"Loop created between positions {pos1} and {pos2}")
                elif parts[0].lower() == "detectLoop":
                    print("Loop detected:", Main.detectLoop())
                elif parts[0].lower() == "print":
                    Main.printList()
                else:
                    print(f"Unknown command: {parts[0]}")
            except Exception as e:
                print(f"Error: {e}")

CommandLineInterface.main()
