import sys

def main():
    n = int(input())  # Read the size of the grid
    square = n * n  # Calculate the total number of elements

    odd = []  # List to store odd numbers
    even = []  # List to store even numbers

    # Separating numbers into odd and even lists
    for i in range(1, square + 1):
        if i % 2 == 0:
            even.append(i)  # Add even numbers to the even list
        else:
            odd.append(i)  # Add odd numbers to the odd list

    loop = square // n  # Calculate the number of rows/columns
    div = loop // 2  # Calculate half the number of elements in each row/column

    debug(div)  # Debugging statement to print the value of div

    # Nested loops to generate the pattern
    for i in range(1, loop + 1):
        for j in range(div):
            if i % 2 == 1:
                print(odd.pop(0), even.pop(-1), end=" ")  # Print odd and even numbers in reverse order for odd rows
            else:
                print(even.pop(0), odd.pop(-1), end=" ")  # Print even and odd numbers in reverse order for even rows
        print()  # Move to the next line after each row

def debug(*obj):
    print(obj, file=sys.stderr)  # Debugging statement to print the object array

if __name__ == "__main__":
    main()

# <END-OF-CODE>
