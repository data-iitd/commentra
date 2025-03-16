def main():
    sum = 0
    x = input()  # Read the first string from the input
    while x[0] != '0':  # Continue the loop until a string starting with '0' is encountered
        for char in x:  # Loop through each character in the string
            sum += int(char)  # Convert the character to its corresponding digit and add it to the sum
        print(sum)  # Print the sum of the digits
        sum = 0  # Reset the sum for the next string
        x = input()  # Read the next string from the input

if __name__ == "__main__":
    main()

# <END-OF-CODE>
