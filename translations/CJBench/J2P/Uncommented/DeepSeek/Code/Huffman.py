from queue import PriorityQueue

class MainNode:
    def __init__(self, data, char, left=None, right=None):
        self.data = data
        self.char = char
        self.left = left
        self.right = right

class MyComparator(MainNode):
    def __lt__(self, other):
        return self.data < other.data

def print_code(root, s):
    if root.left is None and root.right is None and root.char:
        print(f"{root.char}: {s}")
        return
    print_code(root.left, s + "0")
    print_code(root.right, s + "1")

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    char_array = []
    freq_array = []
    index = 1
    for i in range(n):
        char_array.append(data[index])
        freq_array.append(int(data[index + 1]))
        index += 2
    
    pq = PriorityQueue()
    for i in range(n):
        hn = MainNode(freq_array[i], char_array[i])
        pq.put(hn)
    
    root = None
    while pq.qsize() > 1:
        x = pq.get()
        y = pq.get()
        f = MainNode(x.data + y.data, '-', x, y)
        root = f
        pq.put(f)
    
    print_code(root, "")

if __name__ == "__main__":
    main()
