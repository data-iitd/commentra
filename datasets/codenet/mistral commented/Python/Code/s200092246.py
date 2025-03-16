# Take an integer input from the user and assign it to the variable N
N = int(input())

# Initialize an empty list to store the answer
ans = []

# Iterate through the numbers from 1 to N+1
for i in range(1, N+1):
    # Check if the sum of numbers from 1 to i+1 is less than N
    if sum(range(1, i + 1)) < N:
        # If the condition is true, continue to the next iteration
        continue
    # If the condition is false, the answer is found
    else:
        # Assign the values of i-1 and sum of numbers from 1 to i+1 - N to ans[0] and ans[1] respectively
        ans = [i - 1, sum(range(1, i + 1)) - N]
        # Break the loop once the answer is found
        break

# Iterate through the numbers from 0 to ans[0]
for i in range(ans[0]+1):
    # Check if the current number is not the answer[1]
    if i + 1 != ans[1]:
        # If the condition is true, print the number
        print(i + 1)