# Import necessary modules
from collections import defaultdict

# Main function to execute the program
def main():
    s = input()  # Read the first input string
    t = input()  # Read the second input string

    # Initialize counters for unique characters in the first string and opposite characters in the second string
    ura = 0
    opa = 0

    # Create a dictionary to store the frequency of each character in the second string
    tmap = defaultdict(int)

    # Read the characters of the second string and store their frequencies in the dictionary
    for ch in t:
        tmap[ch] += 1

    # Process the first string
    length = len(s)
    s_list = list(s)  # Convert string to list for mutability
    for i in range(length):
        ch = s_list[i]
        num = tmap.get(ch)
        if num is None:  # If the character is not in the second string
            continue
        if num == 1:  # If the character appears only once in the second string
            del tmap[ch]  # Remove it from the dictionary
        else:
            tmap[ch] -= 1  # Decrement its frequency
        s_list[i] = 'Я'  # Replace the character in the list with 'Я'
        ura += 1  # Increment the counter for unique characters

    # Process the reversed version of the first string
    for i in range(length):
        ch = s_list[i]
        rch = reverse(ch)  # Get the reverse character of the current character
        num = tmap.get(rch)
        if num is None:  # If the reverse character is not in the second string
            continue
        if num == 1:  # If the reverse character appears only once in the second string
            del tmap[rch]  # Remove it from the dictionary
        else:
            tmap[rch] -= 1  # Decrement its frequency
        opa += 1  # Increment the counter for opposite characters

    # Print the results
    print(ura, opa)

# Reverse the given character
def reverse(ch):
    if ch.islower():  # If the character is lowercase
        return ch.upper()  # Return its uppercase version
    else:
        return ch.lower()  # If the character is uppercase, return its lowercase version

# Execute the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
