import sys

# Main function is the entry point of the Python application
def main():
    # Reading the first integer value from the standard input stream and assigning it to the variable 'N'
    N = int(sys.stdin.readline().strip())

    # Initializing the counter variable 'count' to zero
    count = 0
    temp = N

    # The following while loop calculates the number of digits in the given integer 'N'
    while temp > 0:
        temp //= 10  # Dividing the current value of 'temp' by 10 to get the last digit
        count += 1  # Incrementing the counter variable 'count' by 1

    ans = 0  # Initializing the answer variable 'ans' to zero

    # The following for loop iterates through each digit of the given integer 'N'
    for i in range(1, count + 1):
        if i == count:  # If the current digit is the last digit
            if i % 2 == 1:  # If the last digit is odd
                ans += (N - 10 ** (i - 1) + 1)  # Adding the sum of digits before the last odd digit to the answer
        else:  # If the current digit is not the last digit
            if i == 1:  # If the current digit is the first digit
                ans += 9  # Adding the number of digits after the first digit to the answer
            elif i % 2 == 1:  # If the current digit is odd
                ans += (10 ** i - 10 ** (i - 1))  # Adding the difference between the 10 raised to the power of the current digit and the 10 raised to the power of the previous digit to the answer

    # Printing the final answer to the standard output stream
    print(ans)

# Calling the main function
if __name__ == "__main__":
    main()
