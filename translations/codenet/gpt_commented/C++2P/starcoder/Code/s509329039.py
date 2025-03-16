
# Read the number of constraints (n) and the number of conditions (m)
n, m = map(int, input().split())

# Initialize vectors to store the positions (s) and corresponding values (c)
s = [0] * m
c = [0] * m

# Read the constraints into the vectors
for i in range(m):
    s[i], c[i] = map(int, input().split())
    s[i] -= 1 # Adjust for 0-based indexing

# Iterate through all possible numbers from 0 to 999
for i in range(1000):
    st = str(i) # Convert the number to a string
    
    # Skip numbers that do not have the required length
    if len(st)!= n:
        continue

    # Flag to check if the current number satisfies all conditions
    f = 1

    # Check each condition against the current number
    for j in range(m):
        if st[s[j]] == c[j] + '0':
            # Condition is satisfied
        else:
            # Condition is not satisfied, set flag to 0
            f = 0

    # If all conditions are satisfied, print the number and exit
    if f:
        print(i)
        break

# If no valid number is found, output -1
else:
    print(-1)

