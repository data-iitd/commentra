
class MainNode:
    def __init__(self, value):
        self.value = value
        self.child = {}
        self.end = False

class Main:
    ROOT_NODE_VALUE = '*'

    def __init__(self):
        self.root = MainNode(Main.ROOT_NODE_VALUE)

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
        return self.count_words_helper(self.root)

    def count_words_helper(self, node):
        if node is None:
            return 0
        count = 1 if node.end else 0
        for child in node.child.values():
            count += self.count_words_helper(child)
        return count

    def startsWith_prefix(self, prefix):
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
        return self.count_words_helper(current_node)

if __name__ == "__main__":
    import sys
    n = int(input())
    main = Main()
    for _ in range(n):
        operation, *args = input().split()
        if operation == "insert":
            main.insert(args[0])
        elif operation == "search":
            print(main.search(args[0]))
        elif operation == "delete":
            print(main.delete(args[0]))
        elif operation == "countWords":
            print(main.count_words())
        elif operation == "startsWith":
            print(main.startsWith_prefix(args[0]))
        elif operation == "countWithPrefix":
            print(main.count_words_with_prefix(args[0]))
    print("