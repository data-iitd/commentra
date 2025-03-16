# Importing sys and defining a custom input function
import sys

# Custom input function
input = sys.stdin.readline

# Function to read an integer
def I( ):
    return int(input())

# Function to read multiple integers
def MI( ):
    return map(int, input().split())

# Function to read a list of integers
def LI( ):
    return list(map(int, input().split()))

# Main function
def main( ):
    # Setting the modulus value
    mod = 10 ** 9 + 7

    # Reading input values: N, A, and B
    N, A, B = MI()

    # Initializing the answer variable to 0
    ans = 0

    # Calculating the number of repetitions
    rep = N // (A + B)

    # Adding the number of blocks that can be fully covered by A and B in one repetition
    ans += rep * A

    # Calculating the remaining number of blocks
    res = N - rep * (A + B)

    # Adding the number of blocks that can be covered by A in the remaining blocks
    ans += min(res, A)

    # Printing the final answer
    print(ans)

# Calling the main function
main()
