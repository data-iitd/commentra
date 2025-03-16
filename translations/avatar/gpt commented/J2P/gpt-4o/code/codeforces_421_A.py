# Import necessary modules
from typing import List

def main():
    # Read the values for n, a, and b from the input
    n = int(input())
    a = int(input())
    b = int(input())
    
    # Initialize two lists to store the elements of the two lists
    list1 = []
    list2 = []
    
    # Read 'a' integers into list1
    for _ in range(a):
        list1.append(int(input()))
    
    # Read 'b' integers into list2
    for _ in range(b):
        list2.append(int(input()))
    
    # Iterate from 0 to n-1 to check the presence of each index in list1
    for i in range(n):
        # If the current index + 1 is in list1, print 1
        if (i + 1) in list1:
            print(1, end=" ")
        else:
            # Otherwise, print 2
            print(2, end=" ")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
