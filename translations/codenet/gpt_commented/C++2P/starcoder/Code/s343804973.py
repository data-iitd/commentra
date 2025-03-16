# Declare global variables
n, m, mod = 0, 0, 0
C = [[0 for i in range(310)] for j in range(310)]
pre = [[0 for i in range(310)] for j in range(310)]
f = [[0 for i in range(310)] for j in range(310)]

# Function to calculate binomial coefficient
def binomial(n, k):
    if k > n:
        return 0
    if k == 0 or k == n:
        return 1
    return C[n][k]

# Function to calculate the value of f[i][j]
def f_value(i, j):
    # Base case: f[1][j] = 1 for all j
    if i == 1:
        return 1
    # Initialize the value of f[i][j]
    value = 0
    # Calculate f[i][j] based on previous values
    for k in range(1, i):
        value += f[i - k][j] * pre[k][j + 1] * binomial(i - 2, k - 1) % mod
    # Return the value of f[i][j]
    return value % mod

# Function to update the pre array for the current row
def update_pre(i):
    for j in range(m, -1, -1):
        pre[i][j] = (pre[i][j + 1] + f[i][j]) % mod

# Function to calculate the value of pre[i][j]
def pre_value(i, j):
    # Base case: pre[1][j] = m - j + 1 for all j
    if i == 1:
        return m - j + 1
    # Return the value of pre[i][j]
    return (pre[i][j + 1] + f[i][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Function to calculate the value of C[i][j]
def c_value(i, j):
    # Base case: C[i][0] = C[i][i] = 1 for all i
    if j == 0 or j == i:
        return 1
    # Return the value of C[i][j]
    return (C[i - 1][j - 1] + C[i - 1][j]) % mod

# Functi