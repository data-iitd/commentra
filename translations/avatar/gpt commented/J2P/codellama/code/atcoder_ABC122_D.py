import sys 

# Number of characters to generate
N = int(sys.stdin.readline()) 
# Modulus value for large number calculations
MOD = 1000000007 
# Possible tokens (characters) to use
TOKENS = ["A", "C", "G", "T"] 
# Memoization array to store computed results
memo = [{} for i in range(N + 1)] 

# Method to calculate the total valid sequences
def calc(): 
    # Start the depth-first search with the initial state
    return dfs(0, "TTT") 

# Method to check if the last 4 characters are valid
def isOK(last4): 
    # Check if the last 4 characters contain "AGC"
    if "AGC" in last4: 
        return False 
    # Check all permutations of the last 4 characters
    for i in range(3): 
        vals = list(last4) 
        # Swap characters to create a new permutation
        vals[i], vals[i + 1] = vals[i + 1], vals[i] 
        s = "".join(vals) 
        # Check if the new permutation contains "AGC"
        if "AGC" in s: 
            return False 
    # If no invalid sequences found, return true
    return True 

# Depth-first search method to explore all possible sequences
def dfs(current, last3): 
    # Check if the result is already computed and stored in memo
    if last3 in memo[current]: 
        return memo[current][last3] 
    # Base case: if the current length equals N, return 1 (valid sequence)
    if current == N: 
        return 1 
    # Variable to accumulate the result
    result = 0 
    # Iterate through each possible token
    for c in TOKENS: 
        # Check if adding the token to the last 3 characters is valid
        if isOK(last3 + c): 
            # Recursively call dfs for the next character
            result = (result + dfs(current + 1, last3[1:] + c)) % MOD 
    # Store the computed result in memoization array
    memo[current][last3] = result 
    return result 

# Main method to execute the program
if __name__ == "__main__": 
    # Print the result of the calculation
    print(calc()) 

