import sys

def main():
    # Reading the number of elements in the list from the input
    n = int(sys.stdin.readline().strip())

    # Creating a list to store the elements
    lst = []

    # Reading 'n' elements from the input and adding them to the list
    for _ in range(n):
        lst.append(int(sys.stdin.readline().strip()))

    # Sorting the list in ascending order
    lst.sort()

    # Initializing a variable 'c' to keep track of the number of distinct elements
    c = 1

    # Iterating through the list to find the number of distinct elements
    for i in range(n):
        # If the current element is greater than or equal to the current count 'c', increment the count
        if lst[i] >= c:
            c += 1

    # Writing the result to the output
    print(c)

# Entry point of the Python application
if __name__ == "__main__":
    main()

# <END-OF-CODE>
