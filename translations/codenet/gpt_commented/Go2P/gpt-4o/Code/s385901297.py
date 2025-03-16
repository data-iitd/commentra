# Import necessary modules
import sys

def main():
    # Read a line of input and parse it into a list of integers
    ns = list(map(int, sys.stdin.readline().strip().split()))

    # Sort the list of integers in ascending order
    ns.sort()

    # Check if the sorted integers match the specific sequence [1, 4, 7, 9]
    if ns == [1, 4, 7, 9]:
        # If they match, print "YES"
        print("YES")
    else:
        # If they do not match, print "NO"
        print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
