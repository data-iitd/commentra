class Node:
    def __init__(self, content):
        self.content = content
        self.next_element = None

class Main:
    def __init__(self):
        self.first_element = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def get_size(self):
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
        current = self.first_element
        while current is not None:
            yield current.content
            current = current.next_element

if __name__ == "__main__":
    n = int(input("Enter number of elements: "))
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
    print(f"Main size: {bag.get_size()}")
    print(f"Is bag empty: {bag.is_empty()}")

# <END-OF-CODE>
