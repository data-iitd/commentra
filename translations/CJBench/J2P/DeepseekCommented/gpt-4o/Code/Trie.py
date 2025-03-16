class MainNode:
    def __init__(self, value):
        self.value = value
        self.child = {}
        self.end = False


class Main:
    def __init__(self):
        self.root = MainNode('*')

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
        nodes = []
        for char in word:
            if char not in current_node.child:
                return False
            nodes.append((current_node, char))
            current_node = current_node.child[char]
        if not current_node.end:
            return False
        current_node.end = False
        for parent, char in reversed(nodes):
            if current_node.child or current_node.end:
                break
            del parent.child[char]
            current_node = parent
        return True

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
        return self._count_words(current_node)


def main():
    trie = Main()
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    index = 1
    for _ in range(n):
        operation = data[index]
        index += 1
        if operation == "insert":
            word = data[index]
            index += 1
            trie.insert(word)
        elif operation == "search":
            word = data[index]
            index += 1
            print(trie.search(word))
        elif operation == "delete":
            word = data[index]
            index += 1
            print(trie.delete(word))
        elif operation == "countWords":
            print(trie.count_words())
        elif operation == "startsWith":
            prefix = data[index]
            index += 1
            print(trie.starts_with_prefix(prefix))
        elif operation == "countWithPrefix":
            prefix = data[index]
            index += 1
            print(trie.count_words_with_prefix(prefix))


if __name__ == "__main__":
    main()
