class Node:
    def __init__(self, content=None, next_element=None):
        self.content = content
        self.next_element = next_element

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
        current = self.first_element
        while current is not None:
            if current.content == element:
                return True
            current = current.next_element
        return False

    def __iter__(self):
        self._current_element = self.first_element
        return self

    def __next__(self):
        if self._current_element is None:
            raise StopIteration("No more elements in the bag.")
        element = self._current_element.content
        self._current_element = self._current_element.next_element
        return element

# Main method for testing the Main class
if __name__ == "__main__":
    bag = Main()
    n = int(input())
    for _ in range(n):
        element = input()
        bag.add(element)

    print("Main contents:")
    for element in bag:
        print(element)

    check_element = input()
    print("Contains", check_element, ":", bag.contains(check_element))
    print("Main size:", bag.size())
    print("Is bag empty:", bag.is_empty())
