class Node:
    def __init__(self, element, next_index):
        self.element = element
        self.next = next_index

class Main:
    CURSOR_SPACE_SIZE = 100

    def __init__(self):
        self.os = 0
        self.head = -1
        self.cursor_space = [Node(None, i + 1) for i in range(self.CURSOR_SPACE_SIZE)]
        self.cursor_space[self.CURSOR_SPACE_SIZE - 1].next = 0
        self.count = 0

    def print_list(self):
        if self.head != -1:
            start = self.head
            while start != -1:
                element = self.cursor_space[start].element
                print(f"{element} -> ", end="")
                start = self.cursor_space[start].next
        print("null")

    def index_of(self, element):
        if element is None:
            raise ValueError("Element cannot be null")
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
            raise ValueError("Element cannot be null")
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
            raise MemoryError("Out of memory")
        self.cursor_space[self.os].next = self.cursor_space[available_node_index].next
        self.cursor_space[available_node_index].next = -1
        return available_node_index

    def free(self, index):
        self.cursor_space[index].element = None
        self.cursor_space[index].next = self.cursor_space[self.os].next
        self.cursor_space[self.os].next = index

    def append(self, element):
        if element is None:
            raise ValueError("Element cannot be null")
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
    print("Enter commands (append <value>, get <index>, removeByIndex <index>, indexOf <value>, print, exit):")
    while True:
        command = input().strip()
        if not command:
            continue
        if command.lower() == "exit":
            break
        try:
            parts = command.split()
            if parts[0] == "append":
                if len(parts) < 2:
                    print("Error: Missing value for append")
                    continue
                list_instance.append(parts[1])
                print(f"Appended: {parts[1]}")
            elif parts[0] == "get":
                if len(parts) < 2:
                    print("Error: Missing index for get")
                    continue
                index = int(parts[1])
                value = list_instance.get(index)
                print(f"Value at index {index}: {value}")
            elif parts[0] == "removeByIndex":
                if len(parts) < 2:
                    print("Error: Missing index for removeByIndex")
                    continue
                remove_index = int(parts[1])
                list_instance.remove_by_index(remove_index)
                print(f"Removed value at index {remove_index}")
            elif parts[0] == "indexOf":
                if len(parts) < 2:
                    print("Error: Missing value for indexOf")
                    continue
                idx = list_instance.index_of(parts[1])
                print(f"Index of {parts[1]}: {idx}")
            elif parts[0] == "print":
                list_instance.print_list()
            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")

# <END-OF-CODE>
