
class Node:
    def __init__(self, data):
        self.data = data
        self.child = []

class Tree:
    def __init__(self, scanner):
        self.root = self.create_tree(None, 0, scanner)

    def create_tree(self, parent, child_index, scanner):
        if parent is None:
            print("Enter root's data:")
        else:
            print("Enter data for child " + str(child_index + 1) + " of " + str(parent.data) + ":")

        node = Node(scanner.nextInt())

        print("Enter the number of children for " + str(node.data) + ":")
        num_children = scanner.nextInt()

        for i in range(num_children):
            child = self.create_tree(node, i, scanner)
            node.child.append(child)

        return node

    def display(self):
        self.display_tree(self.root)

    def display_tree(self, node):
        print(str(node.data) + " => ", end="")
        for child in node.child:
            print(str(child.data) + " ", end="")
        print(".")
        for child in node.child:
            self.display_tree(child)

    def size(self):
        return self.size_helper(self.root)

    def size_helper(self, node):
        size = 0
        for child in node.child:
            size += self.size_helper(child)
        return size + 1

    def max(self):
        return self.max_helper(self.root)

    def max_helper(self, node):
        max = node.data
        for child in node.child:
            max = max(max, self.max_helper(child))
        return max

    def height(self):
        return self.height_helper(self.root) - 1

    def height_helper(self, node):
        height = 0
        for child in node.child:
            height = max(height, self.height_helper(child))
        return height + 1

    def find(self, value):
        return self.find_helper(self.root, value)

    def find_helper(self, node, value):
        if node.data == value:
            return True
        for child in node.child:
            if self.find_helper(child, value):
                return True
        return False

    def level_order(self):
        queue = [self.root]
        while len(queue) > 0:
            current = queue.pop(0)
            print(str(current.data) + " ", end="")
            queue.extend(current.child)
        print()

if __name__ == "__main__":
    scanner = Scanner(System.in)
    tree = Tree(scanner)

    # Display tree, size, max, height, and perform search and level order traversal
    print("\nTree Display:")
    tree.display()
    print("\nSize of the tree: " + str(tree.size()))
    print("Maximum value in the tree: " + str(tree.max()))
    print("Height of the tree: " + str(tree.height()))
    print("\nEnter a value to search:")
    search_value = scanner.nextInt()
    print("Is value present: " + str(tree.find(search_value)))
    print("\nLevel Order Traversal:")
    tree.level_order()

