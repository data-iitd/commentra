def main():
    # Read three integers from standard input
    a, b, c = map(int, input().split())

    # Check if the sum of a and b is greater than or equal to c
    if a + b >= c:
        # If the condition is true, print "Yes"
        print("Yes")
    else:
        # If the condition is false, print "No"
        print("No")

# Call the main function
main()

