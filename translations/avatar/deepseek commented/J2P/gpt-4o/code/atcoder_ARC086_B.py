import sys

def main():
    n = int(sys.stdin.readline().strip())  # Reading the size of the array
    a = list(map(int, sys.stdin.readline().strip().split()))  # Filling the array 'a' with 'n' integers from input

    r = []  # Declaring a list to store the operations
    m = 0  # Initializing the index of the maximum absolute value element

    # Finding the index of the element with the maximum absolute value in the array 'a'
    for i in range(1, n):
        if abs(a[m]) < abs(a[i]):
            m = i

    # Finding pairs of indices where one element is non-negative and the other is negative
    for i in range(n):
        if (a[m] >= 0) ^ (a[i] >= 0):  # Using XOR to check if one is non-negative and the other is negative
            r.append(f"{m + 1} {i + 1}")  # Adding the operation to the list 'r'

    # Generating operations based on whether the maximum absolute value element is non-negative or negative
    if a[m] >= 0:
        for i in range(1, n):
            r.append(f"{i + 1} {i + 2}")  # Adding the operation to the list 'r'
    else:
        for i in range(n, 1, -1):
            r.append(f"{i} {i - 1}")  # Adding the operation to the list 'r'

    # Printing the number of operations and the operations themselves
    print(len(r))
    print("\n".join(r))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
