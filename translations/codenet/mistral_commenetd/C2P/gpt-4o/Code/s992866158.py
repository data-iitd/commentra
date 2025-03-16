# The main function is the entry point of the program
def main():
    # Read two integers n and k from the standard input
    n, k = map(int, input().split())
    # Initialize variable cnt to zero
    cnt = 0
    # Loop through n times
    for _ in range(n):
        # Read an integer h from the standard input
        h = int(input())
        # If h is greater than or equal to k, increment cnt by 1
        if h >= k:
            cnt += 1
    # Print the value of cnt to the standard output
    print(cnt)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
