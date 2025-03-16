# Main function starts here
def main():
    # Loop to read input values from the standard input
    while True:
        try:
            a = int(input())  # Read an integer from input
        except EOFError:
            break  # Exit the loop on end of input

        # Initialize c and k to zero
        c = 0
        k = 0

        # Check if the input value is less than 3
        if a < 3:
            # If yes, print 0 and exit the loop
            print("0")
            break

        # Assign the value of input 'a' to variable 'b'
        b = a

        # Loop to process each digit of the input number 'a'
        while a > 0:
            # Decrement the value of 'b' by 1
            b -= 1

            # Increment the value of 'c' by 1
            c += 1

            # Check if the value of 'c' is equal to 3
            if c == 3:
                # If yes, increment the value of 'k' by 1 and reset the value of 'c' to zero
                k += 1
                c = 0

            a -= 1  # Decrement 'a' to process the next digit

        # Print the value of 'k' as the output
        print(k)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
