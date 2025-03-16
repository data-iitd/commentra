class Node:
    def __init__(self, element, next):
        self.element = element
        self.next = next


class Main:
    def __init__(self):
        self.os = 0
        self.head = -1
        self.cursor_space = [Node(None, i + 1) for i in range(100)]
        self.cursor_space[-1].next = 0
        self.count = 0

    def print_list(self):
        if self.head != -1:
            start = self.head
            while start != -1:
                element = self.cursor_space[start].element
                print(element, "->", end=" ")
                start = self.cursor_space[start].next
        print("null")

    def index_of(self, element):
        if element is None:
            raise ValueError("Element cannot be None")
        current = self.head
        index = 0
        while current != -1:
            if self.cursor_space[current].element == element:
                return index
            current = self.cursor_space[current].next
            index += 1
        return -1

    def get(self, position):
        if 0 <= position < self.count:
            start = self.head
            counter = 0
            while start != -1:
                if counter == position:
                    return self.cursor_space[start].element
                start = self.cursor_space[start].next
                counter += 1
        return None

    def remove_by_index(self, index):
        if 0 <= index < self.count:
            element = self.get(index)
            self.remove(element)

    def remove(self, element):
        if element is None:
            raise ValueError("Element cannot be None")
        if self.head == -1:
            return

        if self.cursor_space[self.head].element == element:
            self.free(self.head)
            self.head = self.cursor_space[self.head].next
        else:
            prev = self.head
            current = self.cursor_space[prev].next

            while current != -1:
                if self.cursor_space[current].element == element:
                    self.cursor_space[prev].next = self.cursor_space[current].next
                    self.free(current)
                    break
                prev = current
                current = self.cursor_space[prev].next
        self.count -= 1

    def alloc(self):
        available_node_index = self.cursor_space[self.os].next
        if available_node_index == 0:
            raise MemoryError()
        self.cursor_space[self.os].next = self.cursor_space[available_node_index].next
        self.cursor_space[available_node_index].next = -1
        return available_node_index

    def free(self, index):
        self.cursor_space[index].element = None
        self.cursor_space[index].next = self.cursor_space[self.os].next
        self.cursor_space[self.os].next = index

    def append(self, element):
        if element is None:
            raise ValueError("Element cannot be None")
        available_index = self.alloc()
        self.cursor_space[available_index].element = element

        if self.head == -1:
            self.head = available_index
        else:
            iterator = self.head
            while self.cursor_space[iterator].next != -1:
                iterator = self.cursor_space[iterator].next
            self.cursor_space[iterator].next = available_index
        self.count += 1


if __name__ == "__main__":
    list_instance = Main()
    while True:
        command = input("Enter command (append <value>, get <index>, removeByIndex <index>, indexOf <value>, print, exit): ").strip()
        if command == "":
            continue
        if command.lower() == "exit":
            break
        parts = command.split()
        try:
            if parts[0].lower() == "append":
                if len(parts) < 2:
                    print("Error: Missing value for append")
                else:
                    list_instance.append(parts[1])
                    print("Appended:", parts[1])
            elif parts[0].lower() == "get":
                if len(parts) < 2:
                    print("Error: Missing index for get")
                else:
                    index = int(parts[1])
                    value = list_instance.get(index)
                    print("Value at index", index, ":", value)
            elif parts[0].lower() == "removebyindex":
                if len(parts) < 2:
                    print("Error: Missing index for removeByIndex")
                else:
                    index = int(parts[1])
                    list_instance.remove_by_index(index)
                    print("Removed value at index", index)
            elif parts[0].lower() == "indexof":
                if len(parts) < 2:
                    print("Error: Missing value for indexOf")
                else:
                    value = parts[1]
                    idx = list_instance.index_of(value)
                    print("Index of", value, ":", idx)
            elif parts[0].lower() == "print":
                list_instance.print_list()
            else:
                print("Unknown command:", parts[0])
        except Exception as e:
            print("Error:", str(e))
