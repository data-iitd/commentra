import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)

# The readline function is assigned to read a single line from standard input.
# This is useful for efficient input reading in loops.

# MOD is set to 10^9 + 7, a common choice for modulo in competitive programming.
# This constant is used to ensure that the results stay within the limits of integer storage.

# INF is set to positive infinity. This allows for comparisons that will always favor the positive infinity side.
# This is particularly useful for initializing variables that need to be compared against potential large values.

# The recursion limit is increased to 10^5 to prevent potential stack overflow issues, especially in deeply recursive functions.
# This is a safeguard to ensure the program can handle a certain level of recursion without crashing.

def main():
    # The integer N is read from standard input. This value is crucial for the program's functionality.
    N = int(readline())
    
    # A set s containing powers of 2 from 2^0 to 2^6 is defined.
    # This set is used to check if a number is a power of 2 within a specific range.
    s = {1, 2, 4, 8, 16, 32, 64}
    
    # ans is initialized to 0. This variable will store the result to be printed.
    ans = 0

    # A for loop iterates through numbers from 1 to N.
    # This loop is used to find the largest number that is a power of 2 and less than or equal to N.
    for i in range(1, N + 1):
        # If the current number i is in the set s, it becomes the new value of ans.
        if i in s:
            ans = i

    # Finally, the value of ans is printed. This is the largest power of 2 less than or equal to N.
    print(ans)

# The main function is called if the script is executed directly.
# This is a common practice to allow the script to be imported as a module without running the main logic automatically.
if __name__ == '__main__':
    main()
