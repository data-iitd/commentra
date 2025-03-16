def main():
    n, k = map(int, input().split())  # Read two integers from the standard input
    if n % k == 0:                    # Check if n is divisible by k
        print(0)                      # If true, print 0
    else:
        print(1)                      # If false, print 1


main()  # Call the main function
