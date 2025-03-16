
# AOJ 2601: Evacuation Route
# 2017.11.26 bal4u@uu

import sys

# Function to read an integer from the input buffer
def getint():
    n = 0; # Initialize the integer to store the result
    # Check for negative sign
    if buf[p] == '-':
        p += 1; # Move to the next character
        while buf[p].isdigit(): n = (n<<3) + (n<<1) + int(buf[p], 16); # Convert characters to integer
        return -n; # Return the negative integer
    # Convert characters to integer for positive numbers
    while buf[p].isdigit(): n = (n<<3) + (n<<1) + int(buf[p], 16);
    return n; # Return the positive integer

# Read the input buffer
buf = sys.stdin.readline()

# Read the width of the evacuation route
w = getint()

# Read the evacuation route values
buf = sys.stdin.readline()

# Initialize answer and flags, and process the route values
ans = 0; f = 0; i = 1
while i <= w:
    a[i] = k = getint(); p += 1 # Read the next integer into array a
    if not k: f |= 1; # Set flag if value is zero
    else if k < 0: f |= 2; # Set flag if value is negative
    else: ans += k; # Accumulate positive values into ans
    i += 1

# Check for special cases: no positive values or only zeros
if not ans or not (f & 1): print(0); sys.exit(0)
# If there are no negative values, print the total sum
if not (f & 2): print(ans); sys.exit(0)

# Calculate the minimum distance to the closest zero from the left
close = 0; f = 0; i = 1
while i <= w:
    if not a[i]: close = INF; f = -1 # Reset close distance if zero is found
    elif a[i] < 0:
        # Update close distance if a negative value is found
        if f < 0 or close - (i-f) > -a[i]: close = -a[i]; f = i
    else:
        # Calculate the distance to the closest zero for positive values
        if f < 0: b[i] = INF # If no zero found, set to infinity
        else:
            k = close - (i-f); if k < 0: k = 0 # Calculate distance
            b[i] = k # Store the distance in array b
    i += 1

# Calculate the minimum distance to the closest zero from the right
close = 0; f = w; i = w
while i >= 1:
    if not a[i]: close = INF; f = -1 # Reset close distance if zero is found
    elif a[i] < 0:
        # Update close distance if a negative value is found
        if f < 0 or close - (f-i) > -a[i]: close = -a[i]; f = i
    else:
        # Calculate the distance to the closest zero for positive values
        if f < 0: b[i] = INF # If no zero found, set to infinity
        else:
            k = close - (f-i); if k < 0: k = 0 # Calculate distance
            if k > b[i]: b[i] = k # Update if the new distance is smaller
    i -= 1

# Calculate the final answer based on the minimum distances
ans = 0; i = 1
while i <= w:
    if a[i] > 0:
        # Add the minimum of the positive value or the calculated distance
        if b[i] > a[i]: ans += a[i]
        else:           ans += b[i]
    i += 1

# Print the final answer
print(ans)

