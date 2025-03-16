
# Import the Scanner class from the java.util package
from java.util import Scanner

# Create a Scanner object to read input from the console
in = Scanner(System.in)

# Read the number of elements (n) and the threshold (k)
n = in.nextInt()
k = in.nextInt()
l = 0
c = 1

# Loop through each element to count consecutive occurrences
for i in range(n):
    # Read the next integer from input
    a = in.nextInt()

    # Check if the current number is the same as the last one
    if a == l:
        c += 1  # Increment the count of consecutive occurrences
    else:
        c = 1  # Reset the count if the number changes

    # Update the last number to the current one
    l = a

# Check if the count of consecutive numbers plus k exceeds n
if c + k > n:
    # If true, print the number of elements that are not part of the consecutive sequence
    print(n - c)
else:
    # Otherwise, print -1 indicating the condition is not met
    print(-1)

# End of code
