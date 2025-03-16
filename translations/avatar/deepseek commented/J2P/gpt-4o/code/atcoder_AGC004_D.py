import sys
from collections import defaultdict

class Calculator:
    def __init__(self, n, k, as_list):
        self.k = k
        self.answer = 0
        self.is_calculate = False
        self.lists = defaultdict(list)  # Using defaultdict for easier list initialization

        for i in range(n):
            j = as_list[i]
            if i > 0:
                self.lists[j].append(i)  # Add relationship between elements
            elif j > 0:
                self.answer += 1  # Increment answer if condition is met

    def calculate(self):
        if not self.is_calculate:
            self.dfs(0, 0)  # Start DFS from the root node
            self.is_calculate = True  # Set the flag to true
        return self.answer  # Return the calculated answer

    def dfs(self, a, pre):
        h = 0  # Variable to store the height of the tree
        for i in self.lists[a]:
            h = max(h, self.dfs(i, a))  # Recursively calculate the height
        if pre > 0 and h == self.k - 1:
            h = 0  # Reset height if condition is met
            self.answer += 1  # Increment answer if condition is met
        else:
            h += 1  # Increment height otherwise
        return h  # Return the height

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the number of elements
    k = int(data[1])  # Read the parameter k
    as_list = [int(data[i]) - 1 for i in range(2, 2 + n)]  # Read each element and adjust by subtracting 1

    # Initialize the Calculator object and calculate the result
    print(Calculator(n, k, as_list).calculate())

if __name__ == "__main__":
    main()

# <END-OF-CODE>
