
import sys

# Trie Node Class
class Node:
    def __init__(self):
        self.child = {}
        self.suffixLink = None
        self.outputLink = None
        self.patternInd = -1

# Trie Class
class Trie:
    def __init__(self, patterns):
        self.root = Node()
        self.patterns = patterns
        self.buildTrie()
        self.buildSuffixAndOutputLinks()

    def buildTrie(self):
        for i in range(len(self.patterns)):
            curr = self.root
            for ch in self.patterns[i]:
                if ch not in curr.child:
                    curr.child[ch] = Node()
                curr = curr.child[ch]
            curr.patternInd = i

    def buildSuffixAndOutputLinks(self):
        self.root.suffixLink = self.root
        queue = []

        for child in self.root.child.values():
            child.suffixLink = self.root
            queue.append(child)

        while queue:
            current = queue.pop(0)

            for ch, child in current.child.items():
                suffix = current.suffixLink
                while suffix != self.root and ch not in suffix.child:
                    suffix = suffix.suffixLink
                if ch in suffix.child:
                    suffix = suffix.child[ch]
                child.suffixLink = suffix

                if suffix.patternInd != -1:
                    child.outputLink = suffix
                else:
                    child.outputLink = suffix.outputLink

                queue.append(child)

    def search(self, text):
        matches = {}
        for pattern in self.patterns:
            matches[pattern] = []

        current = self.root
        for i in range(len(text)):
            ch = text[i]

            while current != self.root and ch not in current.child:
                current = current.suffixLink
            if ch in current.child:
                current = current.child[ch]

            temp = current
            while temp is not None:
                if temp.patternInd != -1:
                    matches[self.patterns[temp.patternInd]].append(i - len(self.patterns[temp.patternInd]) + 1)
                temp = temp.outputLink

        return matches

def main():
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

if __name__ == "__main__":
    main()

