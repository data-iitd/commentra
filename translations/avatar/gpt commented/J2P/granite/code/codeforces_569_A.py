
T = int(input()) # Read the first integer from the input
S = int(input()) # Read the second integer from the input
q = int(input()) # Read the third integer from the input

previous = S # Initialize 'previous' with the starting value S
answer = 0 # Initialize the answer counter

while previous < T: # Loop until 'previous' is less than 'T'
    answer += 1 # Increment the answer counter
    previous *= q # Multiply 'previous' by 'q' for the next iteration

print(answer) # Output the final count of how many times 'previous' was multiplied before reaching 'T'

