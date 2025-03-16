import sys

def main():
    n = int(input().strip())  # Reading the size of the array
    a = list(map(int, input().strip().split()))  # Reading the array elements

    r = []  # Declaring a list to store the operations
    m = 0  # Initializing the index of the maximum absolute value element

    # Finding the index of the element with the maximum absolute value in the array 'a'
    for i in range(1, n):
        if abs(a[m]) < abs(a[i]):
            m = i

    # Finding pairs of indices where one element is non-negative and the other is negative
    for i in range(n):
        if a[m] >= 0 != a[i] >= 0:  # Using != to check if one is non-negative and the other is negative
            r.append(f"{m + 1} {i + 1}")  # Adding the operation to the list 'r'

    # Generating operations based on whether the maximum absolute value element is non-negative or negative
    if a[m] >= 0:
        for i in range(n - 1):
            r.append(f"{i + 1} {i + 2}")  # Adding the operation to the list 'r'
    else:
        for i in range(n - 1):
            r.append(f"{n - i} {n - i - 1}")  # Adding the operation to the list 'r'

    # Printing the number of operations and the operations themselves
    print(len(r))
    for operation in r:
        print(operation)

if __name__ == "__main__":
    main()
