H, W, N = map(int, input().split())  # Read the dimensions of the grid and the starting position
s_r, s_c = map(int, input().split())  # Read the starting position of the robot
S = input()  # Read the string of movements for S
T = input()  # Read the string of movements for T

Judge = False  # Initialize a flag to check if the robot is out of bounds
S_L, S_R, S_U, S_D = 0, 0, 0, 0  # Initialize counters for movements in each direction for S
T_L, T_R, T_U, T_D = 0, 0, 0, 0  # Initialize counters for movements in each direction for T

# Iterate through each movement in S
for x in range(N):
    if S[x] == 'L':
        S_L += 1
        if S_L - T_R - s_c == 0:  # Check if S is about to hit the left boundary
            Judge = True
    elif S[x] == 'R':
        S_R += 1
        if s_c + (S_R - T_L) == W + 1:  # Check if S is about to hit the right boundary
            Judge = True
    elif S[x] == 'U':
        S_U += 1
        if S_U - T_D - s_r == 0:  # Check if S is about to hit the upper boundary
            Judge = True
    elif S[x] == 'D':
        S_D += 1
        if s_r + (S_D - T_U) == H + 1:  # Check if S is about to hit the lower boundary
            Judge = True

    # Update the counters for T based on its movements
    if T[x] == 'L':
        if S_R - T_L + s_c != 1:  # Check if T is about to move left
            T_L += 1
    if T[x] == 'R':
        if s_c + (T_R - S_L) != W:  # Check if T is about to move right
            T_R += 1
    if T[x] == 'U':
        if S_D - T_U + s_r != 1:  # Check if T is about to move up
            T_U += 1
    if T[x] == 'D':
        if s_r + (T_D - S_U) != H:  # Check if T is about to move down
            T_D += 1

# Check the flag and print the result
if Judge:
    print('NO')  # Print 'NO' if the robot is out of bounds
else:
    print('YES')  # Print 'YES' if the robot is within bounds
