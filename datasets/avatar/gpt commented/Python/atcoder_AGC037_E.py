# Read input values for N and K
N, K = map(int, input().split())
# Read the string S
S = input()

# Initialize a flag to determine if we can use a shortcut for output
aaaa = False

# Check if K is large enough or if 2^K is greater than or equal to N
if K >= 15:
    aaaa = True
elif 2 ** K >= N:
    aaaa = True

# If the shortcut condition is met, print the minimum character repeated N times and exit
if aaaa:
    print(min(S) * N)
    exit()

# Function to get the lexicographically smallest rotation of the string
def get_last_dict(s_str):
    # Create a doubled string to facilitate rotation comparison
    U = s_str + s_str[::-1]
    # Find the minimum character in the original string
    c = min(s_str)
    # Get the first occurrence of the minimum character
    p = U.index(c)
    minindex = p
    p += 1
    
    # Iterate through the doubled string to find the smallest rotation
    while p <= N:
        if U[p] == c:
            # Compare the current rotation with the previously found minimum
            if check_normal_dict(U, minindex, p):
                minindex = p
        p += 1
    
    # Return the smallest rotation of length N
    return U[minindex:minindex + N]

# Function to compare two rotations of the string
def check_normal_dict(u, pointer1, pointer2):
    # Compare characters of the two rotations
    for i in range(N):
        if u[pointer1 + i] > u[pointer2 + i]:
            return True
        elif u[pointer1 + i] < u[pointer2 + i]:
            return False
    return False

# Get the lexicographically smallest rotation of S
S = get_last_dict(S)

# If K is 1, simply print the smallest rotation
if K == 1:
    print(S)
else:
    count = 0
    # Count how many times the first character appears consecutively
    for c in S:
        if c == S[0]:
            count += 1
        else:
            break
    
    # Check if the repeated character can fill the string of length N
    if count * (2 ** (K - 1)) >= N:
        print(S[0] * N)
    else:
        # Construct the output string based on the count and the original string
        S = S[0] * (count * ((2 ** (K - 1)) - 1)) + S
        # Print the first N characters of the constructed string
        print(S[0:N])
