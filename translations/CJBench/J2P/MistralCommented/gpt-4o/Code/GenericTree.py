class Node:
    def __init__(self, data):
        self.data = data
        self.children = []

class Tree:
    def __init__(self):
        self.root = None

    def create_tree(self, parent=None):
        if parent is None:
            data = int(input("Enter root's data: "))
            self.root = Node(data)
            parent = self.root
        else:
            data = int(input(f"Enter data for child of {parent.data}: "))
            child = Node(data)
            parent.children.append(child)

        num_children = int(input(f"Enter the number of children for {data}: "))
        for _ in range(num_children):
            self.create_tree(parent)

    def display(self, node=None):
        if node is None:
            node = self.root
        print(f"{node.data} => ", end="")
        for child in node.children:
            print(f"{child.data} ", end="")
        print(".")
        for child in node.children:
            self.display(child)

    def size(self, node=None):
        if node is None:
            node = self.root
        size = 1  # Count the current node
        for child in node.children:
            size += self.size(child)
        return size

    def max_value(self, node=None):
        if node is None:
            node = self.root
        max_val = node.data
        for child in node.children:
            max_val = max(max_val, self.max_value(child))
        return max_val

    def height(self, node=None):
        if node is None:
            node = self.root
        if not node.children:
            return 1
        return 1 + max(self.height(child) for child in node.children)

    def find(self, value, node=None):
        if node is None:
            node = self.root
        if node.data == value:
            return True
        for child in node.children:
            if self.find(value, child):
                return True
        return False

    def level_order(self):
        from collections import deque
        queue = deque([self.root])
        while queue:
            current = queue.popleft()
            print(current.data, end=" ")
            queue.extend(current.children)
        print()

def main():
    tree = Tree()
    tree.create_tree()

    print("\nTree Display:")
    tree.display()
    print(f"\nSize of the tree: {tree.size()}")
    print(f"Maximum value in the tree: {tree.max_value()}")
    print(f"Height of the tree: {tree.height()}")
    
    search_value = int(input("\nEnter a value to search: "))
    print(f"Is value present: {tree.find(search_value)}")
    
    print("\nLevel Order Traversal:")
    tree.level_order()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
