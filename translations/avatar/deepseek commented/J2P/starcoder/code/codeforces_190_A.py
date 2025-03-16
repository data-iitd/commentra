
import sys

def main():
    # Read the first integer input
    n = int(input())

    # Read the second integer input
    m = int(input())

    # Check if n is 0
    if n == 0:
        # If n is 0 but m is not 0, print "Impossible"
        if m!= 0:
            print("Impossible")
        # If both n and m are 0, print "0 0"
        else:
            print(0, 0)
        return

    # If n is not 0, check if m is less than or equal to n
    if m <= n:
        # If m is 0, set m to 1
        if m == 0:
            m = 1
        # Print the values of n and m + n - 1
        print(n, m + n - 1)
        return

    # If m is greater than n, print the values of m and m + n - 1
    print(m, m + n - 1)

if __name__ == "__main__":
    main()

# 