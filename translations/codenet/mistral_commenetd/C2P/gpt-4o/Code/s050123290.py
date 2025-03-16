N = 1000  # Define a constant N with the value 1000

def main():
    while True:  # Start an infinite loop
        su = []  # Declare a list 'su' to store characters
        susum = 0  # Initialize an integer variable 'susum' to zero

        for j in range(N):  # Iterate through each index of the range N
            char = input()  # Read a character from the standard input
            if char == '\n':  # If the character read is a newline character, break out of the loop
                break
            su.append(char)  # Append the character to the list 'su'
            susum += (ord(char) - ord('0'))  # Add the integer value of the character to 'susum'

        if su and su[0] == '0':  # If the first character of the list 'su' is '0', break out of the loop
            break
        print(susum)  # Print the sum of the digits read from the standard input

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
