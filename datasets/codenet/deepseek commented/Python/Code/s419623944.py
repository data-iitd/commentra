
N, R = map(int, input().split())  # Taking two inputs, N and R, which are integers.

# Check if N is greater than or equal to 10
if N >= 10:
    print(R)  # If true, print the value of R.
else:
    # Calculate the additional cost based on the difference between 10 and N,
    # multiply it by 100, and add it to R.
    additional_cost = 100 * (10 - N)
    print(R + additional_cost)  # Print the new value of R after adding the additional cost.

