from collections import Counter

def solve():
    # Read the number of elements in the sequence
    N = int(input())
    # Read the sequence of integers and convert them to a list of integers
    D = list(map(int, input().split()))

    # Define the modulus value for calculations
    mod = 998244353

    # Check if the first element is not zero; if so, output 0 and return
    if D[0] != 0:
        print(0)
        return

    # Count the occurrences of each number in the list D
    cnt = Counter(D)

    # If there are more than one occurrence of zero, output 0 and return
    if cnt[0] > 1:
        print(0)
        return

    # Initialize the result variable to 1
    res = 1

    # Iterate through numbers from 1 to the maximum number in D
    for i in range(1, max(D) + 1):
        # If the previous number (i-1) appears exactly once, continue to the next iteration
        if cnt[i - 1] == 1:
            continue
        # Update the result by multiplying with the count of (i-1) raised to the count of i, modulo mod
        res *= cnt[i - 1] ** cnt[i] % mod
        res %= mod
    
    # Output the final result
    print(res)

# Call the solve function to execute the code
solve()
