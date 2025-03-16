import sys
from collections import defaultdict

class Calculator:
    def __init__(self, n, k, as_list):
        self.k = k  # Store the threshold value
        self.answer = 0  # Store the final answer
        self.is_calculate = False  # Flag to check if calculation is done
        self.lists = defaultdict(list)  # Adjacency list representation

        # Build the adjacency list based on the input values
        for i in range(n):
            j = as_list[i]  # Get the corresponding value
            if i > 0:
                self.lists[j].append(i)  # Add edge to the adjacency list
            elif j > 0:
                self.answer += 1  # Increment answer if the condition is met

    def calculate(self):
        # If calculation hasn't been performed yet, start the DFS
        if not self.is_calculate:
            self.dfs(0, 0)  # Start DFS from node 0
            self.is_calculate = True  # Mark calculation as done
        return self.answer  # Return the final answer

    def dfs(self, a, pre):
        h = 0  # Height of the current node
        # Explore all adjacent nodes
        for i in self.lists[a]:
            h = max(h, self.dfs(i, a))  # Recursively find the height
        # Check if the conditions for incrementing the answer are met
        if pre > 0 and h == self.k - 1:
            h = 0  # Reset height if condition is met
            self.answer += 1  # Increment answer
        else:
            h += 1  # Increment height
        return h  # Return the height

def main():
    # Read input values from the console
    n = int(sys.stdin.readline().strip())  # Read the number of elements
    k = int(sys.stdin.readline().strip())  # Read the threshold value
    as_list = [int(x) - 1 for x in sys.stdin.readline().strip().split()]  # Read n integers and adjust them (subtract 1)

    # Create a Calculator instance and calculate the result, then print it
    print(Calculator(n, k, as_list).calculate())

if __name__ == "__main__":
    main()

# <END-OF-CODE>
