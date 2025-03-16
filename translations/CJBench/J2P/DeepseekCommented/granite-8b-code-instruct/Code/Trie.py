
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
        currentNode = self.root
        for char in word:
            if char not in currentNode.child:
                currentNode.child[char] = MainNode(char)
            currentNode = currentNode.child[char]
        currentNode.end = True

    def search(self, word):
        currentNode = self.root
        for char in word:
            if char not in currentNode.child:
                return False
            currentNode = currentNode.child[char]
        return currentNode.end

    def delete(self, word):
        currentNode = self.root
        for char in word:
            if char not in currentNode.child:
                return False
            currentNode = currentNode.child[char]
        if currentNode.end:
            currentNode.end = False
            return True
        return False

    def countWords(self):
        return self.countWordsHelper(self.root)

    def countWordsHelper(self, node):
        if node is None:
            return 0
        count = 1 if node.end else 0
        for child in node.child.values():
            count += self.countWordsHelper(child)
        return count

    def startsWithPrefix(self, prefix):
        currentNode = self.root
        for char in prefix:
            if char not in currentNode.child:
                return False
            currentNode = currentNode.child[char]
        return True

    def countWordsWithPrefix(self, prefix):
        currentNode = self.root
        for char in prefix:
            if char not in currentNode.child:
                return 0
            currentNode = currentNode.child[char]
        return self.countWordsHelper(currentNode)

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
            print(main.countWords())
        elif operation == "startsWith":
            print(main.startsWithPrefix(args[0]))
        elif operation == "countWithPrefix":
            print(main.countWordsWithPrefix(args[0]))

