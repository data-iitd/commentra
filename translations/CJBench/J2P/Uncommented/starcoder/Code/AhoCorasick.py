import collections
import sys

class Node:
    def __init__(self):
        self.child = collections.defaultdict(Node)
        self.suffixLink = None
        self.outputLink = None
        self.patternInd = -1

class Trie:
    def __init__(self, patterns):
        self.root = Node()
        self.patterns = patterns
        self.buildTrie()
        self.buildSuffixAndOutputLinks()

    def buildTrie(self):
        for i in range(len(self.patterns)):
            curr = self.root
            for c in self.patterns[i]:
                curr = curr.child[c]
            curr.patternInd = i

    def buildSuffixAndOutputLinks(self):
        self.root.suffixLink = self.root
        queue = collections.deque()
        for child in self.root.child.values():
            child.suffixLink = self.root
            queue.append(child)
        while queue:
            current = queue.popleft()
            for ch, child in current.child.items():
                suffix = current.suffixLink
                while suffix!= self.root and ch not in suffix.child:
                    suffix = suffix.suffixLink
                if ch in suffix.child:
                    suffix = suffix.child[ch]
                child.suffixLink = suffix
                if suffix.patternInd!= -1:
                    child.outputLink = suffix
                else:
                    child.outputLink = suffix.outputLink
                queue.append(child)

    def search(self, text):
        matches = collections.defaultdict(list)
        for pattern in self.patterns:
            matches[pattern] = []
        current = self.root
        for i in range(len(text)):
            ch = text[i]
            while current!= self.root and ch not in current.child:
                current = current.suffixLink
            if ch in current.child:
                current = current.child[ch]
            temp = current
            while temp!= None:
                if temp.patternInd!= -1:
                    matches[self.patterns[temp.patternInd]].append(i - len(self.patterns[temp.patternInd]) + 1)
                temp = temp.outputLink
        return matches

if __name__ == "__main__":
    text = sys.stdin.readline().strip()
    patternCount = int(sys.stdin.readline().strip())
    patterns = []
    for i in range(patternCount):
        patterns.append(sys.stdin.readline().strip())
    trie = Trie(patterns)
    result = trie.search(text)
    print("Pattern matches:")
    for pattern in patterns:
        print(pattern + ": " + str(result[pattern]))

