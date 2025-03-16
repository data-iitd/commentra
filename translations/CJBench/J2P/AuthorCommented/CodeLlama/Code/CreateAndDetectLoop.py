
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Main:
    def __init__(self):
        raise Exception("Utility class")

    @staticmethod
    def add_node(data):
        new_node = Node(data)
        if Main.head is None:
            Main.head = new_node
        else:
            temp = Main.head
            while temp.next is not None:
                temp = temp.next
            temp.next = new_node

    @staticmethod
    def print_list():
        temp = Main.head
        count = 0
        while temp is not None and count < 20:
            print(temp.data, end=" -> ")
            temp = temp.next
            count += 1
        if temp is not None:
            print("... (loop detected)")
        else:
            print("null")

    @staticmethod
    def create_loop(position1, position2):
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
    def detect_loop():
        sptr = Main.head
        fptr = Main.head

        while fptr is not None and fptr.next is not None:
            sptr = sptr.next
            fptr = fptr.next.next
            if sptr == fptr:
                return True

        return False

    @staticmethod
    def main():
        while True:
            command = input("Enter commands (add <value>, createLoop <pos1> <pos2>, detectLoop, print, exit):")
            if command.strip() == "":
                continue

            if command.strip().lower() == "exit":
                break

            try:
                parts = command.split()
                if parts[0].strip().lower() == "add":
                    if len(parts) < 2:
                        print("Error: Missing value for add")
                        continue
                    value = int(parts[1])
                    Main.add_node(value)
                    print("Added: " + str(value))
                elif parts[0].strip().lower() == "createLoop":
                    if len(parts) < 3:
                        print("Error: Missing positions for createLoop")
                        continue
                    pos1 = int(parts[1])
                    pos2 = int(parts[2])
                    Main.create_loop(pos1, pos2)
                    print("Loop created between positions " + str(pos1) + " and " + str(pos2))
                elif parts[0].strip().lower() == "detectLoop":
                    print("Loop detected: " + str(Main.detect_loop()))
                elif parts[0].strip().lower() == "print":
                    Main.print_list()
                else:
                    print("Unknown command: " + parts[0])
            except Exception as e:
                print("Error: " + str(e))

        print("Exiting...")

if __name__ == "__main__":
    Main.main()
    print("