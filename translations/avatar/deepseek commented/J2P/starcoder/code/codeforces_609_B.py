
import sys; # Import the sys module for reading input

n = int(sys.stdin.readline()); # Read the first integer n from input
m = int(sys.stdin.readline()); # Read the second integer m from input

arr = [0] * n; # Declare and initialize an array to store n integers
gen = [0] * 11; # Declare and initialize an array to count occurrences of integers

# Read n integers from input and store them in arr, and count their occurrences in gen
for i in range(n):
    arr[i] = int(sys.stdin.readline());
    gen[arr[i]] += 1;

ans = 0; # Declare a variable to store the result

# Calculate the number of pairs (i, k) where i ≠ k and gen[i] and gen[k] are non-zero
for i in range(1, m + 1):
    for k in range(1, m + 1):
        if i!= k:
            ans += gen[i] * gen[k];

# Print the result, which is half of the calculated pairs
print(ans / 2);

# 