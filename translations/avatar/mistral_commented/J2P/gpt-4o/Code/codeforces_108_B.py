# Importing the necessary modules
import sys

def main():
    n = int(input())  # Reading the number of elements in the array from user input
    a = list(map(int, input().split()))  # Creating a list of integers from user input

    # Sorting the array in ascending order
    a.sort()

    # Checking if there is any pair of adjacent elements that satisfy the condition
    for i in range(len(a) - 1):
        # Checking if the next element is less than twice the current element and they are not the same
        if a[i + 1] < a[i] * 2 and a[i] != a[i + 1]:
            print("YES")  # Printing "YES" if a pair is found
            return  # Exiting the function if a pair is found

    # If no pair is found, printing "NO"
    print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
