import sys

# Read three integers from the input: T, S, and q
T, S, q = map(int, sys.stdin.readline().split())

previous = S # Initialize 'previous' with the starting value S
answer = 0 # Initialize the answer counter

# Loop until 'previous' is less than 'T'
while previous < T:
    answer += 1 # Increment the answer counter
    previous *= q # Multiply 'previous' by 'q' for the next iteration

# Output the final count of how many times 'previous' was multiplied before reaching 'T'
print(answer)

