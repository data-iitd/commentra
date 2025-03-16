import heapq

# Define the MainNode class
# This class represents a node in the Main tree. It contains:
# - data: an integer representing the frequency of the character.
# - c: a character.
# - left and right: references to the left and right children of the node.
class MainNode:
    def __init__(self, data, c, left, right):
        self.data = data
        self.c = c
        self.left = left
        self.right = right

# Define the MyComparator class
# This class implements the Comparator interface to compare MainNode objects based on their data field.
class MyComparator:
    def __init__(self):
        pass
    def compare(self, x, y):
        return x.data - y.data

# Define the Main class
# This class contains the main method for the Main coding program.
class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # Implement the printCode method
    # This method takes a root node and a String representing the code, and recursively prints the Main codes for each character.
    def printCode(self, root, s):
        if root.left == None and root.right == None and root.c.isalpha():
            print(root.c + ": " + s)
            return
        self.printCode(root.left, s + "0")
        self.printCode(root.right, s + "1")

    # Implement the main method
    # This method reads the input, creates a priority queue of MainNode objects, constructs the Main tree, and finally prints the Main codes.
    def main(self):
        sc = Scanner(System.in)
        n = sc.nextInt()
        sc.nextLine() 
        charArray = [None] * n
        charfreq = [None] * n
        for i in range(n):
            input = sc.nextLine().split(" ")
            charArray[i] = input[0].charAt(0)
            charfreq[i] = int(input[1])
        q = PriorityQueue(n, MyComparator())
        for i in range(n):
            hn = MainNode(charfreq[i], charArray[i], None, None)
            q.add(hn)
        root = None
        while q.size() > 1:
            x = q.poll()
            y = q.poll()
            f = MainNode(x.data + y.data, '-', x, y)
            root = f
            q.add(f)
        self.printCode(root, "")
        sc.close()

# Main method
if __name__ == "__main__":
    Main().main()

