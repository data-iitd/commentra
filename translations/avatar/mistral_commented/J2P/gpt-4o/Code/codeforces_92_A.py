# Importing the sys module for reading input
import sys

# Defining the main function
def main():
    # Reading the first integer `n` from the standard input
    n = int(sys.stdin.readline().strip())
    # Reading the second integer `k` from the standard input
    k = int(sys.stdin.readline().strip())
    i = 1
    req = 1

    # Starting a while loop that continues as long as `k - req` is greater than or equal to 0
    while k - req >= 0:
        if k - req >= 0:
            k = k - req  # Updating the value of `k` by subtracting the value of `req`
        else:
            break  # Breaking out of the while loop if `k - req` is less than 0
        i += 1  # Incrementing the value of `i` by 1

        if i % n != 0:
            req = i % n  # Updating the value of `req` to the remainder of `i` divided by `n`
        else:
            req = n  # Updating the value of `req` to `n` if the remainder is equal to 0

    # Printing the value of `k` to the standard output
    print(k)

# Calling the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
