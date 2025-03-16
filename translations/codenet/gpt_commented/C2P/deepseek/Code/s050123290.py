N = 1000  # Define a constant N to represent the maximum size of the input array

def main():
    while True:
        su = ['0'] * N  # Declare a list to store the input, initialized with '0'
        susum = 0  # Initialize a variable to hold the sum of the digits
        j = 0  # Initialize a counter variable for the loop

        # Loop to read characters into the list until a newline is encountered or the limit is reached
        while True:
            char = input()  # Read a character from standard input
            if char == '\n':
                break
            su[j] = char
            susum += int(char)  # Convert the character to an integer and add it to the sum
            j += 1

        # Check if the first character is '0', which indicates the end of input
        if su[0] == '0':
            break  # Exit the loop if the first character is '0'

        print(susum)  # Print the sum of the digits read

if __name__ == "__main__":
    main()
