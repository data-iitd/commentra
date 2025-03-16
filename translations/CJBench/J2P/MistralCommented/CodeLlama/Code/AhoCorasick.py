
import collections

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
            for ch in self.patterns[i]:
                if ch not in curr.child:
                    curr.child[ch] = Node()
                curr = curr.child[ch]
            curr.patternInd = i

    def buildSuffixAndOutputLinks(self):
        self.root.suffixLink = self.root
        queue = collections.deque([self.root])
        for child in self.root.child.values():
            child.suffixLink = self.root
            queue.append(child)
        while queue:
            current = queue.popleft()
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
        matches = collections.defaultdict(list)
        for pattern in self.patterns:
            matches[pattern] = []
        current = self.root
        for i, ch in enumerate(text):
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
    text = input()
    patternCount = int(input())
    patterns = []
    for i in range(patternCount):
        patterns.append(input())
    trie = Trie(patterns)
    result = trie.search(text)
    print("Pattern matches:")
    for pattern in patterns:
        print(pattern + ": " + str(result[pattern]))

if __name__ == "__main__":
    main()

