# Importing the necessary module for reading input
import sys

def main():
    # Reading the integer value of n from the standard input
    n = int(sys.stdin.readline().strip())
    
    # Reading the string value of the input from the standard input
    str_input = sys.stdin.readline().strip()
    
    # Initializing variables to store the sums of the two halves
    sumX = 0  # Sum of the first half
    sumY = 0  # Sum of the second half
    
    # Checking if all characters are either '4' or '7'
    if all(c in '47' for c in str_input):
        # Iterating through the first half of the string to calculate the sum of its digits
        for i in range(n // 2):
            sumX += int(str_input[i])  # Adding the value of the current digit to sumX
        
        # Iterating through the second half of the string to calculate the sum of its digits
        for i in range(n // 2, n):
            sumY += int(str_input[i])  # Adding the value of the current digit to sumY
        
        # Checking if the sum of digits in the first half is equal to the sum of digits in the second half
        if sumX == sumY:
            print("YES")  # Printing "YES" if the condition is true
        else:
            print("NO")  # Printing "NO" if the condition is false
    else:
        print("NO")  # Printing "NO" if any character is not '4' or '7'

# Calling the main function to execute the code
if __name__ == "__main__":
    main()

# <END-OF-CODE>
