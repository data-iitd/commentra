from collections import defaultdict  # Importing defaultdict for easier graph representation
import sys  # Importing sys for handling input

class Calculator:
    def __init__(self, n, k, as_list):
        self.k = k  # Variable to store the value of k
        self.answer = 0  # Variable to store the answer
        self.is_calculate = False  # Flag to check if calculation has been done
        self.lists = defaultdict(list)  # Dictionary to store the adjacency list representation of the graph

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

        if pre > 0 and h == self.k - 1:  # Checking if the current node is at the desired height k - 1 from the previous node
            h = 0  # Resetting the height to 0 if it is
            self.answer += 1  # Incrementing the answer if the current node is at the desired height
        else:
            h += 1  # Incrementing the height if the current node is not the base case

        return h  # Returning the height of the current node

def main():
    input = sys.stdin.read  # Reading all input at once
    data = input().split()  # Splitting the input into a list of strings
    n = int(data[0])  # Reading the number of test cases
    k = int(data[1])  # Reading the value of k

    # Reading input values for the array as_list
    as_list = [int(data[i]) - 1 for i in range(2, 2 + n)]  # Adjusting indices by subtracting 1

    # Printing the result of the calculation
    print(Calculator(n, k, as_list).calculate())

if __name__ == "__main__":
    main()  # Running the main function

# <END-OF-CODE>
