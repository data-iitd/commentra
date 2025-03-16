import sys
from functools import cmp_to_key

# Define a large number to represent infinity
INF = (1 << 62) - (1 << 31)

# Define a function to sort edges based on the string and then by the long long value
def esort(a, b):
    cmp = (a[0] > b[0]) - (a[0] < b[0])  # Compare strings
    if cmp != 0:
        return cmp
    return (b[1] > a[1]) - (b[1] < a[1])  # Compare long long values in descending order

# Main function
def main():
    # Read the number of edges
    n = int(sys.stdin.readline().strip())

    # Read each edge's string and long long value, and store the index
    data = []
    for i in range(n):
        s, p = sys.stdin.readline().strip().split()
        p = int(p)
        data.append((s, p, i))

    # Sort the edges using the custom esort function
    data.sort(key=cmp_to_key(esort))

    # Print the indices of the edges in the sorted order
    for i in range(n):
        print(data[i][2] + 1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
