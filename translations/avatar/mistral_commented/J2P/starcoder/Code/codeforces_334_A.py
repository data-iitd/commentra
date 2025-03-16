
import sys

def main():
    # Reading the number 'n' from the user
    n = int(input())

    # Calculating the square of the number 'n'
    square = n * n

    # Creating an empty list for odd numbers
    odd = []

    # Creating an empty list for even numbers
    even = []

    # Looping from 1 to square
    for i in range(1, square + 1):
        # If the number is even
        if i % 2 == 0:
            # Add the number to the even list
            even.append(i)
        else:
            # Add the number to the odd list
            odd.append(i)

    # Calculating the number of pairs to be printed
    loop = square // n

    # Calculating half of the number of pairs
    div = loop // 2

    # Looping through each pair
    for i in range(1, loop + 1):
        # Looping through half of the pair
        for j in range(0, div):
            # If the current pair is odd
            if i % 2 == 1:
                # Print the first and last numbers of the current pair
                print(odd.pop(0), even.pop())
            else:
                # Print the last and first numbers of the current pair
                print(even.pop(), odd.pop())

        # Printing a newline after each pair
        print()

if __name__ == "__main__":
    main()

