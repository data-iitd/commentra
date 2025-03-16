
# Initialize a scanner for reading input from stdin
sc = input().split()

# Initialize variables for processing the input
ans = 0
aPrev = 0

# Process each test case
for i in range(int(sc[0])):
    # Read the next integer as 'a'
    a = int(sc[i+1])

    # Check if 'a' is valid based on the conditions in the problem statement
    if a > i or a > aPrev+1: # 'a' is not valid, print -1 and exit
        print(-1)
        break
    elif a == aPrev+1: # Increment the answer if 'a' is consecutive with the previous number
        ans += 1
    else: # Add 'a' to the answer if it's not consecutive but greater than the previous number
        ans += a

    # Update the previous number
    aPrev = a

# Print the final answer
print(ans)

# End of code
