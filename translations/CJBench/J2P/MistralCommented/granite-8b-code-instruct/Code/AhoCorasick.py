

import sys

class TrieNode:
    def __init__(self):
        self.children = {}
        self.suffixLink = None
        self.outputLink = None
        self.patternInd = -1

class Trie:
    def __init__(self, patterns):
        self.root = TrieNode()
        self.patterns = patterns
        self.buildTrie()
        self.buildSuffixAndOutputLinks()

    def buildTrie(self):
        for i, pattern in enumerate(self.patterns):
            curr = self.root
            for ch in pattern:
                if ch not in curr.children:
                    curr.children[ch] = TrieNode()
                curr = curr.children[ch]
            curr.patternInd = i

    def buildSuffixAndOutputLinks(self):
        queue = [self.root]
        while queue:
            curr = queue.pop(0)
            for ch, child in curr.children.items():
                suffix = curr.suffixLink
                while suffix!= self.root and ch not in suffix.children:
                    suffix = suffix.suffixLink
                if ch in suffix.children:
                    suffix = suffix.children[ch]
                child.suffixLink = suffix
                if suffix.patternInd!= -1:
                    child.outputLink = suffix
                else:
                    child.outputLink = suffix.outputLink
                queue.append(child)

    def search(self, text):
        matches = {pattern: [] for pattern in self.patterns}
        current = self.root
        for i, ch in enumerate(text):
            while current!= self.root and ch not in current.children:
                current = current.suffixLink
            if ch in current.children:
                current = current.children[ch]
            temp = current
            while temp!= None:
                if temp.patternInd!= -1:
                    matches[self.patterns[temp.patternInd]].append(i - len(self.patterns[temp.patternInd]) + 1)
                temp = temp.outputLink
        return matches

if __name__ == "__main__":
    text = sys.stdin.readline().strip()
    patternCount = int(sys.stdin.readline().strip())
    patterns = [sys.stdin.readline().strip() for _ in range(patternCount)]
    trie = Trie(patterns)
    result = trie.search(text)
    print("Pattern matches:")
    for pattern in patterns:
        print(pattern + ": " + str(result[pattern]))

