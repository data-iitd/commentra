# Main function starts here
def main():
    # Declare and initialize variables
    N = input("Enter a number: ")  # string to store the input number
    S = 0  # sum of digits of the number

    # Calculate the sum of digits of the number
    for digit in N:
        # Increment the sum by the integer value of the current digit
        S += int(digit)

    # Check if the number is divisible by the sum of its digits
    if int(N) % S == 0:  # Convert the string to an integer using int()
        print("Yes")  # Output "Yes" if the number is divisible
    else:
        print("No")  # Output "No" otherwise

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
