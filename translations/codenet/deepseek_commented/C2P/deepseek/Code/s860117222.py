def main():
    a, b, c = map(int, input().split())  # Read three integers from the user

    d = c - a - b  # Calculate the difference between c and the sum of a and b
    if d > 0 and (4 * a * b) < d * d:  # Check if the difference is positive and satisfies the specific condition
        print("Yes")  # Print "Yes" if the condition is met
    else:
        print("No")  # Print "No" otherwise


main()  # Call the main function
