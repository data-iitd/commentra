# Import necessary modules
import sys

def main():
    # Read two integers n and m from the input
    n, m = map(int, sys.stdin.readline().split())
    
    # Check if n is zero
    if n == 0:
        # If m is not zero, print "Impossible" since we cannot form a valid output
        if m != 0:
            print("Impossible")
        # If m is also zero, print "0 0" as the valid output
        else:
            print(0, 0)
        return
    
    # Check if m is less than or equal to n
    if m <= n:
        # If m is zero, set it to one to ensure valid output
        if m == 0:
            m = 1
        # Print n and the adjusted value of m
        print(n, m + n - 1)
        return
    
    # If m is greater than n, print m and the adjusted value of m
    print(m, m + n - 1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
