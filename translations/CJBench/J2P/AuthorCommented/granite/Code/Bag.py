

class Main:
    def __init__(self):
        self.first_element = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def size(self):
        return self.size

    def add(self, element):
        new_node = Node(element)
        new_node.next_element = self.first_element
        self.first_element = new_node
        self.size += 1

    def contains(self, element):
        for value in self:
            if value == element:
                return True
        return False

    def __iter__(self):
        return ListIterator(self.first_element)

class Node:
    def __init__(self, content):
        self.content = content
        self.next_element = None

class ListIterator:
    def __init__(self, first_element):
        self.current_element = first_element

    def has_next(self):
        return self.current_element is not None

    def next(self):
        if not self.has_next():
            raise StopIteration("No more elements in the bag.")
        element = self.current_element.content
        self.current_element = self.current_element.next_element
        return element

if __name__ == "__main__":
    n = int(input("Enter the number of elements: "))
    bag = Main()

    print("Enter elements:")
    for _ in range(n):
        element = input()
        bag.add(element)

    print("Main contents:")
    for element in bag:
        print(element)

    check_element = input("Enter an element to check for membership: ")
    print(f"Contains {check_element}: {bag.contains(check_element)}")

    print(f"Main size: {bag.size()}")
    print(f"Is bag empty: {bag.is_empty()}")

