class MainNode:
    def __init__(self, value):
        self.value = value  # Initialize the node with a given value
        self.child = {}  # Initialize an empty dictionary for children
        self.end = False  # Flag to indicate if it's an end node


class Main:
    def __init__(self):
        self.root = MainNode('*')  # Initialize the root node

    def insert(self, word):
        current_node = self.root  # Initialize current_node as the root

        for char in word:
            node = current_node.child.get(char, None)
            if node is None:  # If the node for the current character doesn't exist
                node = MainNode(char)  # Create a new node
                current_node.child[char] = node  # Add it as a child to the current node
            current_node = node  # Move to the next node
        current_node.end = True  # Set the end flag for the last node

    def search(self, word):
        current_node = self.root  # Initialize current_node as the root

        for char in word:
            node = current_node.child.get(char, None)
            if node is None:  # If the node for the current character doesn't exist
                return False
            current_node = node  # Move to the next node
        return current_node.end  # Return true if the last node is an end node

    def delete(self, word):
        current_node = self.root  # Initialize current_node as the root
        stack = []  # To keep track of nodes for potential cleanup

        for char in word:
            node = current_node.child.get(char, None)
            if node is None:  # If the node for the current character doesn't exist
                return False
            stack.append((current_node, char))  # Keep track of the current node and character
            current_node = node  # Move to the next node

        if not current_node.end:  # If the last node is not an end node
            return False

        current_node.end = False  # Unmark the end node

        # Clean up nodes if they have no children
        for parent, char in reversed(stack):
            if not current_node.child:  # If the current node has no children
                del parent.child[char]  # Remove the reference from the parent
                current_node = parent  # Move up to the parent node
            else:
                break  # Stop if we find a node with children

        return True

    def count_words(self):
        return self._count_words(self.root)  # Count words starting from the root

    def _count_words(self, node):
        count = 1 if node.end else 0  # Increment count if it's an end node
        for child in node.child.values():
            count += self._count_words(child)  # Recursively count words in children
        return count

    def starts_with_prefix(self, prefix):
        current_node = self.root  # Initialize current_node as the root

        for char in prefix:
            node = current_node.child.get(char, None)
            if node is None:  # If the node for the current character doesn't exist
                return False
            current_node = node  # Move to the next node
        return True  # Return true if the prefix exists

    def count_words_with_prefix(self, prefix):
        current_node = self.root  # Initialize current_node as the root

        for char in prefix:
            node = current_node.child.get(char, None)
            if node is None:  # If the node for the current character doesn't exist
                return 0
            current_node = node  # Move to the next node
        return self._count_words(current_node)  # Count words in the sub-tree

# Main method to read input and perform operations on the Main
if __name__ == "__main__":
    import sys

    trie = Main()  # Initialize a new Main object

    n = int(sys.stdin.readline().strip())  # Read the number of operations

    for _ in range(n):
        operation = sys.stdin.readline().strip()  # Read the operation

        if operation.startswith("insert"):
            _, word = operation.split()  # Read the word to be inserted
            trie.insert(word)  # Perform the insertion
        elif operation.startswith("search"):
            _, word = operation.split()  # Read the word to be searched
            print(trie.search(word))  # Print the search result
        elif operation.startswith("delete"):
            _, word = operation.split()  # Read the word to be deleted
            print(trie.delete(word))  # Print the deletion result
        elif operation == "countWords":
            print(trie.count_words())  # Print the number of words in the Main
        elif operation.startswith("startsWith"):
            _, prefix = operation.split()  # Read the prefix
            print(trie.starts_with_prefix(prefix))  # Print whether the Main starts with the prefix
        elif operation.startswith("countWithPrefix"):
            _, prefix = operation.split()  # Read the prefix
            print(trie.count_words_with_prefix(prefix))  # Print the number of words in the Main that start with the prefix

# <END-OF-CODE>
