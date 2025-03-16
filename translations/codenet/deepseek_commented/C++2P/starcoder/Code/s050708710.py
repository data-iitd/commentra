# Include the iostream library for input and output operations.
# Include the cstdio library for standard input/output functions.
# Include the cstdlib library for general utilities like dynamic memory allocation, conversion functions, etc.
# Include the string library for string operations.
# Include the vector library for dynamic array operations.
# Include the algorithm library for various algorithms like sort.
# Include the numeric library for numeric operations.
# Include the map library for key-value pair based data structure.
# Include the stack library for stack data structure.
# Include the queue library for queue data structure.
# Include the iomanip library for manipulators like setprecision.
from sys import stdin, stdout # Import the stdin and stdout objects from the sys module.

# Define the main function which is the entry point of the program.
def main():
    # Declare four integer variables to store input values.
    r, g, b, n = map(int, stdin.readline().split())

    # Initialize a variable 'ans' to 0 to store the count of valid combinations.
    ans = 0

    # Start a nested loop to iterate through possible values of 'i' and 'j' that represent the number of times 'r' and 'g' are used, respectively.
    for i in range(n + 1):
        for j in range(n + 1):
            # Calculate the remaining value after using 'r * i' and 'g * j'.
            num = n - r * i - g * j
            # Check if 'num' is non-negative and divisible by 'b'.
            if num >= 0 and num % b == 0:
                # Increment 'ans' if the conditions are met.
                ans += 1

    # Print the value of 'ans' which represents the count of valid combinations.
    stdout.write(str(ans) + '\n')

# Execute the main function.
if __name__ == '__main__':
    main()

