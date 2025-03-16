import sys

def main():
    # Read two integers from input
    A, B = map(int, sys.stdin.readline().split())

    # Calculate the maximum of A+B, A-B, and A*B
    mx = max(A + B, A - B, A * B)
    
    # Print the maximum value
    print(mx)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
