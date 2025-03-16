
import queue

class Node:
    def __init__(self):
        self.children = {}
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
            current = self.root
            for ch in pattern:
                current = current.children.setdefault(ch, Node())
            current.pattern_ind = i

    def build_suffix_and_output_links(self):
        queue = queue.Queue()
        self.root.suffix_link = self.root
        for child in self.root.children.values():
            child.suffix_link = self.root
            queue.put(child)

        while not queue.empty():
            current = queue.get()
            for ch, child in current.children.items():
                suffix = current.suffix_link
                while suffix!= self.root and ch not in suffix.children:
                    suffix = suffix.suffix_link
                if ch in suffix.children:
                    suffix = suffix.children[ch]
                child.suffix_link = suffix
                if suffix.pattern_ind!= -1:
                    child.output_link = suffix
                else:
                    child.output_link = suffix.output_link
                queue.put(child)

    def search(self, text):
        matches = {pattern: [] for pattern in self.patterns}
        current = self.root
        for i, ch in enumerate(text):
            while current!= self.root and ch not in current.children:
                current = current.suffix_link
            if ch in current.children:
                current = current.children[ch]
            temp = current
            while temp is not None:
                if temp.pattern_ind!= -1:
                    matches[self.patterns[temp.pattern_ind]].append(i - len(self.patterns[temp.pattern_ind]) + 1)
                temp = temp.output_link
        return matches

if __name__ == "__main__":
    text = input()
    pattern_count = int(input())
    patterns = [input() for _ in range(pattern_count)]
    trie = Trie(patterns)
    result = trie.search(text)
    print("Pattern matches:")
    for pattern in patterns:
        print(f"{pattern}: {result[pattern]}")

