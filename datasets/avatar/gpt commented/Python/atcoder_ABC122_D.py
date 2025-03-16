def ok(last4):
    # Check if the last 4 characters contain the substring 'AGC'
    for i in range(4):
        # Create a list from the last4 string to allow swapping
        t = list(last4)
        # Swap the current character with the previous one if not the first character
        if i >= 1:
            t[i], t[i - 1] = t[i - 1], t[i]
        # If 'AGC' is found in the modified string, return False
        if ''.join(t).count('AGC') >= 1:
            return False
    # If 'AGC' is not found in any of the permutations, return True
    return True

def dfs(cur, last3):
    # Check if the result for the current state is already computed
    if last3 in memo[cur]:
        return memo[cur][last3]
    # If we have reached the end of the sequence, return 1 (valid sequence found)
    if cur == n:
        return 1
    ret = 0
    # Iterate through each possible character 'A', 'C', 'G', 'T'
    for c in "ACGT":
        # Check if adding the current character keeps the sequence valid
        if ok(last3 + c):
            # Recursively call dfs for the next position with the updated last3
            ret = (ret + dfs(cur + 1, last3[1:] + c)) % mod
    # Store the computed result in the memoization table
    memo[cur][last3] = ret
    return ret

# Read the length of the sequence from input
n = int(input())
# Define the modulus for the result
mod = 10 ** 9 + 7
# Initialize the memoization table
memo = [{} for i in range(n + 1)]
# Start the depth-first search with the initial state
print(dfs(0, 'TTT'))
