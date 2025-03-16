# Set the recursion limit for the function call stack
# This is necessary to prevent a "RecursionError" when dealing with large inputs
def main():
    from sys import setrecursionlimit

    # Set the recursion limit to a large value
    setrecursionlimit(10 ** 6)

    # Import other required modules
    from os import environ
    from collections import defaultdict, deque, Counter
    from math import ceil, floor, gcd
    from itertools import accumulate, combinations, combinations_with_replacement

    # Define a debug function to print debug messages
    # This function is used only when running the program in an IDE or terminal
    set_debug = lambda *something: print(*something) if 'TERM_PROGRAM' in environ else lambda *x: 0
    dbg = set_debug

    # Define the input function to read input from standard input
    input = lambda: stdin.readline().rstrip()

    # Define a function to read multiple integers as a list
    LMIIS = lambda: list(map(int, input().split()))

    # Define input reading functions for single integer and string
    II = lambda: int(input())
    P = 10 ** 9 + 7
    INF = 10 ** 9 + 10

    # Read input for two numbers 'a' and 'b'
    sa, sb = input().split()
    a = int(sa)
    b = int(float(sb) * 100 + 0.1)

    # Calculate the product of 'a' and 'b' and print the result
    print(a * b // 100)

# Call the main function to start the program
main()