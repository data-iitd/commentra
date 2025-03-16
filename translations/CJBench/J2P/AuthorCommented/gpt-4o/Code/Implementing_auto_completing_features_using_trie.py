class TrieNode:
    def __init__(self):
        self.children = [None] * 26  # Alphabet size (26 letters)
        self.is_word_end = False


class TrieAC:
    @staticmethod
    def get_node():
        return TrieNode()

    @staticmethod
    def insert(root, key):
        p_crawl = root
        for level in range(len(key)):
            index = ord(key[level]) - ord('a')
            if p_crawl.children[index] is None:
                p_crawl.children[index] = TrieAC.get_node()
            p_crawl = p_crawl.children[index]
        p_crawl.is_word_end = True

    @staticmethod
    def search(root, key):
        length = len(key)
        p_crawl = root
        for level in range(length):
            index = ord(key[level]) - ord('a')
            if p_crawl.children[index] is None:
                return False
            p_crawl = p_crawl.children[index]
        return p_crawl is not None and p_crawl.is_word_end

    @staticmethod
    def is_last_node(root):
        for child in root.children:
            if child is not None:
                return False
        return True

    @staticmethod
    def suggestions_rec(root, curr_prefix):
        if root.is_word_end:
            print(curr_prefix)
        if TrieAC.is_last_node(root):
            return
        for i in range(26):
            if root.children[i] is not None:
                TrieAC.suggestions_rec(root.children[i], curr_prefix + chr(97 + i))

    @staticmethod
    def print_auto_suggestions(root, query):
        p_crawl = root
        n = len(query)

        for level in range(n):
            index = ord(query[level]) - ord('a')
            if p_crawl.children[index] is None:
                return 0
            p_crawl = p_crawl.children[index]

        is_word = p_crawl.is_word_end
        is_last = TrieAC.is_last_node(p_crawl)

        if is_word and is_last:
            print(query)
            return -1
        if not is_last:
            TrieAC.suggestions_rec(p_crawl, query)
            return 1
        return 0


# Driver code
if __name__ == "__main__":
    n = int(input())
    root = TrieAC.get_node()

    for _ in range(n):
        TrieAC.insert(root, input().strip())

    prefix = input().strip()
    comp = TrieAC.print_auto_suggestions(root, prefix)

    if comp == -1:
        print("No other strings found with this prefix\n")
    elif comp == 0:
        print("No string found with this prefix\n")

# <END-OF-CODE>
