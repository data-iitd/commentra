def main():
    # Read two integers from the standard input (stdin) and store them in A and B
    A, B = map(int, input().split())
    
    # Check if A is between 6 and 12 (inclusive)
    if 6 <= A < 13:
        # If true, calculate B/2 and print the result
        print(B // 2)
    
    # Check if A is less than 6
    if A < 6:
        # If true, print 0
        print(0)
    
    # Check if A is 13 or more
    if A >= 13:
        # If true, print the value of B
        print(B)

# Call the main function
main()

