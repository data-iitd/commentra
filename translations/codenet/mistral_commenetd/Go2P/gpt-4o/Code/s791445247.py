# by syu
import sys

def main():
    # Read the first two integers from the standard input
    n, k = map(int, sys.stdin.readline().split())

    # Check if n is divisible by k
    if n % k == 0:
        # If it is, print 0
        print(0)
    else:
        # If not, print 1
        print(1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
