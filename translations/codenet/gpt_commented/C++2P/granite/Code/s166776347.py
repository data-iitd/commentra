
import sys
input = sys.stdin.readline

# Define types and macros for convenience
MOD = 10**9+7 # Define MOD as a modulus value for calculations

def main():
    # Input: Read the values of N and K
    N, K = map(int, input().split()) # Read N and K as integers
    A = list(map(int, input().split())) # Read N elements into list A

    # Solution: Calculate the number of inversions in the array
    ans1 = 0 # Initialize the count of inversions
    for i in range(N): # Iterate through each element
        for j in range(N): # Compare with every other element
            if i >= j: continue # Skip if i is greater than or equal to j
            if A[i] > A[j]: ans1 += 1 # Count inversion if A[i] > A[j]
            ans1 %= MOD # Take modulo to prevent overflow

    # Count occurrences of each element in the array
    count = [0]*2005 # Initialize a count array to store frequencies
    for i in range(N): # Iterate through the array
        count[A[i]-1] += 1 # Increment the count for the corresponding value

    # Calculate the second part of the answer based on the counts
    ans2 = 0 # Initialize the second answer
    remain = N # Remaining elements to consider
    for i in range(2005): # Iterate through the count array
        remain -= count[i] # Decrease the remaining count by the current count
        ans2 += count[i]*remain # Calculate pairs of inversions

    # Calculate the final answer based on ans1 and ans2
    ans = 0 # Initialize the final answer
    tmp = K*(K-1) # Calculate the number of ways to choose 2 from K
    tmp //= 2 # Divide by 2 to get combinations
    tmp %= MOD # Take modulo
    tmp *= ans2 # Multiply by the second answer
    tmp %= MOD # Take modulo again
    ans += ans1 * K # Add the contribution from ans1
    ans %= MOD # Take modulo
    ans += tmp # Add the contribution from tmp
    ans %= MOD # Take modulo

    # Output: Print the final answer
    print(ans) # Output the result

if __name__ == "__main__":
    main()

Translate the above Python code to Java and end with comment "