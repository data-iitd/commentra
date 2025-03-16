# Read the number of entries
N = int(input())

# Initialize a 3D list (10x3x10) to store the values
m = []
line = ''
m = [[[0 for k in range(10)] for j in range(3)] for i in range(10)]

# Process each entry
for i in range(N):
    # Read input values and convert them to integers
    n = input().split()
    b = int(n[0])  # Building number
    f = int(n[1])  # Floor number
    r = int(n[2])  # Room number
    v = int(n[3])  # Value to add (e.g., number of people)

    # Update the corresponding position in the 3D list
    m[b-1][f-1][r-1] += v

# Print the results in a formatted manner
for i in range(4):  # Iterate over buildings (0 to 3)
    for j in range(3):  # Iterate over floors (0 to 2)
        for k in range(10):  # Iterate over rooms (0 to 9)
            # Append the value from the 3D list to the line string
            line += ' {0}'.format(m[i][j][k])
        
        # Print the line for the current floor
        print(line)
        line = ''  # Reset line for the next floor

    # Print a separator between buildings, except after the last building
    if i < 3:
        print('#'*20)
