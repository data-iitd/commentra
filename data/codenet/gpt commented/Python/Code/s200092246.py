# Read an integer input from the user
N = int(input())
# Initialize an empty list to store the result
ans = []

# Loop through numbers from 1 to N
for i in range(1, N + 1):
    # Check if the sum of the first i natural numbers is less than N
    if sum(range(1, i + 1)) < N:
        # If it is, continue to the next iteration
        continue
    else:
        # If the sum is greater than or equal to N, store the results
        # ans[0] will hold i - 1, and ans[1] will hold the difference
        ans = [i - 1, sum(range(1, i + 1)) - N]
        # Exit the loop as we found the required values
        break

# Loop through numbers from 0 to ans[0] (which is i - 1)
for i in range(ans[0] + 1):
    # Print the numbers that are not equal to ans[1] + 1
    if i + 1 != ans[1]:
        print(i + 1)
