
import sys; # Import the sys module for reading input

n = int(sys.stdin.readline()); # Read an integer n from the user
ans = 0; # Initialize the variable ans to 0

# Loop from 1 to n (inclusive)
for i in range(1, n + 1):
    # Calculate a value based on the current value of i and the variable n
    term = n // i;
    sum = term * (term + 1) // 2;
    ans += i * sum;

# Print the value of ans
print(ans);

# 