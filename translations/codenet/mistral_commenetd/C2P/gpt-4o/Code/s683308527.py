# Include standard input/output library
# Include string manipulation library

def main():  # Start of the main function
    n = int(input())  # Read an integer 'n' from the standard input

    for _ in range(n):  # Start of the for loop that processes each string
        s = input()  # Read a string from the standard input

        while "Hoshino" in s:  # Start of the inner while loop that replaces the substring "Hoshino" with "aana"
            s = s.replace("Hoshino", "aana", 1)  # Replace the first occurrence of "Hoshino" with "aana"

        print(s)  # Print the modified string to the standard output

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
