class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.is_word_end = False

def get_node():
    return TrieNode()

def insert(root, key):
    p_crawl = root
    for level in range(len(key)):
        index = ord(key[level]) - ord('a')
        if not p_crawl.children[index]:
            p_crawl.children[index] = get_node()
        p_crawl = p_crawl.children[index]
    p_crawl.is_word_end = True

def search(root, key):
    p_crawl = root
    for level in range(len(key)):
        index = ord(key[level]) - ord('a')
        if not p_crawl.children[index]:
            return False
        p_crawl = p_crawl.children[index]
    return p_crawl is not None and p_crawl.is_word_end

def is_last_node(root):
    return all(not child for child in root.children)

def suggestions_rec(root, curr_prefix):
    if root.is_word_end:
        print(curr_prefix)
    if is_last_node(root):
        return
    for i in range(26):
        if root.children[i]:
            suggestions_rec(root.children[i], curr_prefix + chr(97 + i))

def print_auto_suggestions(root, query):
    p_crawl = root
    for level in range(len(query)):
        index = ord(query[level]) - ord('a')
        if not p_crawl.children[index]:
            return 0
        p_crawl = p_crawl.children[index]
    is_word = p_crawl.is_word_end
    is_last = is_last_node(p_crawl)
    if is_word and is_last:
        print(query)
        return -1
    if not is_last:
        suggestions_rec(p_crawl, query)
        return 1
    return 0

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    root = get_node()
    for i in range(1, n + 1):
        insert(root, data[i])
    prefix = data[n + 1]
    comp = print_auto_suggestions(root, prefix)
    if comp == -1:
        print("No other strings found with this prefix")
    elif comp == 0:
        print("No string found with this prefix")
