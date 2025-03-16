import sys
from collections import defaultdict, deque

class Calculator:
    def __init__(self, n, k, as_list):
        self.k = k
        self.answer = 0
        self.is_calculate = False
        self.lists = defaultdict(list)

        # Building the adjacency list representation of the graph
        for i in range(n):
            j = as_list[i]
            if i > 0:
                self.lists[j].append(i)  # Adding the index of the current node to the list of neighbors of node j
            elif j > 0:
                self.answer += 1  # Incrementing the answer if the input array contains a negative index

    def calculate(self):
        if not self.is_calculate:
            self.dfs(0, -1)  # Performing Depth First Search (DFS) traversal starting from node 0 with previous node as -1
            self.is_calculate = True
        return self.answer

    def dfs(self, a, pre):
        h = 0  # Variable to store the height of the current node in the DFS tree

        for i in self.lists[a]:  # Iterating through the neighbors of the current node
            h = max(h, self.dfs(i, a))  # Updating the height by calling the dfs recursively on the neighbor and taking the maximum height

        if pre != -1 and h == self.k - 1:  # Checking if the current node is at the desired height k - 1 from the previous node
            h = 0  # Resetting the height to 0 if it is
            self.answer += 1  # Incrementing the answer if the current node is at the desired height
        else:
            h += 1  # Incrementing the height if the current node is not the base case

        return h  # Returning the height of the current node

def main():
    # Reading input values for n and k
    n = int(sys.stdin.readline().strip())
    k = int(sys.stdin.readline().strip())

    # Reading input values for the array as
    as_list = list(map(lambda x: int(x) - 1, sys.stdin.readline().strip().split()))

    # Creating an instance of Calculator and calculating the result
    calculator = Calculator(n, k, as_list)
    result = calculator.calculate()

    # Printing the result of the calculation
    print(result)

if __name__ == "__main__":
    main()

