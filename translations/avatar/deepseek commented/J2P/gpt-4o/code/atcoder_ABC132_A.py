from collections import defaultdict

def main():
    s = input()  # Read the input string

    # Initialize a defaultdict to store character counts
    char_count = defaultdict(int)

    for char in s:  # Loop through each character in the string
        char_count[char] += 1  # Increment the count for the character

    ok = True  # Initialize a boolean flag to check the conditions

    for count in char_count.values():  # Loop through each character count
        if count != 2:  # If any character count is not 2, set ok to false
            ok = False
            break

    if ok and len(char_count) == 2:  # Check if all characters appear exactly twice and there are exactly 2 unique characters
        print("Yes")  # Print "Yes" if the conditions are met
    else:
        print("No")  # Print "No" otherwise

if __name__ == "__main__":
    main()

# <END-OF-CODE>
