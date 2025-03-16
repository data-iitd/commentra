
N = int(input())  # Read an integer input N
ans = []  # Initialize an empty list `ans`

for i in range(1, N + 1):  # Loop from 1 to N
    if sum(range(1, i + 1)) < N:  # Check if the sum of numbers from 1 to i is less than N
        continue  # If true, continue to the next iteration
    else:
        ans = [i - 1, sum(range(1, i + 1)) - N]  # Calculate `ans` and break out of the loop
        break

for i in range(ans[0] + 1):  # Loop from 0 to ans[0]
    if i + 1 != ans[1]:  # Check if the current index i + 1 is not equal to ans[1]
        print(i + 1)  # If true, print i + 1

