# Include the standard input/output library

def main():
    i = 1  # Declare and initialize variable i
    while True:  # Start an infinite loop
        Input = int(input())  # Read an integer from the user
        if Input == 0:  # Check if the input is 0
            break  # Exit the loop if the input is 0
        print(f"Case {i}: {Input}")  # Print the current case number and input value
        i += 1  # Increment the case number

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
