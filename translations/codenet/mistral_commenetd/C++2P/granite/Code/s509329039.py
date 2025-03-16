

# Read input from the standard input stream
n, m = map(int, input().split())

# Initialize lists's' and 'c' for storing student numbers and classes respectively
s = []
c = []

# Read student numbers and classes from the standard input stream
for _ in range(m):
    si, ci = map(int, input().split())
    s.append(si)
    c.append(ci)

# Check all strings of length 'n' for a valid combination of student numbers and classes
for i in range(1000):
    # Convert the current number to a string
    st = str(i)

    # Check if the length of the string is equal to 'n'
    if len(st)!= n:
        continue

    # Initialize a flag 'f' to check if the current combination is valid
    f = True

    # Check each combination of student number and class
    for j in range(m):
        # Check if the current character in the string matches the expected class
        if st[s[j] - 1] == str(c[j]):
            # If yes, continue to the next check
            pass
        else:
            # If no, set the flag 'f' to False and break the loop
            f = False
            break

    # If all checks passed, print the current number and exit the program
    if f:
        print(i)
        break

# If no valid combination was found, print -1
else:
    print(-1)

