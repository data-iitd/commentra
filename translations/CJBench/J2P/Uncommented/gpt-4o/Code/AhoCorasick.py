from collections import defaultdict, deque

class Node:
    def __init__(self):
        self.child = {}
        self.suffix_link = None
        self.output_link = None
        self.pattern_ind = -1

class Trie:
    def __init__(self, patterns):
        self.root = Node()
        self.patterns = patterns
        self.build_trie()
        self.build_suffix_and_output_links()

    def build_trie(self):
        for i, pattern in enumerate(self.patterns):
            curr = self.root
            for c in pattern:
                if c not in curr.child:
                    curr.child[c] = Node()
                curr = curr.child[c]
            curr.pattern_ind = i

    def build_suffix_and_output_links(self):
        self.root.suffix_link = self.root
        queue = deque()
        for child in self.root.child.values():
            child.suffix_link = self.root
            queue.append(child)

        while queue:
            current = queue.popleft()
            for ch, child in current.child.items():
                suffix = current.suffix_link
                while suffix != self.root and ch not in suffix.child:
                    suffix = suffix.suffix_link
                if ch in suffix.child:
                    suffix = suffix.child[ch]
                child.suffix_link = suffix
                if suffix.pattern_ind != -1:
                    child.output_link = suffix
                else:
                    child.output_link = suffix.output_link
                queue.append(child)

    def search(self, text):
        matches = {pattern: [] for pattern in self.patterns}
        current = self.root
        for i, ch in enumerate(text):
            while current != self.root and ch not in current.child:
                current = current.suffix_link
            if ch in current.child:
                current = current.child[ch]
            temp = current
            while temp is not None:
                if temp.pattern_ind != -1:
                    matches[self.patterns[temp.pattern_ind]].append(i - len(self.patterns[temp.pattern_ind]) + 1)
                temp = temp.output_link
        return matches

def main():
    text = input()
    pattern_count = int(input())
    patterns = [input().strip() for _ in range(pattern_count)]
    trie = Trie(patterns)
    result = trie.search(text)
    print("Pattern matches:")
    for pattern in patterns:
        print(f"{pattern}: {result[pattern]}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
