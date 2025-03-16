
# Import the Scanner class from the java.util package
from java.util import Scanner

# Create a Scanner object to read input from the console
sc = Scanner(System.in)

# Read the number of pairs of integers to be processed
n = sc.nextInt()

# Initialize an array to store the characters representing the actions
ch = []

# Initialize sums for two different actions
s1 = 0
s2 = 0

# Loop variables
i = 0
j = 0
flag = 0
dif = 0

# Process each pair of integers
while i < n:
    # Read the next pair of integers
    x = sc.nextInt()
    y = sc.nextInt()

    # Calculate temporary sums for the current iteration
    temp1 = s1 + x
    temp2 = s2 + y

    # Check if adding x to s1 keeps the difference within 500
    if abs(temp1 - s2) <= 500:
        s1 += x  # Update s1
        ch.append('A')  # Record the action 'A'
        i += 1  # Move to the next iteration
        continue

    # Check if adding y to s2 keeps the difference within 500
    if abs(temp2 - s1) <= 500:
        s2 += y  # Update s2
        ch.append('G')  # Record the action 'G'
        i += 1  # Move to the next iteration
        continue

    # If neither condition is met, set flag to indicate failure
    flag = 1
    break  # Exit the loop

# Check if the loop was exited due to a failure condition
if flag == 1:
    print(-1)  # Output -1 to indicate failure
else:
    # Convert the character array to a string and print the result
    ans = ""
    ans = "".join(ch)
    print(ans)  # Output the recorded actions

# End of code
