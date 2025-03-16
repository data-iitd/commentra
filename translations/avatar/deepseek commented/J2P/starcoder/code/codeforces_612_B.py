import sys; # Importing the sys module for input

n = int(sys.stdin.readline()); # Reading the integer n from the input
dp = [0] * 200001; # Initializing an array to store positions

# Storing positions of the integers in the array dp
for i in range(n):
    dp[int(sys.stdin.readline())] = i;

ans = 0; # Initializing the answer variable to 0

# Calculating the sum of absolute differences between consecutive positions
for i in range(2, n):
    ans += abs(dp[i] - dp[i - 1]);

print(ans); # Printing the final answer

# 