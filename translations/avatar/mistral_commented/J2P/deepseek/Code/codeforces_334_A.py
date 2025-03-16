import sys

def main():
    # Reading the number 'n' from the user
    n = int(input())

    # Calculating the square of the number 'n'
    square = n * n

    # Creating empty lists for odd and even numbers
    odd = []
    even = []

    # Looping from 1 to square
    for i in range(1, square + 1):
        if i % 2 == 0:  # If the number is even
            even.append(i)  # Add the number to the even list
        else:  # If the number is odd
            odd.append(i)  # Add the number to the odd list

    # Calculating the number of pairs to be printed
    loop = square // n
    div = loop // 2

    # Looping through each pair
    for i in range(1, loop + 1):
        for j in range(div):
            if i % 2 == 1:  # If the current pair is odd
                print(odd.pop(0), even.pop(-1), end=" ")  # Print the first and last numbers of the current pair
            else:  # If the current pair is even
                print(even.pop(0), odd.pop(-1), end=" ")  # Print the last and first numbers of the current pair
        print()  # Printing a newline after each pair

if __name__ == "__main__":
    main()

