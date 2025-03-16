import sys

def main():
    # Allow local testing with a specific file
    # Uncomment the line below to read from a specific file
    # sys.stdin = open("dataabc155A.txt", "r")

    a = int(sys.stdin.readline().strip())  # Read integer a
    b = int(sys.stdin.readline().strip())  # Read integer b

    if a < b:  # Check if a is less than b
        for _ in range(b):
            print(a, end=' ')  # Print a b times
        print()  # New line
    else:  # Otherwise
        for _ in range(a):
            print(b, end=' ')  # Print b a times
        print()  # New line

if __name__ == "__main__":
    main()

# <END-OF-CODE>
