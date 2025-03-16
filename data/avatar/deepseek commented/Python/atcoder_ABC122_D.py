def ok(last4):
    # Check if the last4 string contains "AGC" more than once
    for i in range(4):
        t = list(last4)
        if i >= 1:
            # Swap the current and previous character
            t[i], t[i - 1] = t[i - 1], t[i]
        if ''.join(t).count('AGC') >= 1:
            # If "AGC" is found, return False
            return False
    return True

def dfs(cur, last3):
    # Check if the result for the current state (cur, last3) is already computed
    if last3 in memo[cur]:
        return memo[cur][last3]
    if cur == n:
        # Base case: if current length equals n, return 1 (valid sequence)
        return 1
    ret = 0
    for c in "ACGT":
        # Check if adding the character c to last3 forms a valid sequence
        if ok(last3 + c):
            # Recursively call dfs with the next character
            ret = (ret + dfs(cur + 1, last3[1:] + c)) % mod
    memo[cur][last3] = ret
    return ret

# Read the input value for n
n = int(input())
mod = 10 ** 9 + 7
# Initialize the memo dictionary for storing computed results
memo = [{} for i in range(n + 1)]
# Print the result of the dfs function starting with last3 as "TTT"
print(dfs(0, 'TTT'))
