def search_range(text, start, limit):
    middle = -1  # Initialize the middle position to -1

    # Find the first 'R' from the start position
    for i in range(start, limit):
        if text[i] != 'R':
            middle = i  # Set middle to the current position if 'R' is found
            break  # Break the loop as we found the first 'R'

    end = limit  # Initialize the end position to the limit

    # Find the first 'L' after the middle position
    for i in range(middle, limit):
        if text[i] != 'L':
            end = i  # Set end to the current position if 'L' is found
            break  # Break the loop as we found the first 'L'

    return start, middle, end  # Return the start, middle, and end positions


def answer():
    text = input()  # Read the input string
    limit = len(text)  # Get the length of the input string

    start = 0  # Initialize the start position
    middle = 0  # Initialize the middle position
    end = 0  # Initialize the end position
    first_printed = False  # Initialize a flag to check if it's the first printed

    # Loop to find and print the counts of 'R' and 'L' in the specified ranges
    while end < limit:
        start, middle, end = search_range(text, start, limit)  # Update the start, middle, and end positions
        len1 = middle - start  # Calculate the length of the first segment
        len2 = end - middle  # Calculate the length of the second segment

        # Print '0's for the first segment
        for i in range(start, middle - 1):
            if first_printed:
                print(" ", end="")  # Print a space if not the first printed
            print("0", end="")  # Print '0'
            first_printed = True  # Set the flag to true

        # Calculate the counts of 'R' and 'L'
        count1 = (len1 + 1) // 2 + len2 // 2
        count2 = len1 // 2 + (len2 + 1) // 2

        if first_printed:
            print(" ", end="")  # Print a space if not the first printed
        print(f"{count1} {count2}", end="")  # Print the counts
        first_printed = True  # Set the flag to true

        # Print '0's for the second segment
        for i in range(middle + 1, end):
            if first_printed:
                print(" ", end="")  # Print a space if not the first printed
            print("0", end="")  # Print '0'
            first_printed = True  # Set the flag to true
        start = end  # Update the start position
        first_printed = True  # Set the flag to true

    print()  # Print a newline at the end


if __name__ == "__main__":
    answer()  # Call the answer function
# <END-OF-CODE>
