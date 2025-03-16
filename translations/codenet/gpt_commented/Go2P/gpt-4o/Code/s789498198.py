import sys

def main():
    # Read two integers from input
    A, B = map(int, input().split())

    # Check if the sum of A and B is even
    if (A + B) % 2 == 0:
        # If even, print the average
        print((A + B) // 2)
    else:
        # If odd, print "IMPOSSIBLE"
        print("IMPOSSIBLE")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
