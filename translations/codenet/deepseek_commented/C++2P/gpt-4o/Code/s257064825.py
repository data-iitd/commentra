# Import necessary libraries
import sys

def main():
    # Read input string
    str_input = input().strip()  
    sum_digits = 0  # Initialize sum variable to store the sum of digits
    
    # Iterate over each character in the string
    for x in str_input:
        sum_digits += int(x)  # Convert character to integer and add to sum
    
    # Check if sum is divisible by 9
    if sum_digits % 9 == 0:
        print("Yes")  # Print "Yes" if sum is divisible by 9
    else:
        print("No")   # Print "No"

if __name__ == "__main__":
    main()

# <END-OF-CODE>
