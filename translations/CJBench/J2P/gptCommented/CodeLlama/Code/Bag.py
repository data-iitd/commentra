
class Node:
    def __init__(self, content, next_element=None):
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
        for value in self:
            if value == element:
                return True
        return False

    def __iter__(self):
        return ListIterator(self.first_element)

class ListIterator:
    def __init__(self, first_element):
        self.current_element = first_element

    def __next__(self):
        if self.current_element is None:
            raise StopIteration
        element = self.current_element.content
        self.current_element = self.current_element.next_element
        return element

    def __iter__(self):
        return self

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
    print("Contains " + check_element + ": " + str(bag.contains(check_element)))

    print("Main size: " + str(bag.size()))

    print("Is bag empty: " + str(bag.is_empty()))

