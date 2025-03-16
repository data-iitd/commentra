#######
# Code
#######

# Initialize variables
H, W, N = map(int, input().split())
s_r, s_c = map(int, input().split())
S = input()
T = input()
Judge = False

# Initialize variables for string S
S_L, S_R, S_U, S_D = 0, 0, 0, 0

# Iterate through string S
for x in range(N):
    # Check current character in S
    if S[x] == 'L':
        S_L += 1
        # Check condition for 'L'
        if S_L - T_R - s_c == 0:
            Judge = True
    elif S[x] == 'R':
        S_R += 1
        # Check condition for 'R'
        if s_c + (S_R - T_L) == W + 1:
            Judge = True
    elif S[x] == 'U':
        S_U += 1
        # Check condition for 'U'
        if S_U - T_D - s_r == 0:
            Judge = True
    elif S[x] == 'D':
        S_D += 1
        # Check condition for 'D'
        if s_r + (S_D - T_U) == H + 1:
            Judge = True

# Initialize variables for string T
if T_L is None:
    T_L = 0
if T_R is None:
    T_R = 0
if T_U is None:
    T_U = 0
if T_D is None:
    T_D = 0

# Iterate through string T and adjust variables accordingly
for x in range(N):
    # Check current character in T
    if T[x] == 'L':
        # Adjust T_L variable
        if S_R - T_L + s_c != 1:
            T_L += 1
    if T[x] == 'R':
        # Adjust T_R variable
        if s_c + (T_R - S_L) != W:
            T_R += 1
    if T[x] == 'U':
        # Adjust T_U variable
        if S_D - T_U + s_r != 1:
            T_U += 1
    if T[x] == 'D':
        # Adjust T_D variable
        if s_r + (T_D - S_U) != H:
            T_D += 1

# Check final condition
if Judge:
    print('NO')
else:
    print('YES')
