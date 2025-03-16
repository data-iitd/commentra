import sys

INF = 0x5fffffff  # Define the maximum possible integer value
a = [0] * 100002  # Declare array 'a' to store integers
b = [0] * 100002  # Declare array 'b' to store evacuation routes

# Function to read an integer from the input
def getint():
    global p
    n = 0
    if p[0] == '-':  # Check if the number is negative
        p = p[1:]  # Move past the negative sign
        while p and p[0].isdigit():
            n = (n << 3) + (n << 1) + (ord(p[0]) - ord('0'))  # Parse the negative number
            p = p[1:]  # Move to the next character
        return -n
    while p and p[0].isdigit():
        n = (n << 3) + (n << 1) + (ord(p[0]) - ord('0'))  # Parse the positive number
        p = p[1:]  # Move to the next character
    return n

def main():
    global p
    buf = sys.stdin.read()  # Read all input at once
    p = buf.split()  # Split input into tokens
    w = getint()  # Read the width of the array and store it in 'w'
    
    ans = 0
    f = 0
    for i in range(1, w + 1):  # Initialize variables and start parsing the input
        a[i] = k = getint()  # Read the next integer and store it in 'a[i]'
        if k == 0:
            f |= 1  # Set flag if zero is found
        elif k < 0:
            f |= 2  # Set flag if negative number is found
        else:
            ans += k  # Add to the sum if positive number

    if ans == 0 or not (f & 1):  # If no positive numbers or zero found, output 0
        print("0")
        return
    if not (f & 2):  # If no negative numbers, output the sum of positive numbers
        print(ans)
        return

    # Calculate the minimum evacuation routes
    close = 0
    f = 0
    for i in range(1, w + 1):  # First pass from left to right
        if a[i] == 0:
            close = INF
            f = -1  # Reset if zero is found
        elif a[i] < 0:
            if f < 0 or close - (i - f) > -a[i]:
                close = -a[i]
                f = i  # Update the closest negative number
        else:
            if f < 0:
                b[i] = INF  # If no negative number found yet, set to INF
            else:
                k = close - (i - f)
                if k < 0:
                    k = 0  # Calculate the evacuation route
                b[i] = k

    close = 0
    f = w
    for i in range(w, 0, -1):  # Second pass from right to left
        if a[i] == 0:
            close = INF
            f = -1  # Reset if zero is found
        elif a[i] < 0:
            if f < 0 or close - (f - i) > -a[i]:
                close = -a[i]
                f = i  # Update the closest negative number
        else:
            if f < 0:
                b[i] = INF  # If no negative number found yet, set to INF
            else:
                k = close - (f - i)
                if k < 0:
                    k = 0  # Calculate the evacuation route
                if k > b[i]:
                    b[i] = k  # Update if a better route is found

    ans = 0
    for i in range(1, w + 1):  # Calculate the total evacuation route
        if a[i] > 0:
            if b[i] > a[i]:
                ans += a[i]  # Add the minimum of b[i] and a[i]
            else:
                ans += b[i]

    print(ans)  # Output the final result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
