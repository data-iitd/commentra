class TrieNode:
    # TrieNode class representing each node in the Trie
    def __init__(self):
        self.children = [None] * 26  # Array of children nodes
        self.is_word_end = False  # Boolean flag to indicate if the node marks the end of a word


class Trie:
    ALPHABET_SIZE = 26  # Constant representing the size of the alphabet (26 letters)

    @staticmethod
    def get_node():
        # Method to create and initialize a new TrieNode
        return TrieNode()

    @staticmethod
    def insert(root, key):
        # Method to insert a new key (word) into the Trie
        p_crawl = root  # Start from the root node
        for level in range(len(key)):
            index = ord(key[level]) - ord('a')  # Calculate index for the character
            if p_crawl.children[index] is None:
                p_crawl.children[index] = Trie.get_node()  # Create a new node if it doesn't exist
            p_crawl = p_crawl.children[index]  # Move to the child node
        p_crawl.is_word_end = True  # Mark the end of the word

    @staticmethod
    def search(root, key):
        # Method to search for a key (word) in the Trie
        p_crawl = root  # Start from the root node
        for level in range(len(key)):
            index = ord(key[level]) - ord('a')  # Calculate index for the character
            if p_crawl.children[index] is None:
                return False  # Key not found
            p_crawl = p_crawl.children[index]  # Move to the child node
        return p_crawl is not None and p_crawl.is_word_end  # Return true if it's the end of a word

    @staticmethod
    def is_last_node(node):
        # Method to check if the current node is the last node (no children)
        for child in node.children:
            if child is not None:
                return False
        return True  # No children exist

    @staticmethod
    def suggestions_rec(node, curr_prefix):
        # Recursive method to find and print suggestions based on the current prefix
        if node.is_word_end:
            print(curr_prefix)  # Print the prefix if it's a word
        if Trie.is_last_node(node):
            return
        for i in range(Trie.ALPHABET_SIZE):
            if node.children[i] is not None:
                Trie.suggestions_rec(node.children[i], curr_prefix + chr(97 + i))  # Recursively call for children

    @staticmethod
    def print_auto_suggestions(root, query):
        # Method to print auto-suggestions for a given query
        p_crawl = root  # Start from the root node
        for level in range(len(query)):
            index = ord(query[level]) - ord('a')  # Calculate index for the character
            if p_crawl.children[index] is None:
                return 0  # No suggestions found
            p_crawl = p_crawl.children[index]  # Move to the child node
        is_word = p_crawl.is_word_end
        is_last = Trie.is_last_node(p_crawl)
        if is_word and is_last:
            print(query)  # Print the query if it's a word and the last node
            return -1
        if not is_last:
            Trie.suggestions_rec(p_crawl, query)  # Print suggestions
            return 1  # Suggestions found
        return 0  # No suggestions found


# Main method to run the Trie operations
if __name__ == "__main__":
    n = int(input())  # Read the number of words to insert
    root = Trie.get_node()  # Create the root node of the Trie
    for _ in range(n):
        Trie.insert(root, input().strip())  # Insert each word into the Trie
    prefix = input().strip()  # Read the prefix for suggestions
    comp = Trie.print_auto_suggestions(root, prefix)  # Get suggestions based on the prefix
    if comp == -1:
        print("No other strings found with this prefix\n")
    elif comp == 0:
        print("No string found with this prefix\n")

# <END-OF-CODE>
