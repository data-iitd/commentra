# Include the standard input-output library

def main():  # Define the main function, the entry point of the program
    h, r = map(int, input().split())  # Read two integers from the standard input and store them in h and r
    if r > -h:  # Check if r is greater than -h
        print("1")  # If true, print 1
    elif r == -h:  # If the condition in the if statement is false, check if r is equal to -h
        print("0")  # If true, print 0
    else:  # If neither of the above conditions is true
        print("-1")  # Print -1

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
