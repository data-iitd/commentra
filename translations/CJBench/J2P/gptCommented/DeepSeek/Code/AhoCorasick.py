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
        for i in range(len(self.patterns)):
            curr = self.root
            for c in self.patterns[i]:
                curr = curr.child.setdefault(c, Node())
            curr.pattern_ind = i

    def build_suffix_and_output_links(self):
        self.root.suffix_link = self.root
        queue = [self.root]

        while queue:
            current = queue.pop(0)
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

        for i in range(len(text)):
            ch = text[i]
            while current != self.root and ch not in current.child:
                current = current.suffix_link
            if ch in current.child:
                current = current.child[ch]
            temp = current

            while temp:
                if temp.pattern_ind != -1:
                    matches[self.patterns[temp.pattern_ind]].append(i - len(self.patterns[temp.pattern_ind]) + 1)
                temp = temp.output_link

        return matches

# Main function to run the program
def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    text = data[0]
    pattern_count = int(data[1])
    patterns = data[2:]

    trie = Trie(patterns)
    result = trie.search(text)

    print("Pattern matches:")
    for pattern, indices in result.items():
        print(f"{pattern}: {indices}")

if __name__ == "__main__":
    main()
