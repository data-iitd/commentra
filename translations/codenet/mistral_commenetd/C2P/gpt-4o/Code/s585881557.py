# Include the standard input/output library

def main():  # The entry point of the program
    h, r = map(int, input().split())  # Read two integers from the standard input and store them in variables h and r
    if r > -h:  # Check if r is greater than the negative value of h
        print("1")  # If the condition is true, print the number 1 followed by a newline character
    elif r == -h:  # Check if r is equal to the negative value of h
        print("0")  # If the condition is true, print the number 0 followed by a newline character
    else:  # If the previous conditions are false
        print("-1")  # Print the number -1 followed by a newline character

if __name__ == "__main__":  # Ensure the main function runs when the script is executed
    main()

# <END-OF-CODE>
