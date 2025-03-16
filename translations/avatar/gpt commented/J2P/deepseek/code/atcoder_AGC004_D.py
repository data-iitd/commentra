import sys
from typing import List

class MyRunnable:
    def run(self):
        n = int(input().strip())  # Number of elements
        k = int(input().strip())  # A specific threshold value
        as_ = list(map(int, input().strip().split()))  # List to store input values

        # Create a Calculator instance and calculate the result, then print it
        print(Calculator(n, k, as_).calculate())

class Calculator:
    def __init__(self, n: int, k: int, as_: List[int]):
        self.k = k  # Store the threshold value
        self.answer = 0  # Store the final answer
        self.is_calculate = False  # Flag to check if calculation is done
        self.lists = [[] for _ in range(n)]  # Adjacency list representation

        # Build the adjacency list based on the input values
        for i in range(n):
            j = as_[i] - 1  # Get the corresponding value
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

    def dfs(self, a: int, pre: int):
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

# Start a new thread to run the MyRunnable class
if __name__ == "__main__":
    MyRunnable().run()
