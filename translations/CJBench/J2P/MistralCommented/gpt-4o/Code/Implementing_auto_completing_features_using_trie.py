class TrieNode:
    ALPHABET_SIZE = 26

    def __init__(self):
        self.children = [None] * self.ALPHABET_SIZE
        self.is_word_end = False


class Trie:
    def __init__(self):
        self.root = self.get_node()

    @staticmethod
    def get_node():
        return TrieNode()

    def insert(self, key):
        current_node = self.root
        for level in range(len(key)):
            index = ord(key[level]) - ord('a')
            if current_node.children[index] is None:
                current_node.children[index] = self.get_node()
            current_node = current_node.children[index]
        current_node.is_word_end = True

    def search(self, key):
        current_node = self.root
        for level in range(len(key)):
            index = ord(key[level]) - ord('a')
            if current_node.children[index] is None:
                return False
            current_node = current_node.children[index]
        return current_node is not None and current_node.is_word_end

    @staticmethod
    def is_last_node(node):
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
        current_node = self.root
        n = len(query)
        for level in range(n):
            index = ord(query[level]) - ord('a')
            if current_node.children[index] is None:
                return 0
            current_node = current_node.children[index]
        is_word = current_node.is_word_end
        is_last = self.is_last_node(current_node)
        if is_word and is_last:
            print(query)
            return -1
        if not is_last:
            self.suggestions_rec(current_node, query)
            return 1
        return 0


if __name__ == "__main__":
    n = int(input())  # Read the number of words to be inserted into Trie
    trie = Trie()  # Create a Trie object

    # Insert words into Trie
    for _ in range(n):
        word = input().strip()  # Read a word from the input
        trie.insert(word)  # Insert the word into Trie

    prefix = input().strip()  # Read the prefix for suggestions
    suggestions_count = trie.print_auto_suggestions(prefix)  # Print auto-suggestions based on the prefix

    if suggestions_count == -1:
        print("No other strings found with this prefix\n")  # If the prefix is a word and there are no other words with the same prefix
    elif suggestions_count == 0:
        print("No string found with this prefix\n")  # If there is no word with the given prefix

# <END-OF-CODE>
