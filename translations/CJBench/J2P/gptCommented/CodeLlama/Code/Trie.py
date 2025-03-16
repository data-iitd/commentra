
import collections

# Class representing a node in the Main
class MainNode:
    def __init__(self, value):
        self.value = value
        self.child = collections.defaultdict(MainNode)
        self.end = False

# Main class for the Main data structure
class Main:
    def __init__(self):
        self.root = MainNode('*')

    def insert(self, word):
        current_node = self.root
        for char in word:
            current_node = current_node.child[char]
        current_node.end = True

    def search(self, word):
        current_node = self.root
        for char in word:
            current_node = current_node.child.get(char, None)
            if current_node is None:
                return False
        return current_node.end

    def delete(self, word):
        current_node = self.root
        for char in word:
            current_node = current_node.child.get(char, None)
            if current_node is None:
                return False
        if current_node.end:
            current_node.end = False
            return True
        return False

    def count_words(self):
        return self.count_words(self.root)

    def count_words(self, node):
        if node is None:
            return 0
        count = 0
        if node.end:
            count += 1
        for child in node.child.values():
            count += self.count_words(child)
        return count

    def starts_with_prefix(self, prefix):
        current_node = self.root
        for char in prefix:
            current_node = current_node.child.get(char, None)
            if current_node is None:
                return False
        return True

    def count_words_with_prefix(self, prefix):
        current_node = self.root
        for char in prefix:
            current_node = current_node.child.get(char, None)
            if current_node is None:
                return 0
        return self.count_words(current_node)


# Main method to run the Main operations based on user input
if __name__ == "__main__":
    trie = Main()
    n = int(input())
    for _ in range(n):
        operation = input()
        if operation == "insert":
            word = input()
            trie.insert(word)
        elif operation == "search":
            word = input()
            print(trie.search(word))
        elif operation == "delete":
            word = input()
            print(trie.delete(word))
        elif operation == "countWords":
            print(trie.count_words())
        elif operation == "startsWith":
            prefix = input()
            print(trie.starts_with_prefix(prefix))
        elif operation == "countWithPrefix":
            prefix = input()
            print(trie.count_words_with_prefix(prefix))


