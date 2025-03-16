# Include the standard input/output library

def main():
    n = input()  # Read a string from the user input

    # Check if any two consecutive characters in the string n are the same
    if (n[0] == n[1] == n[2]) or (n[1] == n[2] == n[3]):
        print("Yes")  # Print "Yes" if the condition is true
    else:
        print("No")  # Print "No" if the condition is false

if __name__ == "__main__":
    main()

# <END-OF-CODE>
