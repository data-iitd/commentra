# Importing necessary modules
import sys

def main():
    # Reading input from the console
    h = int(input())  # Height of the grid
    w = int(input())  # Width of the grid
    n = int(input())  # Number of steps

    sr = int(input())  # Starting row of the safe zone
    sc = int(input())  # Starting column of the safe zone

    s = input()  # Sequence of 'U' and 'D' for vertical movements
    t = input()  # Sequence of 'L' and 'R' for horizontal movements

    end = False  # Variable to track if the safe zone is valid
    usafe = 1  # Upper boundary of the safe zone
    dsafe = h  # Lower boundary of the safe zone

    # Checking vertical boundaries of the safe zone based on sequence 's'
    for i in range(n - 1, -1, -1):
        if s[i] == 'U':  # If the current character is 'U', increase the upper boundary
            usafe += 1
        elif s[i] == 'D':  # If the current character is 'D', decrease the lower boundary
            dsafe -= 1
        if usafe > dsafe:  # If the upper boundary exceeds the lower boundary, the safe zone is invalid
            end = True
            break
        if i > 0:  # Check the previous character in sequence 't'
            if t[i - 1] == 'U':
                dsafe = min(dsafe + 1, h)  # Increase lower boundary
            elif t[i - 1] == 'D':
                usafe = max(usafe - 1, 1)  # Decrease upper boundary

    lsafe = 1  # Left boundary of the safe zone
    rsafe = w  # Right boundary of the safe zone

    # Checking horizontal boundaries of the safe zone based on sequence 't'
    for i in range(n - 1, -1, -1):
        if t[i] == 'L':  # If the current character is 'L', increase the left boundary
            lsafe += 1
        elif t[i] == 'R':  # If the current character is 'R', decrease the right boundary
            rsafe -= 1
        if lsafe > rsafe:  # If the left boundary exceeds the right boundary, the safe zone is invalid
            end = True
            break
        if i > 0:  # Check the previous character in sequence 's'
            if s[i - 1] == 'L':
                rsafe = min(rsafe + 1, w)  # Increase right boundary
            elif s[i - 1] == 'R':
                lsafe = max(lsafe - 1, 1)  # Decrease left boundary

    # Checking if the starting position is within the safe zone boundaries
    if sr >= usafe and sr <= dsafe and sc >= lsafe and sc <= rsafe and not end:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
