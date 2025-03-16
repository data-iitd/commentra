def main():
    n = int(input())  # Read the number of characters in the string
    s = input()       # Read the input string

    max_count = 0     # Initialize max_count to 0
    count = 0         # Initialize count to 0

    for r in s:       # Loop through each character in the string s
        if r == 'I':  # If the character is 'I'
            count += 1  # Increment count
        else:          # If the character is 'D'
            count -= 1  # Decrement count

        if count > max_count:  # Check if the current count is greater than max_count
            max_count = count   # Update max_count to be equal to count

    print(max_count)  # Print the maximum value of count encountered

if __name__ == "__main__":
    main()

# <END-OF-CODE>
