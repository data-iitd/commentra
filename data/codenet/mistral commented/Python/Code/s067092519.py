# Ask the user for the number of test cases
N = int(input())

# Initialize a 3D list m of size 10x3x10 with zeros
m = [[[0 for k in range(10)] for j in range(3)] for i in range(10)]

# Iterate through each test case and update the corresponding cell in the m list
for i in range(N):
    # Get the values of b, f, r, and v from the input
    n = input().split()
    b = int(n[0])
    f = int(n[1])
    r = int(n[2])
    v = int(n[3])
    
    # Update the corresponding cell in the m list with the value v
    m[b-1][f-1][r-1] += v

# Iterate through the 3D list m and print each row
for i in range(4):
    for j in range(3):
        for k in range(10):
            # Print the value at the current cell
            line += ' {0}'.format(m[i][j][k])
    
    # Add a newline and a separator '#' after every 3 rows
    if i < 3:
        print('#'*20)
        print()
