import sys

INF = 0x5fffffff  # Define the maximum possible integer value
a = [0] * 100002  # Declare array 'a' to store integers
b = [0] * 100002  # Declare array 'b' to store evacuation routes

buf = [0] * 700002  # Buffer for reading input
p = 0  # Pointer for parsing

# Function to read an integer from the input buffer
def getint():
    global p
    n = 0
    if buf[p] == '-':  # Check if the number is negative
        p += 1
        while buf[p] >= '0':
            n = (n << 3) + (n << 1) + ord(buf[p]) - ord('0')
            p += 1
        return -n
    while buf[p] >= '0':
        n = (n << 3) + (n << 1) + ord(buf[p]) - ord('0')
        p += 1
    return n

# Main function
def main():
    global p
    w, i, k, f, close, ans = 0, 1, 0, 0, 0, 0

    # Read the width of the array and store it in 'w'
    w = int(sys.stdin.readline().strip())
    # Read the input line into the buffer
    sys.stdin.readinto(buf)

    # Initialize variables and start parsing the input
    ans = 0
    f = 0
    while i <= w:
        k = getint()
        a[i] = k
        p += 1
        if k == 0:
            f |= 1  # Set flag if zero is found
        elif k < 0:
            f |= 2  # Set flag if negative number is found
        else:
            ans += k  # Add to the sum if positive number
        i += 1

    if ans == 0 or (f & 1) == 0:  # If no positive numbers or zero found, output 0
        print(0)
        return
    if (f & 2) == 0:  # If no negative numbers, output the sum of positive numbers
        print(ans)
        return

    # Calculate the minimum evacuation routes
    close = 0
    f = 0
    i = 1
    while i <= w:  # First pass from left to right
        if a[i] == 0:
            close = INF
            f = -1
        elif a[i] < 0:
            if f < 0 or close - (i - f) > -a[i]:
                close = -a[i]
                f = i
        else:
            if f < 0:
                b[i] = INF
            else:
                k = close - (i - f)
                if k < 0:
                    k = 0
                b[i] = k
        i += 1

    close = 0
    f = w
    i = w
    while i >= 1:  # Second pass from right to left
        if a[i] == 0:
            close = INF
            f = -1
        elif a[i] < 0:
            if f < 0 or close - (f - i) > -a[i]:
                close = -a[i]
                f = i
        else:
            if f < 0:
                b[i] = INF
            else:
                k = close - (f - i)
                if k < 0:
                    k = 0
                if k > b[i]:
                    b[i] = k
        i -= 1

    ans = 0
    i = 1
    while i <= w:  # Calculate the total evacuation route
        if a[i] > 0:
            if b[i] > a[i]:
                ans += a[i]
            else:
                ans += b[i]
        i += 1

    print(ans)  # Output the final result

if __name__ == "__main__":
    main()
