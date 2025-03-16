# by syu
import sys

def main():
    # Read two integers n and k from input
    n, k = map(int, sys.stdin.readline().split())
    
    # Check if n is divisible by k
    if n % k == 0:
        # If divisible, print 0
        print(0)
    else:
        # If not divisible, print 1
        print(1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
