class Node:
    def __init__(self):
        self.child = {}
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
                curr = curr.child.setdefault(c, Node())

    def buildSuffixAndOutputLinks(self):
        self.root.suffixLink = self.root
        queue = [self.root]
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
        matches = {pattern: [] for pattern in self.patterns}
        current = self.root
        for i in range(len(text)):
            ch = text[i]
            while current != self.root and ch not in current.child:
                current = current.suffixLink
            if ch in current.child:
                current = current.child[ch]
            temp = current
            while temp:
                if temp.patternInd != -1:
                    matches[self.patterns[temp.patternInd]].append(i - len(self.patterns[temp.patternInd]) + 1)
                temp = temp.outputLink
        return matches

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    text = data[0]
    patternCount = int(data[1])
    patterns = data[2:2 + patternCount]
    trie = Trie(patterns)
    result = trie.search(text)
    print("Pattern matches:")
    for pattern in patterns:
        print(f"{pattern}: {result[pattern]}")

if __name__ == "__main__":
    main()

