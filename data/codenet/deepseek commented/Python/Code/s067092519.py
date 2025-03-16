
N = int(input())  # Read the number of entries
m=[]
line = ''
# Initialize a 3D list m with dimensions 10x3x10, filled with zeros
m = [[[0 for k in range(10)] for j in range(3)] for i in range(10)]

# Loop to read and process each entry
for i in range(N):
    n = input().split()  # Read a line and split it into parts
    b = int(n[0])  # Convert the building number to integer
    f = int(n[1])  # Convert the floor number to integer
    r = int(n[2])  # Convert the room number to integer
    v = int(n[3])  # Convert the value to integer
    # Update the corresponding position in the m list
    m[b-1][f-1][r-1] += v

# Loop to print the results
for i in range(4):
    for j in range(3):
        for k in range(10):
            line += ' {0}'.format(m[i][j][k])  # Build the line to print
        print(line)  # Print the line for the current floor
        line = ''  # Reset the line for the next floor
    if i < 3:
        print('#'*20)  # Print a separator line between the prints

