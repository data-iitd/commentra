import heapq

# node class is the basic structure
# of each node present in the Main - tree.
class MainNode:
    def __init__(self, data, c, left, right):
        self.data = data
        self.c = c
        self.left = left
        self.right = right

# comparator class helps to compare the node
# on the basis of one of its attribute.
# Here we will be compared
# on the basis of data values of the nodes.
class MyComparator:
    def __init__(self):
        pass

    def compare(self, x, y):
        return x.data - y.data

def printCode(root, s):
    if root.left == None and root.right == None and root.c.isalpha():
        # c is the character in the node
        print(root.c + ": " + s)
        return

    # if we go to left then add "0" to the code.
    # if we go to the right add"1" to the code.
    # recursive calls for left and
    # right sub-tree of the generated tree.
    printCode(root.left, s + "0")
    printCode(root.right, s + "1")

def main():
    sc = Scanner(System.in)

    n = sc.nextInt()
    sc.nextLine() # Consume newline

    charArray = [None] * n
    charfreq = [None] * n

    for i in range(n):
        input = sc.nextLine().split(" ")
        charArray[i] = input[0].charAt(0)
        charfreq[i] = int(input[1])

    q = PriorityQueue(n, MyComparator())

    for i in range(n):
        # creating a Main node object
        # and add it to the priority queue.
        hn = MainNode(charfreq[i], charArray[i], None, None)
        q.add(hn)

    root = None

    # Here we will extract the two minimum value
    # from the heap each time until
    # its size reduces to 1, extract until
    # all the nodes are extracted.
    while q.size() > 1:
        
        x = q.poll()
        y = q.poll()

        # new node f which is equal
        f = MainNode(0, '-', None, None)
        # to the sum of the frequency of the two nodes
        # assigning values to the f node.
        f.data = x.data + y.data
        f.c = '-'
        # first extracted node as left child.
        f.left = x
        # second extracted node as the right child.
        f.right = y

        # marking the f node as the root node.
        root = f
        # add this node to the priority-queue.
        q.add(f)

    # print the codes by traversing the tree
    printCode(root, "")
    sc.close()

if __name__ == "__main__":
    main()

