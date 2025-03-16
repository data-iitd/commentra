# Import the necessary module
import sys

def main():
    n = int(sys.stdin.readline().strip())  # Read the number of elements
    arr = []  # Create a list to store the indices of elements equal to 1

    for i in range(n):  # Read the elements and store their indices if they are equal to 1
        if int(sys.stdin.readline().strip()) == 1:
            arr.append(i)

    if not arr:  # Check if the list is empty
        print(0)  # If the list is empty, print 0
    else:
        result = 1  # Initialize the result variable to 1
        for i in range(1, len(arr)):  # Calculate the product of differences between consecutive indices
            result *= arr[i] - arr[i - 1]
        print(result)  # Print the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
