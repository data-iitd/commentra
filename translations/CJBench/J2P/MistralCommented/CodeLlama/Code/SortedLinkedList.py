
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
        else:
            if value < self.head.value:
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

        if self.head.value == value:
            if self.head.next == None:
                self.head = None
                self.tail = None
            else:
                self.head = self.head.next
            return True

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
    scanner = input("Enter a command: ")

    while scanner != "exit":
        command = scanner.split(" ")
        operation = command[0]

        if operation == "insert":
            if len(command) < 2:
                print("Error: Missing value for insert")
            else:
                insertValue = int(command[1])
                list.insert(insertValue)
                print("Inserted: " + str(insertValue))
        elif operation == "delete":
            if len(command) < 2:
                print("Error: Missing value for delete")
            else:
                deleteValue = int(command[1])
                deleted = list.delete(deleteValue)
                print(deleted and "Deleted: " + str(deleteValue) or "Value not found: " + str(deleteValue))
        elif operation == "search":
            if len(command) < 2:
                print("Error: Missing value for search")
            else:
                searchValue = int(command[1])
                found = list.search(searchValue)
                print(found and "Found: " + str(searchValue) or "Not found: " + str(searchValue))
        elif operation == "isEmpty":
            print("Is empty: " + str(list.isEmpty()))
        elif operation == "print":
            print("List: " + str(list))
        else:
            print("Error: Unknown operation")

        scanner = input("Enter a command: ")

if __name__ == "__main__":
    main()

