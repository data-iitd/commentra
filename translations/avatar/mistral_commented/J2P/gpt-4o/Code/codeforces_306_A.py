# Importing the necessary modules
import sys

def main():
    # Reading the first two integers from the input
    n = int(input())
    m = int(input())

    # Creating a list 'a' of size 'm'
    a = [0] * m

    # Checking if 'n' is divisible by 'm'
    if n % m == 0:
        # If 'n' is divisible by 'm', then 'n' can be divided evenly by 'm'
        # So, all elements of 'a' will be equal to the quotient of 'n' and 'm'
        for i in range(len(a)):
            a[i] = n // m  # Assigning the quotient to each element of 'a'
    else:
        # If 'n' is not divisible by 'm', then 'n' can't be divided evenly by 'm'
        # So, we need to calculate the quotient 'sub' and the remainder 'test' of 'n' by 'm'
        sub = n // m

        # All elements of 'a' will be equal to 'sub', except for some elements at the end
        for i in range(len(a)):
            a[i] = sub  # Assigning 'sub' to each element of 'a'

        # Calculating the number of extra elements needed at the end of 'a'
        test = n - (sub * m)

        # Adding '1' to each extra element of 'a'
        count = 0
        for i in range(test):
            a[count] += 1  # Incrementing the value of each extra element by '1'
            count += 1

            # If we reach the end of 'a', then we reset the index to '0'
            if count >= len(a):
                count = 0

    # Printing the elements of 'a' in reverse order
    for i in range(len(a) - 1, -1, -1):
        print(a[i], end=" ")

# Calling the main function to execute the code
if __name__ == "__main__":
    main()

# <END-OF-CODE>
