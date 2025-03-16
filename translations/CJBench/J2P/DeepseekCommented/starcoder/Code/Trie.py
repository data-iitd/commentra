import java.util.HashMap;
import java.util.Scanner;

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
            if node == None:
                node = MainNode(word[i])
                currentNode.child[word[i]] = node
            currentNode = node
        currentNode.end = True

    def search(self, word):
        currentNode = self.root
        for i in range(len(word)):
            node = currentNode.child.get(word[i], None)
            if node == None:
                return False
            currentNode = node
        return currentNode.end

    def delete(self, word):
        currentNode = self.root
        for i in range(len(word)):
            node = currentNode.child.get(word[i], None)
            if node == None:
                return False
            currentNode = node
        if currentNode.end:
            currentNode.end = False
            return True
        return False

    def countWords(self):
        return self.countWords(self.root)

    def countWords(self, node):
        if node == None:
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
            if node == None:
                return False
            currentNode = node
        return True

    def countWordsWithPrefix(self, prefix):
        currentNode = self.root
        for i in range(len(prefix)):
            node = currentNode.child.get(prefix[i], None)
            if node == None:
                return 0
            currentNode = node
        return self.countWords(currentNode)

if __name__ == '__main__':
    scanner = Scanner(System.in)
    trie = Main()
    n = scanner.nextInt()
    scanner.nextLine()
    for i in range(n):
        operation = scanner.next()
        if operation.equals("insert"):
            word = scanner.next()
            trie.insert(word)
        elif operation.equals("search"):
            word = scanner.next()
            print(trie.search(word))
        elif operation.equals("delete"):
            word = scanner.next()
            print(trie.delete(word))
        elif operation.equals("countWords"):
            print(trie.countWords())
        elif operation.equals("startsWith"):
            prefix = scanner.next()
            print(trie.startsWithPrefix(prefix))
        elif operation.equals("countWithPrefix"):
            prefix = scanner.next()
            print(trie.countWordsWithPrefix(prefix))
    scanner.close()

