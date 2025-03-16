def main():
    # Read input from the user
    s = input()

    # Initialize a counter for consecutive valid characters and a list to hold counts
    count = 0
    counter = []

    # If the input string is empty, exit the function
    if s == "":
        return

    # Start the counter with an initial value of 0
    counter.append(0)

    # Iterate over each character in the string
    for char in s:
        # Check if the character is one of the valid DNA bases
        if char in "ACGT":
            # Increment the count for consecutive valid characters
            count += 1
        else:
            # If an invalid character is encountered, store the current count
            counter.append(count)
            # Reset the count for the next sequence
            count = 0

    # Append the count of the last sequence of valid characters
    counter.append(count)
    # Sort the counts to find the maximum consecutive valid characters
    counter.sort()
    # Print the maximum count of consecutive valid characters
    print(counter[-1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
