import sys

def main():
    # Reading an integer n from standard input, which represents the number of elements
    n = int(sys.stdin.readline().strip())
    
    # Initializing a list to store the indices of elements that are equal to 1
    arr = []

    # Looping through the input values to find indices of elements equal to 1
    elements = list(map(int, sys.stdin.readline().strip().split()))
    for i in range(n):
        # If the input value is 1, add the current index to the list
        if elements[i] == 1:
            arr.append(i)

    # Checking if the list of indices is empty
    if not arr:
        # If the list is empty, print 0
        print(0)
    else:
        # If the list is not empty, initialize a result variable to 1
        result = 1

        # Calculate the product of the differences between consecutive indices
        for i in range(1, len(arr)):
            result *= arr[i] - arr[i - 1]

        # Print the final result
        print(result)

if __name__ == "__main__":
    main()
