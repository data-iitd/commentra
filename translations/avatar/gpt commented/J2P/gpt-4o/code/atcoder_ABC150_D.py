import sys
from math import gcd
from functools import reduce

def main():
    # Read the first integer n, which represents the number of elements
    n = int(input().strip())
    
    # Read the second integer m, which represents the upper limit
    m = int(input().strip())
    
    # Read n integers from input, divide each by 2, and store in list a
    a = [int(input().strip()) // 2 for _ in range(n)]
    
    lcd = 1  # Initialize the least common denominator (lcd) to 1
    
    # Calculate the least common multiple (lcd) of the array elements
    for i in range(n):
        current_gcd = gcd(lcd, a[i])  # Get the greatest common divisor (gcd) of lcd and current element
        lcd = lcd * a[i] // current_gcd  # Update lcd using the formula: lcd = (lcd * a[i]) / gcd
        
        # If lcd exceeds m, print 0 and exit
        if lcd > m:
            print(0)
            return
    
    # Check if the condition for each element in the array is satisfied
    for i in range(n):
        # If lcd divided by the current element is even, print 0 and exit
        if (lcd // a[i]) % 2 == 0:
            print(0)
            return
    
    # Calculate and print the final result based on the value of m and lcd
    print((m // lcd + 1) // 2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
