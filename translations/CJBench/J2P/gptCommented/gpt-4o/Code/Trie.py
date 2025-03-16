class MainNode:
    def __init__(self, value):
        self.value = value  # Character value of the node
        self.child = {}  # Children of the current node
        self.end = False  # Indicates if the node marks the end of a word


class Main:
    ROOT_NODE_VALUE = '*'  # Value for the root node

    def __init__(self):
        self.root = MainNode(self.ROOT_NODE_VALUE)  # Initialize the Main with a root node

    def insert(self, word):
        current_node = self.root  # Start from the root node
        for char in word:
            # Get the child node corresponding to the current character
            node = current_node.child.get(char, None)
            # If the node does not exist, create a new one
            if node is None:
                node = MainNode(char)
                current_node.child[char] = node  # Add the new node to children
            current_node = node  # Move to the child node
        current_node.end = True  # Mark the end of the word

    def search(self, word):
        current_node = self.root  # Start from the root node
        for char in word:
            # Get the child node corresponding to the current character
            node = current_node.child.get(char, None)
            # If the node does not exist, the word is not in the Main
            if node is None:
                return False
            current_node = node  # Move to the child node
        return current_node.end  # Return true if the current node marks the end of a word

    def delete(self, word):
        current_node = self.root  # Start from the root node
        for char in word:
            # Get the child node corresponding to the current character
            node = current_node.child.get(char, None)
            # If the node does not exist, the word cannot be deleted
            if node is None:
                return False
            current_node = node  # Move to the child node
        # If the current node marks the end of a word, unmark it
        if current_node.end:
            current_node.end = False  # Mark the end as false
            return True  # Return true indicating successful deletion
        return False  # Return false if the word was not found

    def count_words(self):
        return self._count_words(self.root)  # Start counting from the root node

    def _count_words(self, node):
        if node is None:
            return 0  # Base case: no node means no words
        count = 0  # Initialize word count
        if node.end:
            count += 1  # Increment count if the node marks the end of a word
        # Recursively count words in all child nodes
        for child in node.child.values():
            count += self._count_words(child)
        return count  # Return the total count

    def starts_with_prefix(self, prefix):
        current_node = self.root  # Start from the root node
        for char in prefix:
            # Get the child node corresponding to the current character
            node = current_node.child.get(char, None)
            # If the node does not exist, no word starts with the prefix
            if node is None:
                return False
            current_node = node  # Move to the child node
        return True  # Return true if the prefix exists in the Main

    def count_words_with_prefix(self, prefix):
        current_node = self.root  # Start from the root node
        for char in prefix:
            # Get the child node corresponding to the current character
            node = current_node.child.get(char, None)
            # If the node does not exist, return 0 as no words match the prefix
            if node is None:
                return 0
            current_node = node  # Move to the child node
        return self._count_words(current_node)  # Count words from the current node


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    trie = Main()  # Initialize the Main
    n = int(data[0])  # Read the number of operations
    for i in range(1, n + 1):
        operation = data[i].split()  # Read the operation type
        # Perform the corresponding operation based on user input
        if operation[0] == "insert":
            word = operation[1]
            trie.insert(word)  # Insert the word into the Main
        elif operation[0] == "search":
            word = operation[1]
            print(trie.search(word))  # Search for the word and print the result
        elif operation[0] == "delete":
            word = operation[1]
            print(trie.delete(word))  # Delete the word and print the result
        elif operation[0] == "countWords":
            print(trie.count_words())  # Print the total number of words in the Main
        elif operation[0] == "startsWith":
            prefix = operation[1]
            print(trie.starts_with_prefix(prefix))  # Check if any word starts with the prefix and print the result
        elif operation[0] == "countWithPrefix":
            prefix = operation[1]
            print(trie.count_words_with_prefix(prefix))  # Count words with the given prefix and print the result

# <END-OF-CODE>
