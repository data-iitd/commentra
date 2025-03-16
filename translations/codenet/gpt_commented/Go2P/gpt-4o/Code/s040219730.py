import sys
from collections import defaultdict

MOD = 1000000007  # Modulus value for calculations

class FenwickTree:
    def __init__(self, n):
        self.dat = [0] * (n + 1)  # Array to store the tree data
        self.n = n  # Number of elements

    def sum(self, i):
        s = 0  # Variable to hold the sum
        while i > 0:
            s += self.dat[i]  # Add the current index value to the sum
            i -= i & (-i)  # Move to the parent index
        return s  # Return the calculated sum

    def add(self, i, x):
        while i <= self.n:
            self.dat[i] += x  # Add x to the current index
            i += i & (-i)  # Move to the next index

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Number of elements
    q = int(data[1])  # Number of queries
    C = list(map(int, data[2:n + 2]))  # Read the slice of integers

    P = [-1] * (500000 + 50)  # Array to track the last position of each value
    Answers = [0] * (500000 + 50)  # Array to hold the answers for each query
    queries = []  # List to hold the queries

    index = n + 2
    for i in range(q):
        l = int(data[index])
        r = int(data[index + 1])
        queries.append((i, l, r))  # Create a new query
        index += 2

    # Sort the queries based on the right bound
    queries.sort(key=lambda x: x[2])
    ft = FenwickTree(500000 + 50)  # Initialize a Fenwick Tree for range queries

    k = 0  # Pointer to track the current position in the input array
    # Process each query
    for idx, l, r in queries:
        # Update the Fenwick Tree for all elements up to the right bound of the current query
        while k < r:
            if P[C[k]] != -1:  # If the current value has been seen before
                ft.add(P[C[k]] + 1, -1)  # Remove its previous occurrence from the Fenwick Tree
            P[C[k]] = k  # Update the last position of the current value
            ft.add(k + 1, 1)  # Add the current value to the Fenwick Tree
            k += 1  # Move to the next position

        # Calculate the answer for the current query using the Fenwick Tree
        Answers[idx] = ft.sum(r) - ft.sum(l - 1)

    # Output the answers for all queries
    for i in range(q):
        print(Answers[i])  # Print each answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>
