import sys
input = sys.stdin.readline

# Function to read an integer
def I():
    return int(input())

# Function to read a map of integers
def MI():
    return map(int, input().split())

# Function to read a list of integers
def LI():
    return list(map(int, input().split()))

# Main function
def main():
    mod = 10 ** 9 + 7  # Modulo value
    N, A, B = MI()  # Reading N, A, and B
    ans = 0  # Initializing the result variable
    
    # Calculating the number of complete cycles of A + B within N
    rep = N // (A + B)
    
    # Updating the result with the number of complete cycles multiplied by A
    ans += rep * A
    
    # Calculating the remaining days after the complete cycles
    res = N - rep * (A + B)
    
    # Updating the result with the minimum of the remaining days and A
    ans += min(res, A)
    
    # Printing the final result
    print(ans)

main()
