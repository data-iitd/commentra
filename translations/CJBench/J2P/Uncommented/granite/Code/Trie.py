

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
        return self.countWordsHelper(currentNode)

if __name__ == '__main__':
    import sys
    n = int(input())
    trie = Main()
    for i in range(n):
        operation, *args = input().split()
        if operation == 'insert':
            trie.insert(args[0])
        elif operation =='search':
            print(trie.search(args[0]))
        elif operation == 'delete':
            print(trie.delete(args[0]))
        elif operation == 'countWords':
            print(trie.countWords())
        elif operation =='startsWith':
            print(trie.startsWithPrefix(args[0]))
        elif operation == 'countWithPrefix':
            print(trie.countWordsWithPrefix(args[0]))
    sys.stdout.flush()
