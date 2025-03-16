import sys
from bisect import bisect_left

def solve():
    # Read input values for N (number of elements) and K (modulus value)
    input = sys.stdin.readline
    N, K = map(int, input().split())
    
    # Read the array A and transform each element by taking modulo K and subtracting 1
    A = [(int(a) % K) - 1 for a in input().split()]
    
    # Initialize a list to store cumulative sums modulo K
    sum_A = [0 for _ in range(N + 1)]

    # Initialize a counter for valid subarrays and a dictionary to store indices of cumulative sums
    count = 0
    modK = dict()
    modK[0] = [0]  # Initialize with the sum 0 at index 0

    # Calculate cumulative sums modulo K and store their indices in modK
    for i in range(N):
        sum_A[i + 1] = (sum_A[i] + A[i]) % K  # Update cumulative sum
        if sum_A[i + 1] not in modK:
            modK[sum_A[i + 1]] = [i + 1]  # Initialize list if key doesn't exist
        else:
            modK[sum_A[i + 1]].append(i + 1)  # Append index to existing key

    # Count the number of valid subarrays using the stored indices
    for key in modK:
        lenK = len(modK[key])  # Get the number of indices for the current key
        for i, a in enumerate(modK[key]):
            # Use binary search to find the number of valid subarrays ending at index a
            count += bisect_left(modK[key], a + K, i, lenK) - i - 1

    # Output the final count of valid subarrays
    print(count)
    return 0

if __name__ == "__main__":
    solve()
