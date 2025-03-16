# Import the sys module for user input
import sys

def main():
    # Read four integers from the user
    x = int(input())  # Upper limit for the first variable
    y = int(input())  # Upper limit for the second variable
    a = int(input())  # Lower limit for the first variable
    b = int(input())  # Lower limit for the second variable
    
    # Initialize a counter to keep track of valid pairs
    count = 0
    
    # First nested loop to iterate through the range [a, x]
    for i in range(a, x + 1):
        # Second nested loop to iterate through the range [b, y]
        for j in range(b, y + 1):
            # Skip the iteration if i is less than or equal to j
            if i <= j:
                continue
            
            # Increment the count for each valid pair (i, j)
            count += 1
    
    # Output the total count of valid pairs
    print(count)
    
    # Second set of nested loops to print the valid pairs
    for i in range(a, x + 1):
        for j in range(b, y + 1):
            # Skip the iteration if i is less than or equal to j
            if i <= j:
                continue
            
            # Print the valid pair (i, j)
            print(i, j)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
