
# Declare variables K and X to hold input values
K, X = map(int, input().split())

# Check if 500 times K is greater than or equal to X
if 500*K >= X:
    # If the condition is true, print "Yes"
    print("Yes")
else:
    # If the condition is false, print "No"
    print("No")

