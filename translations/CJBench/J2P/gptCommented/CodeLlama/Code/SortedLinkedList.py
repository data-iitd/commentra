
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class Main:
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
            while temp.next != None and temp.next.value < value:
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
            while temp.next != None:
                if temp.next.value == value:
                    if temp.next == self.tail:
                        self.tail = temp
                    temp.next = temp.next.next
                    return True
                temp = temp.next
            return False

    def search(self, value):
        temp = self.head
        while temp != None:
            if temp.value == value:
                return True
            temp = temp.next
        return False

    def isEmpty(self):
        return self.head == None

    def __str__(self):
        if self.head != None:
            sb = "["
            temp = self.head
            while temp != None:
                sb += str(temp.value)
                if temp.next != None:
                    sb += ", "
                temp = temp.next
            sb += "]"
            return sb
        else:
            return "[]"

def main():
    list = Main()
    while True:
        command = input("Enter command: ").strip()
        if command == "":
            continue
        if command == "exit":
            break
        try:
            parts = command.split(" ")
            if parts[0] == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                    continue
                insertValue = int(parts[1])
                list.insert(insertValue)
                print("Inserted: " + str(insertValue))
            elif parts[0] == "delete":
                if len(parts) < 2:
                    print("Error: Missing value for delete")
                    continue
                deleteValue = int(parts[1])
                deleted = list.delete(deleteValue)
                print(str(deleted) + " " + str(deleteValue))
            elif parts[0] == "search":
                if len(parts) < 2:
                    print("Error: Missing value for search")
                    continue
                searchValue = int(parts[1])
                found = list.search(searchValue)
                print(str(found) + " " + str(searchValue))
            elif parts[0] == "isEmpty":
                print("Is empty: " + str(list.isEmpty()))
            elif parts[0] == "print":
                print("List: " + str(list))
            else:
                print("Error: Unknown command")
        except Exception as e:
            print("Error: " + str(e))

if __name__ == "__main__":
    main()

