import sys  # Importing required packages for input and output

def main():
    # Initializing input and output
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Reading the number 'n' from the user

    square = n * n  # Calculating the square of the number 'n'

    odd = []  # Creating an empty list for odd numbers
    even = []  # Creating an empty list for even numbers

    for i in range(1, square + 1):  # Looping from 1 to square
        if i % 2 == 0:  # If the number is even
            even.append(i)  # Add the number to the even list
        else:  # If the number is odd
            odd.append(i)  # Add the number to the odd list

    loop = square // n  # Calculating the number of pairs to be printed
    div = loop // 2  # Calculating half of the number of pairs

    output = []  # List to collect output lines
    for i in range(1, loop + 1):  # Looping through each pair
        for j in range(div):  # Looping through half of the pair
            if i % 2 == 1:  # If the current pair is odd
                output.append(f"{odd.pop(0)} {even.pop(-1)} ")  # Print the first and last numbers of the current pair
            else:  # If the current pair is even
                output.append(f"{even.pop(0)} {odd.pop(-1)} ")  # Print the last and first numbers of the current pair
        output.append("\n")  # Adding a newline after each pair

    sys.stdout.write(''.join(output))  # Writing all output at once

if __name__ == "__main__":
    main()

# <END-OF-CODE>
