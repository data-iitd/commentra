

class Main:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, value):
        newNode = Node(value)
        if self.head is None:
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
            while temp.next is not None and temp.next.value < value:
                temp = temp.next
            newNode.next = temp.next
            temp.next = newNode
            if newNode.next is None:
                self.tail = newNode

    def delete(self, value):
        if self.head is None:
            return False
        elif self.head.value == value:
            if self.head.next is None:
                self.head = None
                self.tail = None
            else:
                self.head = self.head.next
            return True
        else:
            temp = self.head
            while temp.next is not None:
                if temp.next.value == value:
                    if temp.next == self.tail:
                        self.tail = temp
                    temp.next = temp.next.next
                    return True
                temp = temp.next
            return False

    def search(self, value):
        temp = self.head
        while temp is not None:
            if temp.value == value:
                return True
            temp = temp.next
        return False

    def is_empty(self):
        return self.head is None

    def __str__(self):
        if self.head is not None:
            result = "["
            temp = self.head
            while temp is not None:
                result += str(temp.value)
                if temp.next is not None:
                    result += ", "
                temp = temp.next
            result += "]"
            return result
        else:
            return "[]"

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

if __name__ == "__main__":
    list = Main()
    commands = ["insert 10", "insert 5", "insert 20", "isEmpty", "print", "exit"]

    for command in commands:
        parts = command.split(" ")
        if len(parts) == 0:
            continue
        elif parts[0].lower() == "exit":
            break
        try:
            if parts[0].lower() == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                    continue
                insert_value = int(parts[1])
                list.insert(insert_value)
                print("Inserted: " + str(insert_value))
            elif parts[0].lower() == "delete":
                if len(parts) < 2:
                    print("Error: Missing value for delete")
                    continue
                delete_value = int(parts[1])
                deleted = list.delete(delete_value)
                print("Deleted: " + str(delete_value) if deleted else "Value not found: " + str(delete_value))
            elif parts[0].lower() == "search":
                if len(parts) < 2:
                    print("Error: Missing value for search")
                    continue
                search_value = int(parts[1])
                found = list.search(search_value)
                print("Found: " + str(search_value) if found else "Not found: " + str(search_value))
            elif parts[0].lower() == "is_empty":
                print("Is empty: " + str(list.is_empty()))
            elif parts[0].lower() == "print":
                print("List: " + list.__str__())
            else:
                print("Unknown command: " + parts[0])
        except Exception as e:
            print("Error: " + str(e))

