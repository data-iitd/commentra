# Step 3: Import necessary modules
from typing import List

def main():
    # Step 4: Read the values of n, a, and b
    n = int(input())
    a = int(input())
    b = int(input())
    
    # Step 5: Create two lists to store the lists of integers
    list1 = []
    list2 = []
    
    # Step 6: Read the elements of list1 and list2 from the user
    for _ in range(a):
        list1.append(int(input()))
    for _ in range(b):
        list2.append(int(input()))
    
    # Step 7: Iterate through the range from 1 to n and print the appropriate list number
    for i in range(n):
        if (i + 1) in list1:
            print(1, end=" ")
        else:
            print(2, end=" ")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
