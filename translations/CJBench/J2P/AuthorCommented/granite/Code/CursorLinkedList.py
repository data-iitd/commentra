

class Main:
    def __init__(self):
        self.os = 0
        self.count = 0
        self.head = -1
        self.cursor_space = [None] * 100
        for i in range(99):
            self.cursor_space[i] = (None, i + 1)
        self.cursor_space[99] = (None, 0)

    def print_list(self):
        if self.head!= -1:
            start = self.head
            while start!= -1:
                element = self.cursor_space[start][0]
                print(element, end=" -> ")
                start = self.cursor_space[start][1]
        print("null")

    def index_of(self, element):
        if element is None:
            raise ValueError("Element cannot be None")
        current = self.head
        index = 0
        while current!= -1:
            if self.cursor_space[current][0] == element:
                return index
            current = self.cursor_space[current][1]
            index += 1
        return -1

    def get(self, position):
        if position >= 0 and position < self.count:
            start = self.head
            counter = 0
            while start!= -1:
                if counter == position:
                    return self.cursor_space[start][0]
                start = self.cursor_space[start][1]
                counter += 1
        return None

    def remove_by_index(self, index):
        if index >= 0 and index < self.count:
            element = self.get(index)
            self.remove(element)

    def remove(self, element):
        if element is None:
            raise ValueError("Element cannot be None")
        if self.head == -1:
            return
        if self.cursor_space[self.head][0] == element:
            self.free(self.head)
            self.head = self.cursor_space[self.head][1]
        else:
            prev = self.head
            current = self.cursor_space[prev][1]
            while current!= -1:
                if self.cursor_space[current][0] == element:
                    self.cursor_space[prev][1] = self.cursor_space[current][1]
                    self.free(current)
                    break
                prev = current
                current = self.cursor_space[prev][1]
        self.count -= 1

    def alloc(self):
        available_node_index = self.cursor_space[self.os][1]
        if available_node_index == 0:
            raise MemoryError("No space available in cursor space")
        self.cursor_space[self.os][1] = self.cursor_space[available_node_index][1]
        self.cursor_space[available_node_index][1] = -1
        return available_node_index

    def free(self, index):
        self.cursor_space[index][0] = None
        self.cursor_space[index][1] = self.cursor_space[self.os][1]
        self.cursor_space[self.os][1] = index

    def append(self, element):
        if element is None:
            raise ValueError("Element cannot be None")
        available_index = self.alloc()
        self.cursor_space[available_index][0] = element
        if self.head == -1:
            self.head = available_index
        else:
            iterator = self.head
            while self.cursor_space[iterator][1]!= -1:
                iterator = self.cursor_space[iterator][1]
            self.cursor_space[iterator][1] = available_index
        self.count += 1

if __name__ == "__main__":
    list = Main()
    commands = ["append 1", "append 2", "append 3", "get 1", "removeByIndex 1", "indexOf 2", "print", "exit"]
    for command in commands:
        parts = command.split()
        if parts[0] == "append":
            if len(parts) < 2:
                print("Error: Missing value for append")
                continue
            list.append(parts[1])
            print("Appended:", parts[1])
        elif parts[0] == "get":
            if len(parts) < 2:
                print("Error: Missing index for get")
                continue
            index = int(parts[1])
            value = list.get(index)
            print("Value at index", index, ":", value)
        elif parts[0] == "removeByIndex":
            if len(parts) < 2:
                print("Error: Missing index for removeByIndex")
                continue
            remove_index = int(parts[1])
            list.remove_by_index(remove_index)
            print("Removed value at index", remove_index)
        elif parts[0] == "indexOf":
            if len(parts) < 2:
                print("Error: Missing value for indexOf")
                continue
            value = parts[1]
            idx = list.index_of(value)
            print("Index of", value, ":", idx)
        elif parts[0] == "print":
            list.print_list()
        else:
            print("Unknown command:", parts[0])

