import heapq

class MainNode:
    def __init__(self, data, c):
        self.data = data
        self.c = c
        self.left = None
        self.right = None

class MyComparator:
    def __call__(self, x, y):
        return x.data - y.data

def print_code(root, s):
    if root.left is None and root.right is None and root.c.isalpha():
        print(f"{root.c}: {s}")
        return
    if root.left:
        print_code(root.left, s + "0")
    if root.right:
        print_code(root.right, s + "1")

def main():
    n = int(input())
    char_array = []
    char_freq = []
    
    for _ in range(n):
        input_line = input().split()
        char_array.append(input_line[0])
        char_freq.append(int(input_line[1]))
    
    priority_queue = []
    
    for i in range(n):
        hn = MainNode(char_freq[i], char_array[i])
        heapq.heappush(priority_queue, (hn.data, hn))
    
    root = None
    while len(priority_queue) > 1:
        x = heapq.heappop(priority_queue)[1]
        y = heapq.heappop(priority_queue)[1]
        f = MainNode(x.data + y.data, '-')
        f.left = x
        f.right = y
        root = f
        heapq.heappush(priority_queue, (f.data, f))
    
    print_code(root, "")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
