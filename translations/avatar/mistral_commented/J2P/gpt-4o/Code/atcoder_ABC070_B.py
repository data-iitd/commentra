import sys

def main():
    # Read input integers a, b, c, and d
    a, b, c, d = map(int, sys.stdin.readline().split())

    # Check if c is greater than b
    if c > b:
        # If yes, print 0 and exit
        print(0)
        return

    # Check if a is greater than d
    elif a > d:
        # If yes, print 0 and exit
        print(0)
        return

    # Check if a is less than c
    elif a < c:
        # If yes, calculate the difference between the smaller and larger of b and d
        difference = min(b, d) - c
        # Print the difference
        print(difference)
        return

    # If none of the above conditions are true, then a, b, c, and d are in sorted order
    else:
        # Create a list of integers a, b, c, and d
        l = [a, b, c, d]

        # Sort the list in ascending order
        l.sort()

        # Calculate the difference between the second and third elements of the list
        difference = l[2] - l[1]

        # Print the difference
        print(difference)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
