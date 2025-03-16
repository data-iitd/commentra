import math  # Importing the math library to use power function

def main():
    N = int(input())  # Reading the first integer value from the standard input stream and assigning it to the variable 'N'

    count = 0  # Initializing the counter variable 'count' to zero
    temp = N  # Assigning the value of 'N' to the variable 'temp'

    # The following while loop calculates the number of digits in the given integer 'N'
    while temp > 0:
        temp //= 10  # Dividing the current value of 'temp' by 10 to get the last digit
        count += 1  # Incrementing the counter variable 'count' by 1

    ans = 0  # Initializing the answer variable 'ans' to zero

    for i in range(1, count + 1):  # The following for loop iterates through each digit of the given integer 'N'
        if i == count:  # If the current digit is the last digit
            if N % 10 % 2 == 1:  # If the last digit is odd
                ans += (N - 10 ** (i - 1) + 1)  # Adding the sum of digits before the last odd digit to the answer
        else:  # If the current digit is not the last digit
            if i == 1:  # If the current digit is the first digit
                ans += 9  # Adding the number of digits after the first digit to the answer
            elif i % 2 == 1:  # If the current digit is odd
                ans += (10 ** i - 10 ** (i - 1))  # Adding the difference between the 10 raised to the power of the current digit and the 10 raised to the power of the previous digit to the answer

    print(ans)  # Printing the final answer to the standard output stream

if __name__ == "__main__":
    main()

# <END-OF-CODE>
