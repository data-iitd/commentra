
from collections import Counter

def solve():
    # Read the integer N and the list of integers D from input
    N = int(input())
    D = list(map(int, input().split()))

    # Set the constant mod to 998244353
    mod = 998244353

    # Check if the first element of D is not 0
    if D[0] != 0:
        print(0)
        return

    # Use Counter from the collections module to count occurrences of each element in D
    cnt = Counter(D)

    # Check if there is more than one occurrence of 0 in D
    if cnt[0] > 1:
        print(0)
        return

    # Initialize the result variable res to 1
    res = 1

    # Iterate through the range from 1 to the maximum element in D
    for i in range(1, max(D)+1):
        # If there is only one occurrence of i-1, skip to the next iteration
        if cnt[i-1] == 1:
            continue
        # Calculate the product of cnt[i-1] raised to the power of cnt[i] modulo mod
        # and update res accordingly
        res *= cnt[i-1]**cnt[i] % mod
        res %= mod
    
    # Print the final result
    print(res)

solve()

