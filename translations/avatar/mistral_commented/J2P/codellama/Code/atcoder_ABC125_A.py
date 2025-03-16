
# Import the Scanner class from the java.util package
from java.util import Scanner

# Create a new Scanner object to read input from the standard input stream
sc = Scanner(System.in)

# Read three integers from the standard input: the number of seconds, the number of periods, and the total number of seconds
sec = sc.nextInt()  # Read the number of seconds
per_num = sc.nextInt()  # Read the number of periods
max_sec = sc.nextInt()  # Read the total number of seconds

# Convert the last input (max_sec) to a double type and add 0.5 to it to get the maximum number of seconds with a fractional part
max_sec = float(max_sec) + 0.5

# Initialize a counter variable ans_num to zero
ans_num = 0

# Start a for loop that runs from the initial value sec to the final value max_sec with a step size of sec. In each iteration of the loop, add per_num to ans_num
for i in range(sec, max_sec, sec):
    ans_num += per_num

# Print the result ans_num to the standard output stream
print(ans_num)

# Close the Scanner object to release the system resources
sc.close()

