# Read the values of six integer variables from standard input
a, b, c, d, e, k = map(int, input().split())

# Perform a simple condition check using the relational operator <=
if e - a <= k:
    print("Yay!")  # If the condition is true, print "Yay!"
else:
    print(":(")  # If the condition is false, print ":("

# Indicate that the program has finished running successfully
# <END-OF-CODE>
