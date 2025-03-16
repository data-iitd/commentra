# Include the standard input-output header file

def main():
    n, k = map(int, input().split())  # Read two integers from the standard input
    if n % k == 0:                     # Check if n is divisible by k
        print("0")                     # If true, print 0
    else:
        print("1")                     # If false, print 1

if __name__ == "__main__":
    main()                             # Call the main function

# <END-OF-CODE>
