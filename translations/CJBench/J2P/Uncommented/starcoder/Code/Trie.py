
import collections
class TrieNode:
    def __init__(self):
        self.child = collections.defaultdict(TrieNode)
        self.end = False
class Trie:
    def __init__(self):
        self.root = TrieNode()
    def insert(self, word):
        current = self.root
        for c in word:
            current = current.child[c]
        current.end = True
    def search(self, word):
        current = self.root
        for c in word:
            current = current.child.get(c, None)
            if current is None:
                return False
        return current.end
    def delete(self, word):
        current = self.root
        for c in word:
            current = current.child.get(c, None)
            if current is None:
                return False
        if current.end:
            current.end = False
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
        current = self.root
        for c in prefix:
            current = current.child.get(c, None)
            if current is None:
                return False
        return True
    def countWordsWithPrefix(self, prefix):
        current = self.root
        for c in prefix:
            current = current.child.get(c, None)
            if current is None:
                return 0
        return self.countWords(current)

if __name__ == "__main__":
    trie = Trie()
    n = int(input())
    for i in range(n):
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
            print(trie.countWords())
        elif operation == "startsWith":
            prefix = input()
            print(trie.startsWithPrefix(prefix))
        elif operation == "countWithPrefix":
            prefix = input()
            print(trie.countWordsWithPrefix(prefix))

