
import sys

def main():
    # Initialize input and output streams
    input = sys.stdin
    output = sys.stdout
    
    # Read the number of elements and the modulo value
    n, m = map(int, input.readline().split())
    
    # Read the array of elements
    a = list(map(int, input.readline().split()))
    
    # HashMap to store the frequency of remainders
    dp = {}
    
    # Initialize the answer and base variable
    ans = 0
    base = 0
    
    # Iterate through the array to calculate the answer
    for i in range(n):
        # Update the base variable
        base = (base - a[i] % m + m) % m
        
        # Update the frequency of remainders in the HashMap
        dp[base] = dp.get(base, 0) + 1
        
        # Add the frequency of the current remainder to the answer
        ans += dp.get((base + a[i]) % m, 0)
    
    # Print the final answer
    output.write(str(ans) + '\n')

if __name__ == '__main__':
    main()

