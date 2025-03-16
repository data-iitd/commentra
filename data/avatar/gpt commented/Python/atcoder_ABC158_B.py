import sys

# Use readline for faster input
input = sys.stdin.readline

# Function to read a single integer from input
def I():
    return int(input())

# Function to read multiple integers from input and return them as a map
def MI():
    return map(int, input().split())

# Function to read multiple integers from input and return them as a list
def LI():
    return list(map(int, input().split()))

def main():
    # Define the modulo constant
    mod = 10 ** 9 + 7
    
    # Read input values: N (total items), A (items of type A), B (items of type B)
    N, A, B = MI()
    
    # Initialize the answer variable
    ans = 0
    
    # Calculate how many complete cycles of (A + B) fit into N
    rep = N // (A + B)
    
    # Add the total items of type A from the complete cycles to the answer
    ans += rep * A
    
    # Calculate the remaining items after complete cycles
    res = N - rep * (A + B)
    
    # Add the minimum of remaining items or A to the answer
    ans += min(res, A)
    
    # Print the final answer
    print(ans)

# Call the main function to execute the program
main()
