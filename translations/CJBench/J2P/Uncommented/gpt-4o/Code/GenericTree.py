class Node:
    def __init__(self, data):
        self.data = data
        self.children = []

class Tree:
    def __init__(self):
        self.root = None

    def create_tree(self, parent=None, child_index=0):
        if parent is None:
            data = int(input("Enter root's data: "))
        else:
            data = int(input(f"Enter data for child {child_index + 1} of {parent.data}: "))
        
        node = Node(data)
        num_children = int(input(f"Enter the number of children for {node.data}: "))
        
        for i in range(num_children):
            child = self.create_tree(node, i)
            node.children.append(child)
        
        if parent is None:
            self.root = node
        
        return node

    def display(self):
        self.display_tree(self.root)

    def display_tree(self, node):
        print(f"{node.data} => ", end="")
        for child in node.children:
            print(f"{child.data} ", end="")
        print(".")
        for child in node.children:
            self.display_tree(child)

    def size(self):
        return self.size_helper(self.root)

    def size_helper(self, node):
        size = 0
        for child in node.children:
            size += self.size_helper(child)
        return size + 1

    def max(self):
        return self.max_helper(self.root)

    def max_helper(self, node):
        max_value = node.data
        for child in node.children:
            max_value = max(max_value, self.max_helper(child))
        return max_value

    def height(self):
        return self.height_helper(self.root) - 1

    def height_helper(self, node):
        height = 0
        for child in node.children:
            height = max(height, self.height_helper(child))
        return height + 1

    def find(self, value):
        return self.find_helper(self.root, value)

    def find_helper(self, node, value):
        if node.data == value:
            return True
        for child in node.children:
            if self.find_helper(child, value):
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

if __name__ == "__main__":
    tree = Tree()
    tree.create_tree()
    print("\nTree Display:")
    tree.display()
    print(f"\nSize of the tree: {tree.size()}")
    print(f"Maximum value in the tree: {tree.max()}")
    print(f"Height of the tree: {tree.height()}")
    search_value = int(input("\nEnter a value to search: "))
    print(f"Is value present: {tree.find(search_value)}")
    print("\nLevel Order Traversal:")
    tree.level_order()

# <END-OF-CODE>
