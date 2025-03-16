
class Node:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None

class Tree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root == None:
            self.root = Node(key)
            return

        currentNode = self.root
        while currentNode!= None:
            if currentNode.key < key:
                if currentNode.right == None:
                    currentNode.right = Node(key)
                    currentNode.right.parent = currentNode
                    return
                else:
                    currentNode = currentNode.right
            else:
                if currentNode.left == None:
                    currentNode.left = Node(key)
                    currentNode.left.parent = currentNode
                    return
                else:
                    currentNode = currentNode.left

    def print(self):
        if self.root == None:
            print("")
            print("")
        else:
            print(" " + " ".join(map(str, self.visitInorder(self.root))))
            print(" " + " ".join(map(str, self.visitPreorder(self.root))))

    def visitPreorder(self, node):
        if node == None:
            return []
        acc = [node.key]
        if node.left!= None:
            acc = acc + self.visitPreorder(node.left)
        if node.right!= None:
            acc = acc + self.visitPreorder(node.right)
        return acc

    def visitInorder(self, node):
        if node == None:
            return []
        if node.left!= None:
            acc = self.visitInorder(node.left)
        else:
            acc = []
        acc = acc + [node.key]
        if node.right!= None:
            acc = acc + self.visitInorder(node.right)
        return acc

def main():
    sc = Scanner()
    n = sc.nextInt()

    tree = Tree()
    for i in range(n):
        command = sc.next()
        if command == "insert":
            key = sc.nextInt()
            tree.insert(key)
        elif command == "print":
            tree.print()
        else:
            raise Exception("unknown command: " + command)

class Scanner:
    def __init__(self):
        self.tokens = []
        self.readMore()

    def readMore(self):
        try:
            line = input()
            self.tokens = line.split()
        except EOFError:
            self.tokens = []

    def hasNext(self):
        return len(self.tokens) > 0

    def next(self):
        if not self.hasNext():
            raise Exception("no tokens left")
        self.readMore()
        return self.tokens.pop(0)

    def nextInt(self):
        if not self.hasNext():
            raise Exception("no tokens left")
        token = self.tokens.pop(0)
        try:
            return int(token)
        except ValueError:
            raise Exception("bad token: " + token)

