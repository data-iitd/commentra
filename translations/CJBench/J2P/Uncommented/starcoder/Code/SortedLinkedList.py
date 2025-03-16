
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, value):
        newNode = Node(value)
        if self.head == None:
            self.head = newNode
            self.tail = newNode
        elif value < self.head.value:
            newNode.next = self.head
            self.head = newNode
        elif value > self.tail.value:
            self.tail.next = newNode
            self.tail = newNode
        else:
            temp = self.head
            while temp.next!= None and temp.next.value < value:
                temp = temp.next
            newNode.next = temp.next
            temp.next = newNode
            if newNode.next == None:
                self.tail = newNode

    def delete(self, value):
        if self.head == None:
            return False
        elif self.head.value == value:
            if self.head.next == None:
                self.head = None
                self.tail = None
            else:
                self.head = self.head.next
            return True
        else:
            temp = self.head
            while temp.next!= None:
                if temp.next.value == value:
                    if temp.next == self.tail:
                        self.tail = temp
                    temp.next = temp.next.next
                    return True
                temp = temp.next
            return False

    def search(self, value):
        temp = self.head
        while temp!= None:
            if temp.value == value:
                return True
            temp = temp.next
        return False

    def isEmpty(self):
        return self.head == None

    def __str__(self):
        if self.head!= None:
            sb = "["
            temp = self.head
            while temp!= None:
                sb += str(temp.value)
                if temp.next!= None:
                    sb += ", "
                temp = temp.next
            sb += "]"
            return sb
        else:
            return "[]"

if __name__ == "__main__":
    list = LinkedList()
    while True:
        command = input("Enter commands (insert <value>, delete <value>, search <value>, isEmpty, print, exit): ").strip()
        if command.isEmpty():
            continue
        if command.equalsIgnoreCase("exit"):
            break
        try:
            parts = command.split(" ")
            if parts[0] == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                    break
                list.insert(int(parts[1]))
                print("Inserted: " + parts[1])
            elif parts[0] == "delete":
                if len(parts) < 2:
                    print("Error: Missing value for delete")
                    break
                list.delete(int(parts[1]))
                print("Deleted: " + parts[1])
            elif parts[0] == "search":
                if len(parts) < 2:
                    print("Error: Missing value for search")
                    break
                list.search(int(parts[1]))
                print("Found: " + parts[1])
            elif parts[0] == "isEmpty":
                print("Is empty: " + list.isEmpty())
            elif parts[0] == "print":
                print("List: " + list)
            else:
                print("Unknown command: " + parts[0])
        except Exception as e:
            print("Error: " + e.getMessage())

