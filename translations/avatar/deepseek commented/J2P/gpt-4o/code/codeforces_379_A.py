def main():
    a = int(input())  # Read the first integer input
    b = int(input())  # Read the second integer input
    res = a  # Initialize result variable with the value of a

    # Enter a while loop that continues as long as a is greater than or equal to b
    while a >= b:
        res += (a // b)  # Update result by adding the integer division of a by b
        a = (a // b) + (a % b)  # Update a to be the sum of the integer division and remainder

    print(res)  # Print the final value of res

if __name__ == "__main__":
    main()

# <END-OF-CODE>
