# Importing necessary modules
from typing import List

def main():
    x = int(input())  # Reading the first number from the standard input stream
    digits: List[int] = []  # Creating an empty list to store digits

    # The following while loop runs as long as the number x is greater than zero
    while x > 0:
        r = x % 10  # Storing the last digit of the number x in the variable r

        # The following if statement checks if the difference between 9 and the last digit r is less than r itself
        if 9 - r < r:
            # The following nested if statement checks if both x and the difference between 9 and the last digit r are zero
            if x // 10 == 0 and 9 - r == 0:
                digits.append(r)  # Adding the last digit r to the list if it is the only digit in the number x
            else:
                digits.append(9 - r)  # Adding the number 9 minus the last digit r to the list
        else:
            digits.append(r)  # Adding the last digit r to the list

        x = x // 10  # Dividing the number x by 10 to get the next digit

    new_number = 0  # Initializing the variable new_number to 0 to store the final number
    pow = 0  # Initializing the variable pow to 0 to be used as the power of 10

    # The following for loop runs through each digit in the list and calculates the new number
    for digit in digits:
        new_number += digit * (10 ** pow)  # Adding the digit multiplied by the power of 10 to new_number
        pow += 1  # Incrementing the power

    print(new_number)  # Printing the final number to the standard output stream

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
