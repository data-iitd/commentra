# Declare and initialize three integer variables
a, b, c = map(int, input().split())  # Read the values of a, b, and c from the standard input

# Check if the sum of a and b is greater than or equal to c
if a + b >= c:
    print("Yes")  # If the condition is true, print "Yes"
else:
    print("No")   # If the condition is false, print "No"

# End the main function with a return statement of 0, indicating that the program has executed successfully
# <END-OF-CODE>
