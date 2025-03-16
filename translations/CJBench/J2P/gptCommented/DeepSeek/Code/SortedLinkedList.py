class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class Main:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        elif value < self.head.value:
            new_node.next = self.head
            self.head = new_node
        elif value > self.tail.value:
            self.tail.next = new_node
            self.tail = new_node
        else:
            temp = self.head
            while temp.next is not None and temp.next.value < value:
                temp = temp.next
            new_node.next = temp.next
            temp.next = new_node
            if new_node.next is None:
                self.tail = new_node

    def delete(self, value):
        if self.head is None:
            return False
        if self.head.value == value:
            if self.head.next is None:
                self.head = None
                self.tail = None
            else:
                self.head = self.head.next
            return True
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
            values = []
            temp = self.head
            while temp is not None:
                values.append(str(temp.value))
                temp = temp.next
            return ", ".join(values)
        else:
            return "[]"

if __name__ == "__main__":
    linked_list = Main()
    while True:
        command = input().strip()
        if command == "":
            continue
        if command.lower() == "exit":
            break
        parts = command.split()
        if parts[0].lower() == "insert":
            if len(parts) < 2:
                print("Error: Missing value for insert")
                continue
            value = int(parts[1])
            linked_list.insert(value)
            print(f"Inserted: {value}")
        elif parts[0].lower() == "delete":
            if len(parts) < 2:
                print("Error: Missing value for delete")
                continue
            value = int(parts[1])
            deleted = linked_list.delete(value)
            print(f"Deleted: {'Yes' if deleted else 'No'}")
        elif parts[0].lower() == "search":
            if len(parts) < 2:
                print("Error: Missing value for search")
                continue
            value = int(parts[1])
            found = linked_list.search(value)
            print(f"Found: {'Yes' if found else 'No'}")
        elif parts[0].lower() == "isempty":
            print(f"Is empty: {'Yes' if linked_list.is_empty() else 'No'}")
        elif parts[0].lower() == "print":
            print(f"List: {linked_list}")
