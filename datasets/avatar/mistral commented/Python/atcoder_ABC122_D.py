#######
# This function checks if the last 4 nucleotides (last4) contain the sequence "AGC" or not.
# It returns False if it does, and True otherwise.
# Input: last4 (a list of 4 nucleotides)
# Output: A boolean value
########################################################################################################################
def ok(last4):
    # Iterate through the last 4 nucleotides in reverse order
    for i in range(4):
        # Swap the positions of the current and previous nucleotides
        t = list(last4)
        if i >= 1:
            t[i], t[i-1] = t[i-1], t[i]
        
        # Check if the swapped sequence contains "AGC"
        if ''.join(t).count('AGC') >= 1:
            # If yes, return False and exit the function
            return False
        
    # If no "AGC" sequence is found, return True
    return True
########################################################################################################################

# This function performs Depth-First Search (DFS) to find the number of valid sequences
# Input: cur (the current index), last3 (the last 3 nucleotides)
# Output: An integer value representing the number of valid sequences
########################################################################################################################
def dfs(cur, last3):
    # Memoization table to store the results of subproblems
    if last3 in memo[cur]:
        # If the subproblem has already been solved, return the stored result
        return memo[cur][last3]
    
    # Base case: If we have reached the end of the sequence, return 1
    if cur == n:
        return 1
    
    # Initialize the result to 0
    ret = 0
    
    # Iterate through all possible nucleotides (A, C, G, T)
    for c in "ACGT":
        # Check if the next nucleotide can be added to the last 3 nucleotides
        if ok(last3 + c):
            # If yes, recursively call dfs with the updated last 3 nucleotides and the new current index
            ret = (ret + dfs(cur+1, last3[1:]+c)) % mod
    
    # Store the result in the memoization table and return it
    memo[cur][last3] = ret
    return ret
########################################################################################################################

# Read the input: the number of nucleotides (n)
n = int(input())

# Initialize the memoization table with empty dictionaries
memo = [{} for i in range(n+1)]

# Initialize the modulus value
mod = 10 ** 9 + 7

# Perform DFS and print the result
print(dfs(0, 'TTT'))
