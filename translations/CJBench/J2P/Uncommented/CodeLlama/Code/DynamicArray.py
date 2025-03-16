
class Main:
    def __init__(self, capacity=16):
        if capacity < 0:
            raise ValueError("Capacity cannot be negative.")
        self.size = 0
        self.mod_count = 0
        self.elements = [None] * capacity

    def add(self, element):
        self.ensure_capacity(self.size + 1)
        self.elements[self.size] = element
        self.size += 1
        self.mod_count += 1

    def get(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index: {}, Size: {}".format(index, self.size))
        return self.elements[index]

    def remove(self, index):
        if index < 0 or index >= self.size:
            raise IndexError("Index: {}, Size: {}".format(index, self.size))
        old_element = self.elements[index]
        self.fast_remove(index)
        self.mod_count += 1
        return old_element

    def get_size(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def ensure_capacity(self, min_capacity):
        if min_capacity > len(self.elements):
            new_capacity = max(len(self.elements) * 2, min_capacity)
            self.elements.extend([None] * (new_capacity - len(self.elements)))

    def fast_remove(self, index):
        num_moved = self.size - index - 1
        if num_moved > 0:
            self.elements[index:index + num_moved] = self.elements[index + 1:index + num_moved + 1]
        self.elements[self.size - 1] = None
        self.size -= 1

    def __str__(self):
        return str(self.elements[:self.size])

    def __iter__(self):
        return MainIterator(self)

    def __repr__(self):
        return "Main({})".format(self.elements[:self.size])


class MainIterator:
    def __init__(self, main):
        self.main = main
        self.cursor = 0
        self.expected_mod_count = main.mod_count

    def __next__(self):
        self.check_for_comodification()
        if self.cursor >= self.main.size:
            raise StopIteration
        return self.main.elements[self.cursor]

    def check_for_comodification(self):
        if self.main.mod_count != self.expected_mod_count:
            raise RuntimeError("Main has been modified during iteration.")

    def __iter__(self):
        return self


class MainDemo:
    def __init__(self):
        self.main = Main()

    def run(self):
        operations = int(input())
        for _ in range(operations):
            command, *args = input().split()
            if command == "ADD":
                self.main.add(int(args[0]))
            elif command == "REMOVE":
                try:
                    self.main.remove(int(args[0]))
                except IndexError as e:
                    print("Error:", e)
            elif command == "GET":
                try:
                    print("Value at index {}: {}".format(int(args[0]), self.main.get(int(args[0]))))
                except IndexError as e:
                    print("Error:", e)
            else:
                print("Invalid command.")

        print("Final array:", self.main)
        print("Array size:", self.main.get_size())


if __name__ == "__main__":
    MainDemo().run()
    # 