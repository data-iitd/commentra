# The main function is the entry point of the program
def main():
    # Read two integers from the standard input
    n, k = map(int, input().split())

    # Check if 'n' is divisible by 'k'
    if n % k == 0:
        # If it is, print '0' to the standard output
        print("0")
    else:
        # If it's not, print '1' to the standard output
        print("1")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
