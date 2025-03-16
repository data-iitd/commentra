

n, m = map(int, input().split()) # Read the first two integers n and m from input
arr = list(map(int, input().split())) # Read n integers from input and store them in arr
gen = [0] * 11 # Initialize an array to count occurrences of integers

# Count the occurrences of integers in arr and store them in gen
for i in arr:
    gen[i] += 1

ans = 0 # Declare a variable to store the result

# Calculate the number of pairs (i, k) where i ≠ k and gen[i] and gen[k] are non-zero
for i in range(1, m + 1):
    for k in range(1, m + 1):
        if i!= k:
            ans += gen[i] * gen[k]

# Print the result, which is half of the calculated pairs
print(ans // 2)

