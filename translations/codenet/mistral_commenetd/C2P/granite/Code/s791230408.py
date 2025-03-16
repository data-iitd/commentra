
import sys

def main():
    j = int(input("Enter the number of test cases: ")) # Prompt user to enter the number of test cases
    for i in range(j): # Loop through each test case
        a, b, c = map(int, input("Enter the values of a, b, and c for test case {}: ".format(i+1)).split()) # Prompt user to enter the values of a, b, and c for the current test case
        max_val = max(a, b, c) # Find the maximum value among a, b, and c
        k = 0 # Initialize k with 0
        if max_val == b: # Check if max_val is equal to b
            k = 1 # Set k to 1 to indicate that b is greater than a
        elif max_val == c: # Check if max_val is equal to c
            k = 2 # Set k to 2 to indicate that c is greater than max_val (which was previously a or b)
        max_val *= max_val # Multiply max_val with itself to calculate max_val*max_val
        a *= a # Multiply a with itself to calculate a*a
        b *= b # Multiply b with itself to calculate b*b
        c *= c # Multiply c with itself to calculate c*c
        if k == 0 and max_val == b+c: # Check if k is 0 and max_val is equal to the sum of b and c
            print("YES") # Print "YES" to the console
        elif k == 1 and max_val == a+c: # Check if k is 1 and max_val is equal to the sum of a and c
            print("YES") # Print "YES" to the console
        elif k == 2 and max_val == a+b: # Check if k is 2 and max_val is equal to the sum of a and b
            print("YES") # Print "YES" to the console
        else: # If none of the above conditions are true
            print("NO") # Print "NO" to the console
    return 0 # Indicate successful execution of the program

if __name__ == "__main__":
    sys.exit(main())

