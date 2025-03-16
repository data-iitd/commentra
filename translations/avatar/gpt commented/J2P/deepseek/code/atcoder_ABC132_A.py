from collections import Counter
import sys

def main():
    # Read the input string from the user
    s = input()
    
    # Count the frequency of each character in the string
    char_count = Counter(s)
    
    # Initialize a boolean variable to check if the conditions are met
    ok = True
    
    # Check if each character appears exactly twice
    for count in char_count.values():
        if count != 2:
            ok = False  # Set ok to false if any character does not appear twice
            break
    
    # Check if there are exactly two unique characters that appear twice
    if ok and len(char_count) == 2:
        print("Yes")  # Output "Yes" if conditions are satisfied
    else:
        print("No")  # Output "No" if conditions are not satisfied

if __name__ == "__main__":
    main()
