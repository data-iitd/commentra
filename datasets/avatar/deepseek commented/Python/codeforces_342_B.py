
R = lambda : map(int, input().split())  # Define a lambda function to read integers from input
n, m, s, f = R()  # Read values of n, m, s, and f

# Determine the direction and character based on the starting and finishing points
if s < f:
    d = 1  # Set direction to right (R)
    c = 'R'
else:
    d = -1  # Set direction to left (L)
    c = 'L'

res = ""  # Initialize an empty string to store the result
i = 1  # Initialize step counter
j = s  # Initialize current position
t, l, r = R()  # Read values of t, l, and r
k = 1  # Initialize the current time step

# Loop until the current position reaches the finishing point
while j != f:
    if i > t and k < m:  # Check if it's time to update the time step and there are more steps
        t, l, r = R()  # Read new values for t, l, and r
        k += 1  # Increment the time step counter
    
    if i == t and (l <= j <= r or l <= j + d <= r):  # Check if it's the specified time step and the position is within the allowed range
        res += 'X'  # Append 'X' to the result string
    else:
        res += c  # Append the direction character to the result string
        j += d  # Update the current position
    i += 1  # Increment the step counter

print(res)  # Print the result string

