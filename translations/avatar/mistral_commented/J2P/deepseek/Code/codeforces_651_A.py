import sys

def main():
    # Reading two integers 'a' and 'b' from the standard input
    a = int(sys.stdin.readline().strip())
    b = int(sys.stdin.readline().strip())

    # Initializing variable 'c' to 0
    c = 0

    # Checking if both 'a' and 'b' are equal to 1. If yes, then print 0 and exit
    if a == 1 and b == 1:
        print(0)
        sys.exit()

    # If 'a' is not equal to 1 and 'b' is not equal to 1, then perform the following steps
    else:
        # Performing the loop until either 'a' or 'b' becomes 0
        while a >= 1 or b >= 1:
            # If 'a' is greater than or equal to 'b', then decrement 'b' and increment 'a' by 2
            if a >= b:
                b += 1
                a -= 2
            # If 'a' is less than 'b', then increment 'a' and decrement 'b' by 2
            else:
                a += 1
                b -= 2

            # Checking if either 'a' or 'b' has become 0. If yes, then increment 'c' and break the loop
            if a <= 0 or b <= 0:
                c += 1
                break

            # Incrementing 'c' for each iteration of the loop
            c += 1

        # Printing the final result 'c' as the output
        print(c)

if __name__ == "__main__":
    main()

