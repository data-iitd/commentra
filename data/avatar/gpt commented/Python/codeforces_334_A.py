# Read an integer input from the user
n = int(input())

# Initialize two variables: 'i' starting from 1 and 'j' starting from n*n
i, j = 1, n * n

# Loop until 'i' is less than 'j'
while i < j:
    # Print the current values of 'i' and 'j'
    print(i, j)
    
    # Increment 'i' to move towards the center
    i += 1
    
    # Decrement 'j' to move towards the center
    j -= 1
