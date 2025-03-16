
n = int(input())  # Read the integer input `n`
s = list(input())  # Read the list `s` of length `n`
t = list(input())  # Read the list `t` of length `n`

# Check if the lists `s` and `t` are equal
if s == t:
    print(n)  # If they are equal, print `n`
else:
    cnt = 0  # Initialize the counter `cnt` to 0
    # Compare elements of `s` and `t` starting from each index `i` of `s`
    for i in range(n):
        for j in range(n - i):
            # If a mismatch is found, break out of the inner loop
            if s[i + j] != t[j]:
                break
            # If the end of the inner list is reached without breaking, set `cnt`
            if j == n - i - 1:
                cnt = n - i
    # Print `2 * n - cnt`
    print(2 * n - cnt)

