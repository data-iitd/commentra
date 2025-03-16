import sys

def main():
    # Continuously read integers from standard input until EOF
    for line in sys.stdin:
        a = int(line.strip())  # Read and convert input to integer
        c = 0  # Initialize count of individual items
        k = 0  # Initialize count of groups of three

        # Check if the input number is less than 3
        if a < 3:
            print("0")  # If less than 3, print 0 (no groups can be formed)
        else:
            b = a  # Store the original value of a in b for later use

            # Loop to count down from a to 0
            while a > 0:
                b -= 1  # Decrement b
                c += 1  # Increment the count of items

                # Check if we have counted three items
                if c == 3:
                    k += 1  # Increment the count of groups of three
                    c = 0  # Reset the count of items for the next group

                a -= 1  # Decrement a

            # Print the total number of groups of three formed
            print(k)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
