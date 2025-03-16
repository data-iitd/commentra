#include <stdio.h>
#include <stdlib.h>

#define INF 0x5fffffff // Define the maximum possible integer value
a = [0] * 100002 // Declare array 'a' to store integers
b = [0] * 100002 // Declare array 'b' to store evacuation routes

buf = "" // Buffer for reading input and pointer for parsing

# Function to read an integer from the input buffer
def getint():
    n = 0
    if buf[0] == '-': # Check if the number is negative
        buf = buf[1:]
        while buf[0] >= '0':
            n = (n<<3) + (n<<1) + ord(buf[0]) - ord('0')
            buf = buf[1:]
        return -n
    while buf[0] >= '0':
        n = (n<<3) + (n<<1) + ord(buf[0]) - ord('0')
        buf = buf[1:]
    return n

def main():
    w, i, k, f, close, ans = 0, 1, 0, 0, 0, 0 # Declare variables to store input, indices, and results

    w = getint() # Read the width of the array and store it in 'w'
    buf = input() # Read the input line into the buffer
    for i in range(1, w+1): # Initialize variables and start parsing the input
        a[i] = k = getint() # Read the next integer and store it in 'a[i]'
        if not k: f |= 1 # Set flag if zero is found
        elif k < 0: f |= 2 # Set flag if negative number is found
        else: ans += k # Add to the sum if positive number
    if not ans or not (f & 1): # If no positive numbers or zero found, output 0
        print(0)
        return
    if not (f & 2): # If no negative numbers, output the sum of positive numbers
        print(ans)
        return

    # Calculate the minimum evacuation routes
    for close in range(0, INF): # First pass from left to right
        if not a[i]: close = INF; f = -1 # Reset if zero is found
        elif a[i] < 0:
            if f < 0 or close - (i-f) > -a[i]: close = -a[i]; f = i # Update the closest negative number
        else:
            if f < 0: b[i] = INF # If no negative number found yet, set to INF
            else:
                k = close - (i-f); if k < 0: k = 0 # Calculate the evacuation route
                b[i] = k
    for close in range(0, INF): # Second pass from right to left
        if not a[i]: close = INF; f = -1 # Reset if zero is found
        elif a[i] < 0:
            if f < 0 or close - (f-i) > -a[i]: close = -a[i]; f = i # Update the closest negative number
        else:
            if f < 0: b[i] = INF # If no negative number found yet, set to INF
            else:
                k = close - (f-i); if k < 0: k = 0 # Calculate the evacuation route
                if k > b[i]: b[i] = k # Update if a better route is found
    for i in range(1, w+1): # Calculate the total evacuation route
        if a[i] > 0:
            if b[i] > a[i]: ans += a[i] # Add the minimum of b[i] and a[i]
            else:             ans += b[i]
    print(ans) # Output the final result

