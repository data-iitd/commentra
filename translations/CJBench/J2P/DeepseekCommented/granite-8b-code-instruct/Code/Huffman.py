
import heapq

# Define the MainNode class
# This class represents a node in the Main tree. It contains:
# - data: an integer representing the frequency of the character.
# - c: a character.
# - left and right: references to the left and right children of the node.
class MainNode:
    def __init__(self, data, c):
        self.data = data
        self.c = c
        self.left = None
        self.right = None

# Define the MyComparator class
# This class implements the __lt__ method to compare MainNode objects based on their data field.
class MyComparator:
    def __init__(self):
        pass

    def __lt__(self, other):
        return self.data < other.data

# Define the Main class
# This class contains the main method for the Main coding program.
class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # Implement the printCode method
    # This method takes a root node and a String representing the code, and recursively prints the Main codes for each character.
    @staticmethod
    def printCode(root, s):
        if root.left is None and root.right is None and root.c.isalpha():
            print(root.c + ": " + s)
            return
        Main.printCode(root.left, s + "0")
        Main.printCode(root.right, s + "1")

    # Implement the main method
    # This method reads the input, creates a heap of MainNode objects, constructs the Main tree, and finally prints the Main codes.
    @staticmethod
    def main():
        n = int(input())
        charArray = []
        charfreq = []
        for i in range(n):
            input_str = input()
            input_list = input_str.split(" ")
            charArray.append(input_list[0][0])
            charfreq.append(int(input_list[1]))
        h = []
        for i in range(n):
            hn = MainNode(charfreq[i], charArray[i])
            hn.left = None
            hn.right = None
            heapq.heappush(h, hn)
        root = None
        while len(h) > 1:
            x = heapq.heappop(h)
            y = heapq.heappop(h)
            f = MainNode(x.data + y.data, "-")
            f.left = x
            f.right = y
            root = f
            heapq.heappush(h, f)
        Main.printCode(root, "")

# Call the main method
Main.main()

# End of code
