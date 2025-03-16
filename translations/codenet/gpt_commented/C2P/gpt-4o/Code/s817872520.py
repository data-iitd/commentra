# AOJ 2601: Evacuation Route
# 2017.11.26 bal4u@uu

import sys

INF = 0x5fffffff  # Define a constant for infinity
a = [0] * 100002  # Array to hold the values of the evacuation route
b = [0] * 100002  # Array to hold the computed values for the evacuation route

# Function to read an integer from the input
def getint():
    global p
    n = 0  # Initialize the integer to store the result
    # Check for negative sign
    if p[0] == '-':
        p = p[1:]  # Move to the next character
        while p and p[0] >= '0':
            n = (n << 3) + (n << 1) + (ord(p[0]) & 0xf)  # Convert characters to integer
            p = p[1:]  # Move to the next character
        return -n  # Return the negative integer
    # Convert characters to integer for positive numbers
    while p and p[0] >= '0':
        n = (n << 3) + (n << 1) + (ord(p[0]) & 0xf)
        p = p[1:]  # Move to the next character
    return n  # Return the positive integer

def main():
    global p
    buf = sys.stdin.read()  # Read all input at once
    p = buf.splitlines()  # Split input into lines
    w = getint()  # Read the width of the evacuation route
    a_values = list(map(int, p[1].split()))  # Read the evacuation route values

    # Initialize answer and flags, and process the route values
    ans = 0
    f = 0
    for i in range(1, w + 1):
        a[i] = a_values[i - 1]  # Read the next integer into array a
        k = a[i]
        if k == 0:
            f |= 1  # Set flag if value is zero
        elif k < 0:
            f |= 2  # Set flag if value is negative
        else:
            ans += k  # Accumulate positive values into ans

    # Check for special cases: no positive values or only zeros
    if ans == 0 or not (f & 1):
        print("0")
        return
    # If there are no negative values, print the total sum
    if not (f & 2):
        print(ans)
        return

    # Calculate the minimum distance to the closest zero from the left
    close = 0
    f = 0
    for i in range(1, w + 1):
        if a[i] == 0:
            close = INF
            f = -1  # Reset close distance if zero is found
        elif a[i] < 0:
            # Update close distance if a negative value is found
            if f < 0 or close - (i - f) > -a[i]:
                close = -a[i]
                f = i
        else:
            # Calculate the distance to the closest zero for positive values
            if f < 0:
                b[i] = INF  # If no zero found, set to infinity
            else:
                k = close - (i - f)
                if k < 0:
                    k = 0  # Calculate distance
                b[i] = k  # Store the distance in array b

    # Calculate the minimum distance to the closest zero from the right
    close = 0
    f = w
    for i in range(w, 0, -1):
        if a[i] == 0:
            close = INF
            f = -1  # Reset close distance if zero is found
        elif a[i] < 0:
            # Update close distance if a negative value is found
            if f < 0 or close - (f - i) > -a[i]:
                close = -a[i]
                f = i
        else:
            # Calculate the distance to the closest zero for positive values
            if f < 0:
                b[i] = INF  # If no zero found, set to infinity
            else:
                k = close - (f - i)
                if k < 0:
                    k = 0  # Calculate distance
                if k > b[i]:
                    b[i] = k  # Update if the new distance is smaller

    # Calculate the final answer based on the minimum distances
    ans = 0
    for i in range(1, w + 1):
        if a[i] > 0:
            # Add the minimum of the positive value or the calculated distance
            if b[i] > a[i]:
                ans += a[i]
            else:
                ans += b[i]

    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
