# Take an integer input `n` which represents the number of lists to be provided as input.
n = int(input())

# Initialize a counter `c` to 0. This will keep track of the number of lists where the sum of elements is greater than 1.
c = 0

# Loop `n` times to process each list of integers.
for i in range(n):
    # Take a list of integers as input, split them by spaces, convert them to integers, and store them in `l1`.
    l1 = list(map(int, input().split()))
    
    # Calculate the sum of the elements in `l1`.
    # If the sum is greater than 1, increment the counter `c` by 1.
    if sum(l1) > 1:
        c = c + 1

# After the loop completes, print the final value of `c`, which represents the number of lists where the sum of elements is greater than 1.
print(c)
