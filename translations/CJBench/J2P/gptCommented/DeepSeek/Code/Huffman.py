import heapq

class MainNode:
    def __init__(self, data, char, left=None, right=None):
        self.data = data
        self.char = char
        self.left = left
        self.right = right

class MyComparator(heapq.Comparator):
    def __call__(self, x, y):
        return x.data - y.data

def print_code(root, s):
    if root.left is None and root.right is None and root.char.isalpha():
        print(f"{root.char}: {s}")
        return
    print_code(root.left, s + "0")
    print_code(root.right, s + "1")

if __name__ == "__main__":
    import sys
    input = sys.stdin.readline
    
    n = int(input())
    char_array = [None] * n
    char_freq = [0] * n
    
    for i in range(n):
        char, freq = input().split()
        char_array[i] = char[0]
        char_freq[i] = int(freq)
    
    q = []
    for i in range(n):
        hn = MainNode(char_freq[i], char_array[i])
        heapq.heappush(q, hn)
    
    root = None
    
    while len(q) > 1:
        x = heapq.heappop(q)
        y = heapq.heappop(q)
        
        f = MainNode(x.data + y.data, '-')
        f.left = x
        f.right = y
        
        root = f
        heapq.heappush(q, f)
    
    print_code(root, "")
