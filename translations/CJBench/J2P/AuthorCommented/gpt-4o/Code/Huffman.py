import heapq

# Node class is the basic structure of each node present in the Huffman tree.
class MainNode:
    def __init__(self, data, c):
        self.data = data
        self.c = c
        self.left = None
        self.right = None

# Comparator class helps to compare the node on the basis of one of its attributes.
class MyComparator:
    def __call__(self, x):
        return x.data

def print_code(root, s):
    if root.left is None and root.right is None and root.c.isalpha():
        # c is the character in the node
        print(f"{root.c}: {s}")
        return

    # if we go to left then add "0" to the code.
    # if we go to the right add "1" to the code.
    print_code(root.left, s + "0")
    print_code(root.right, s + "1")

def main():
    n = int(input().strip())

    char_array = []
    char_freq = []

    for _ in range(n):
        input_data = input().strip().split()
        char_array.append(input_data[0])
        char_freq.append(int(input_data[1]))

    # Create a priority queue (min-heap)
    priority_queue = []
    
    for i in range(n):
        # creating a MainNode object and add it to the priority queue.
        hn = MainNode(char_freq[i], char_array[i])
        heapq.heappush(priority_queue, hn)

    root = None

    # Here we will extract the two minimum values from the heap each time until its size reduces to 1.
    while len(priority_queue) > 1:
        x = heapq.heappop(priority_queue)
        y = heapq.heappop(priority_queue)

        # new node f which is equal to the sum of the frequency of the two nodes
        f = MainNode(x.data + y.data, '-')
        # first extracted node as left child.
        f.left = x
        # second extracted node as the right child.
        f.right = y

        # marking the f node as the root node.
        root = f
        # add this node to the priority queue.
        heapq.heappush(priority_queue, f)

    # print the codes by traversing the tree
    print_code(root, "")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
