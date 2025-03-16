

import sys
# Import the sys module to access the exit function

def main():
    s = input()
    # Read the input string

    targ = list(s)
    # Convert the string to a list of characters

    char_count = {}
    # Initialize a dictionary to store character counts

    for c in targ:
        # Loop through each character in the list
        if c not in char_count:
            # If the character is not already in the dictionary, add it with a count of 1
            char_count[c] = 1
        else:
            # If the character is already in the dictionary, increment its count
            char_count[c] += 1

    ok = True
    # Initialize a boolean flag to check the conditions

    for c, count in char_count.items():
        # Loop through each key-value pair in the dictionary
        if count!= 2:
            # If any character count is not 2, set ok to False and break the loop
            ok = False
            break

    if ok and len(char_count) == 2:
        # Check if all characters appear exactly twice and there are exactly 2 unique characters
        print("Yes")
        # Print "Yes" if the conditions are met
    else:
        print("No")
        # Print "No" otherwise

if __name__ == "__main__":
    main()
    # Call the main function

