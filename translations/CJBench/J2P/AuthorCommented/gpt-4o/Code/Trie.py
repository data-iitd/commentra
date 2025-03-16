class MainNode:
    def __init__(self, value):
        self.value = value
        self.child = {}
        self.end = False


class Main:
    ROOT_NODE_VALUE = '*'

    def __init__(self):
        self.root = MainNode(self.ROOT_NODE_VALUE)

    def insert(self, word):
        current_node = self.root
        for char in word:
            if char not in current_node.child:
                current_node.child[char] = MainNode(char)
            current_node = current_node.child[char]
        current_node.end = True

    def search(self, word):
        current_node = self.root
        for char in word:
            if char not in current_node.child:
                return False
            current_node = current_node.child[char]
        return current_node.end

    def delete(self, word):
        current_node = self.root
        for char in word:
            if char not in current_node.child:
                return False
            current_node = current_node.child[char]

        if current_node.end:
            current_node.end = False
            return True
        return False

    def count_words(self):
        return self._count_words(self.root)

    def _count_words(self, node):
        if node is None:
            return 0

        count = 1 if node.end else 0

        for child in node.child.values():
            count += self._count_words(child)

        return count

    def starts_with_prefix(self, prefix):
        current_node = self.root
        for char in prefix:
            if char not in current_node.child:
                return False
            current_node = current_node.child[char]
        return True

    def count_words_with_prefix(self, prefix):
        current_node = self.root
        for char in prefix:
            if char not in current_node.child:
                return 0
            current_node = current_node.child[char]
        return self.count_words(current_node)

if __name__ == "__main__":
    import sys

    trie = Main()

    # Input: Number of operations
    n = int(sys.stdin.readline().strip())

    for _ in range(n):
        operation = sys.stdin.readline().strip().split()

        if operation[0] == "insert":
            word = operation[1]
            trie.insert(word)
        elif operation[0] == "search":
            word = operation[1]
            print(trie.search(word))
        elif operation[0] == "delete":
            word = operation[1]
            print(trie.delete(word))
        elif operation[0] == "countWords":
            print(trie.count_words())
        elif operation[0] == "startsWith":
            prefix = operation[1]
            print(trie.starts_with_prefix(prefix))
        elif operation[0] == "countWithPrefix":
            prefix = operation[1]
            print(trie.count_words_with_prefix(prefix))

# <END-OF-CODE>
