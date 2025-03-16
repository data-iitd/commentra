# Import necessary modules
import sys

def main():
    # Read the number of elements in the array
    n = int(input())
    
    # Initialize a list to store the input values
    a = list(map(int, input().split()))
    
    # Sort the list in ascending order
    a.sort()
    
    # Store the minimum value from the sorted list
    min_value = a[0]
    
    # Check if all elements in the list are divisible by the minimum value
    for value in a:
        if value % min_value != 0:
            # If any element is not divisible, print -1 and exit
            print(-1)
            return
    
    # If all elements are divisible, print the minimum value
    print(min_value)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
