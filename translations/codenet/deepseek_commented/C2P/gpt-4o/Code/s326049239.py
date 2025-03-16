# Main function to execute the program
def main():
    import sys

    # Start a while loop to read input
    for line in sys.stdin:
        a = int(line.strip())  # Read an integer 'a' from the input

        c = 0  # Initialize counter 'c' to 0
        k = 0  # Initialize counter 'k' to 0

        if a < 3:  # Check if 'a' is less than 3
            print("0")  # Print 0 if 'a' is less than 3
        else:
            b = a  # Store the initial value of 'a' in 'b' for later use
            while a > 0:  # Decrement 'a' until it becomes 0
                b -= 1  # Decrement 'b' in each iteration
                c += 1  # Increment 'c' in each iteration
                if c == 3:  # Check if 'c' equals 3
                    k += 1  # Increment 'k'
                    c = 0  # Reset 'c' to 0
                a -= 1  # Decrement 'a' in each iteration
            print(k)  # Print the number of times 'c' reset to 0

if __name__ == "__main__":
    main()

# <END-OF-CODE>
