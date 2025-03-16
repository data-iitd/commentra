import sys

def main():
    # Start a new thread to run the MyRunnable class
    threading.Thread(target=MyRunnable).start()

class MyRunnable:
    def __init__(self):
        # Use a Scanner to read input values from the console
        sc = Scanner(sys.stdin)
        n = sc.nextInt() # Read the number of elements
        k = sc.nextInt() # Read the threshold value
        as = [] # List to store input values
        # Read n integers and adjust them (subtract 1) before adding to the list
        for i in range(n):
            as.append(sc.nextInt() - 1)

        # Create a Calculator instance and calculate the result, then print it
        print(Calculator(n, k, as).calculate())

class Calculator:
    def __init__(self, n, k, as):
        self.k = k # Set the threshold value
        self.answer = 0 # Store the final answer
        self.isCalculate = False # Flag to check if calculation is done
        self.lists = [] # Adjacency list representation
        # Initialize the adjacency list
        for i in range(n):
            self.lists.append([])
        # Build the adjacency list based on the input values
        for i in range(n):
            j = as[i] # Get the corresponding value
            if i > 0:
                self.lists[j].append(i) # Add edge to the adjacency list
            elif j > 0:
                self.answer += 1 # Increment answer if the condition is met

    # Method to calculate the answer
    def calculate(self):
        # If calculation hasn't been performed yet, start the DFS
        if not self.isCalculate:
            self.dfs(0, 0) # Start DFS from node 0
            self.isCalculate = True # Mark calculation as done
        return self.answer # Return the final answer

    # Depth-First Search (DFS) method to explore the graph
    def dfs(self, a, pre):
        h = 0 # Height of the current node
        # Explore all adjacent nodes
        for i in self.lists[a]:
            h = max(h, self.dfs(i, a)) # Recursively find the height
        # Check if the conditions for incrementing the answer are met
        if pre > 0 and h == self.k - 1:
            h = 0 # Reset height if condition is met
            self.answer += 1 # Increment answer
        else:
            h += 1 # Increment height
        return h # Return the height


