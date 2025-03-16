
# Binary search tree
#
# <NAME>
# University of Illinois
#

class node:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None

class tree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root == None:
            self.root = node(key)
            return

        currentNode = self.root
        for currentNode!= None:
            if currentNode.key < key:
                if currentNode.right == None:
                    currentNode.right = node(key)
                    currentNode.right.parent = currentNode
                    return
                else:
                    currentNode = currentNode.right
            else:
                if currentNode.left == None:
                    currentNode.left = node(key)
                    currentNode.left.parent = currentNode
                    return
                else:
                    currentNode = currentNode.left

    def print(self):
        if self.root == None:
            print("")
            print("")
        else:
            print(" " + " ".join(self.isToAs(self.visitInorder(self.root, []))))
            print(" " + " ".join(self.isToAs(self.visitPreorder(self.root, []))))

    def visitPreorder(self, node, acc):
        if node == None:
            return acc
        acc.append(node.key)
        if node.left!= None:
            acc = self.visitPreorder(node.left, acc)
        if node.right!= None:
            acc = self.visitPreorder(node.right, acc)
        return acc

    def visitInorder(self, node, acc):
        if node == None:
            return acc
        if node.left!= None:
            acc = self.visitInorder(node.left, acc)
        acc.append(node.key)
        if node.right!= None:
            acc = self.visitInorder(node.right, acc)
        return acc

    def isToAs(self, is):
        n = len(is)
        as = [None] * n
        for i in range(n):
            as[i] = str(is[i])
        return as

# main function reads commands from standard input.
# It supports two commands: insert to add a key to the tree and print to print the tree.
# It uses helper functions nextText and nextInt to read input values.
def main():
    sc = bufio.NewScanner(sys.stdin)
    sc.Split(bufio.ScanWords)

    n, err = nextInt(sc)
    if err!= None:
        raise(err)

    tree = tree()
    for i in range(n):
        command = nextText(sc)
        if command == "insert":
            key, err = nextInt(sc)
            if err!= None:
                raise(err)
            tree.insert(key)
        elif command == "print":
            tree.print()
        else:
            raise("unknown command: " + command)

# nextText reads a single word from the scanner.
def nextText(sc):
    sc.Scan()
    return sc.Text()

# nextInt reads an integer from the scanner by converting the text output of nextText to an integer.
def nextInt(sc):
    return int(nextText(sc))

# isToAs converts a slice of integers to a slice of strings.
def isToAs(is):
    n = len(is)
    as = [None] * n
    for i in range(n):
        as[i] = str(is[i])
    return as

