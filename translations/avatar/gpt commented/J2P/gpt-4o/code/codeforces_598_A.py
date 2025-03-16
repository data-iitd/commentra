import math  # Importing the math module for logarithm and power functions

def main():
    # Reading the number of test cases
    q = int(input())
    
    # Looping through each test case
    for _ in range(q):
        # Reading the integer n for the current test case
        n = int(input())
        
        # Calculating the highest power of 2 less than or equal to n
        x = int(math.log(n, 2)) + 1
        
        # Calculating the final result using the derived formula
        s = -1 * (2 ** x) + 2 + (n * (n + 1)) // 2 - (2 ** x)
        
        # Printing the result for the current test case
        print(s)

# Calling the main function to execute the code
if __name__ == "__main__":
    main()

# <END-OF-CODE>
