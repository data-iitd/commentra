
import sys
import threading

class Main:
    def __init__(self):
        # Start the MyRunnable thread to handle input and output
        threading.Thread(target=MyRunnable()).start()

class MyRunnable(threading.Thread):
    def run(self):
        n = int(sys.stdin.readline()) # Read the number of elements
        k = int(sys.stdin.readline()) # Read the parameter k
        as = [] # List to store input values
        for i in range(n):
            as.append(int(sys.stdin.readline()) - 1) # Read each element and adjust by subtracting 1

        # Initialize the Calculator object and calculate the result
        print(Calculator(n, k, as).calculate())

class Calculator:
    def __init__(self, n, k, as):
        self.k = k
        self.answer = 0
        self.isCalculate = False
        self.lists = []
        for i in range(n):
            self.lists.append([]) # Initialize each list in the lists
        for i in range(n):
            j = as[i]
            if 0 < i:
                self.lists[j].append(i) # Add relationship between elements
            elif 0 < j:
                self.answer += 1 # Increment answer if condition is met

    # Method to calculate the result using DFS
    def calculate(self):
        if not self.isCalculate:
            self.dfs(0, 0) # Start DFS from the root node
            self.isCalculate = True # Set the flag to true
        return self.answer # Return the calculated answer

    # DFS method to traverse through the lists
    def dfs(self, a, pre):
        h = 0 # Variable to store the height of the tree
        for i in self.lists[a]:
            h = max(h, self.dfs(i, a)) # Recursively calculate the height
        if 0 < pre and h == self.k - 1:
            h = 0 # Reset height if condition is met
            self.answer += 1 # Increment answer if condition is met
        else:
            h += 1 # Increment height otherwise
        return h # Return the height

# Start the program
Main()

