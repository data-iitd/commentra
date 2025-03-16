# Importing the necessary module for user input
import sys

def main():
    # Reading the number of elements to be inputted
    a = int(input())
    
    # Initializing a list to hold the input integers
    ar = []
    
    # Loop to read integers into the list
    for _ in range(a):
        ar.append(int(input()))  # Reading each integer into the list
    
    # Loop to calculate and print the min and max differences for each element
    for i in range(len(ar)):
        # Calculating the maximum difference from the first and last elements
        max_diff = max(ar[i] - ar[0], ar[-1] - ar[i])
        
        # Calculating the minimum difference based on the position of the current element
        if i == 0:
            # If it's the first element, compare with the second element
            min_diff = ar[i + 1] - ar[i]
        elif i == len(ar) - 1:
            # If it's the last element, compare with the second last element
            min_diff = ar[i] - ar[i - 1]
        else:
            # For middle elements, compare with both neighbors
            min_diff = min(ar[i] - ar[i - 1], ar[i + 1] - ar[i])
        
        # Printing the minimum and maximum differences for the current element
        print(min_diff, max_diff)

# Calling the main function to execute the code
if __name__ == "__main__":
    main()

# <END-OF-CODE>
