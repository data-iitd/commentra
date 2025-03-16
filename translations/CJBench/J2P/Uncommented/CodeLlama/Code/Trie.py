
class MainNode:
    def __init__(self, value):
        self.value = value
        self.child = {}
        self.end = False

class Main:
    def __init__(self):
        self.root = MainNode('*')

    def insert(self, word):
        currentNode = self.root
        for i in range(len(word)):
            node = currentNode.child.get(word[i], None)
            if node is None:
                node = MainNode(word[i])
                currentNode.child[word[i]] = node
            currentNode = node
        currentNode.end = True

    def search(self, word):
        currentNode = self.root
        for i in range(len(word)):
            node = currentNode.child.get(word[i], None)
            if node is None:
                return False
            currentNode = node
        return currentNode.end

    def delete(self, word):
        currentNode = self.root
        for i in range(len(word)):
            node = currentNode.child.get(word[i], None)
            if node is None:
                return False
            currentNode = node
        if currentNode.end:
            currentNode.end = False
            return True
        return False

    def countWords(self):
        return self.countWords(self.root)

    def countWords(self, node):
        if node is None:
            return 0
        count = 0
        if node.end:
            count += 1
        for child in node.child.values():
            count += self.countWords(child)
        return count

    def startsWithPrefix(self, prefix):
        currentNode = self.root
        for i in range(len(prefix)):
            node = currentNode.child.get(prefix[i], None)
            if node is None:
                return False
            currentNode = node
        return True

    def countWordsWithPrefix(self, prefix):
        currentNode = self.root
        for i in range(len(prefix)):
            node = currentNode.child.get(prefix[i], None)
            if node is None:
                return 0
            currentNode = node
        return self.countWords(currentNode)

if __name__ == "__main__":
    trie = Main()
    n = int(input())
    for i in range(n):
        operation = input().split()
        if operation[0] == "insert":
            trie.insert(operation[1])
        elif operation[0] == "search":
            print(trie.search(operation[1]))
        elif operation[0] == "delete":
            print(trie.delete(operation[1]))
        elif operation[0] == "countWords":
            print(trie.countWords())
        elif operation[0] == "startsWith":
            print(trie.startsWithPrefix(operation[1]))
        elif operation[0] == "countWithPrefix":
            print(trie.countWordsWithPrefix(operation[1]))

