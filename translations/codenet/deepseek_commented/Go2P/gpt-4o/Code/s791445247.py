import sys

def main():
    # Read two integers, n and k, from the input.
    n, k = map(int, sys.stdin.readline().split())
    
    # Check if n is divisible by k.
    if n % k == 0:
        # If n is divisible by k, print 0.
        print(0)
    else:
        # If n is not divisible by k, print 1.
        print(1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
