# Importing necessary modules
import sys

def main():
    n = int(input())  # Read the number of elements (n) from the user
    a = list(map(int, input().split()))  # Read the elements of the array 'a' from the user
    r = 0  # Initialize a variable 'r' to store the result of XOR operation

    # Perform XOR operation on each element
    for num in a:
        r ^= num

    # Print the result of XOR operation for each element in the array 'a'
    result = []
    for num in a:
        result.append(r ^ num)  # Calculate the result for each element

    print(" ".join(map(str, result)))  # Print the results as a space-separated string

if __name__ == "__main__":
    main()

# <END-OF-CODE>
