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
            node = current_node.child.get(char, None)
            if node is None:
                node = MainNode(char)
                current_node.child[char] = node
            current_node = node
        current_node.end = True

    def search(self, word):
        current_node = self.root
        for char in word:
            node = current_node.child.get(char, None)
            if node is None:
                return False
            current_node = node
        return current_node.end

    def delete(self, word):
        current_node = self.root
        for char in word:
            node = current_node.child.get(char, None)
            if node is None:
                return False
            current_node = node
        if not current_node.end:
            return False
        if len(current_node.child) == 0:
            del current_node.parent.child[current_node.value]
            return True
        smallest_node = current_node
        for child in current_node.child.values():
            if child.value < smallest_node.value:
                smallest_node = child
        smallest_node.child.update(current_node.child)
        smallest_node.end = current_node.end
        del current_node.parent.child[current_node.value]
        return True

    def count_words(self):
        return self.count_words_recursive(self.root)

    def count_words_recursive(self, node):
        count = 0
        if node.end:
            count += 1
        for child in node.child.values():
            count += self.count_words_recursive(child)
        return count

    def starts_with_prefix(self, prefix):
        current_node = self.root
        for char in prefix:
            node = current_node.child.get(char, None)
            if node is None:
                return False
            current_node = node
        return True

    def count_words_with_prefix(self, prefix):
        current_node = self.root
        for char in prefix:
            node = current_node.child.get(char, None)
            if node is None:
                return 0
            current_node = node
        return self.count_words_recursive(current_node)


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
