class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.is_word_end = False

class Trie:
    ALPHABET_SIZE = 26

    def __init__(self):
        self.root = self.get_node()

    def get_node(self):
        return TrieNode()

    def insert(self, key):
        p_crawl = self.root
        for level in range(len(key)):
            index = ord(key[level]) - ord('a')
            if p_crawl.children[index] is None:
                p_crawl.children[index] = self.get_node()
            p_crawl = p_crawl.children[index]
        p_crawl.is_word_end = True

    def search(self, key):
        length = len(key)
        p_crawl = self.root
        for level in range(length):
            index = ord(key[level]) - ord('a')
            if p_crawl.children[index] is None:
                return False
            p_crawl = p_crawl.children[index]
        return p_crawl is not None and p_crawl.is_word_end

    def is_last_node(self, node):
        for child in node.children:
            if child is not None:
                return False
        return True

    def suggestions_rec(self, node, curr_prefix):
        if node.is_word_end:
            print(curr_prefix)
        if self.is_last_node(node):
            return
        for i in range(self.ALPHABET_SIZE):
            if node.children[i] is not None:
                self.suggestions_rec(node.children[i], curr_prefix + chr(97 + i))

    def print_auto_suggestions(self, query):
        p_crawl = self.root
        n = len(query)
        for level in range(n):
            index = ord(query[level]) - ord('a')
            if p_crawl.children[index] is None:
                return 0
            p_crawl = p_crawl.children[index]
        is_word = p_crawl.is_word_end
        is_last = self.is_last_node(p_crawl)
        if is_word and is_last:
            print(query)
            return -1
        if not is_last:
            self.suggestions_rec(p_crawl, query)
            return 1
        return 0

if __name__ == "__main__":
    n = int(input())
    trie = Trie()
    for _ in range(n):
        trie.insert(input().strip())
    prefix = input().strip()
    comp = trie.print_auto_suggestions(prefix)
    if comp == -1:
        print("No other strings found with this prefix\n")
    elif comp == 0:
        print("No string found with this prefix\n")

# <END-OF-CODE>
