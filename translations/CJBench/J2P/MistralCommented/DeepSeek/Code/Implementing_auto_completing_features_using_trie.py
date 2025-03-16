class TrieNode:
    ALPHABET_SIZE = 26

    def __init__(self):
        self.children = [None] * TrieNode.ALPHABET_SIZE
        self.is_word_end = False

def get_node():
    return TrieNode()

def insert(root, key):
    current_node = root
    for level in range(len(key)):
        index = ord(key[level]) - ord('a')
        if current_node.children[index] is None:
            current_node.children[index] = get_node()
        current_node = current_node.children[index]
    current_node.is_word_end = True

def search(root, key):
    current_node = root
    for level in range(len(key)):
        index = ord(key[level]) - ord('a')
        if current_node.children[index] is None:
            return False
        current_node = current_node.children[index]
    return current_node is not None and current_node.is_word_end

def is_last_node(root):
    for i in range(TrieNode.ALPHABET_SIZE):
        if root.children[i] is not None:
            return False
    return True

def suggestions_rec(root, curr_prefix):
    if root.is_word_end:
        print(curr_prefix)
    if is_last_node(root):
        return
    for i in range(TrieNode.ALPHABET_SIZE):
        if root.children[i] is not None:
            suggestions_rec(root.children[i], curr_prefix + chr(97 + i))

def print_auto_suggestions(root, query):
    current_node = root
    level = 0
    n = len(query)
    for level in range(n):
        index = ord(query[level]) - ord('a')
        if current_node.children[index] is None:
            return 0
        current_node = current_node.children[index]
    is_word = current_node.is_word_end
    is_last = is_last_node(current_node)
    if is_word and is_last:
        print(query)
        return -1
    if not is_last:
        suggestions_rec(current_node, query)
        return 1
    return 0

# Main function
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    words = data[1:]

    root = get_node()

    for word in words:
        insert(root, word)

    prefix = data[words.index(input().strip()) + 1]
    suggestions_count = print_auto_suggestions(root, prefix)

    if suggestions_count == -1:
        print("No other strings found with this prefix\n")
    elif suggestions_count == 0:
        print("No string found with this prefix\n")
