M = 1046527  # Size of the hash table
L = 14       # Maximum length of strings to be stored in the hash table

H = [''] * M  # Hash Table to store strings

# Function to convert a character to a corresponding integer value
def get_char(ch):
    if ch == 'A':
        return 1  # A maps to 1
    elif ch == 'C':
        return 2  # C maps to 2
    elif ch == 'G':
        return 3  # G maps to 3
    elif ch == 'T':
        return 4  # T maps to 4
    return 0  # Return 0 for any other character

# Convert a string into a unique integer key using a polynomial rolling hash
def get_key(s):
    sum = 0
    p = 1  # Initialize power
    for char in s:
        sum += p * get_char(char)  # Update sum with the character's value
        p *= 5  # Increase power of 5 for the next character
    return sum  # Return the computed key

# Hash function h1: Computes the primary hash index
def h1(key):
    return key % M

# Hash function h2: Computes the secondary hash index for collision resolution
def h2(key):
    return 1 + (key % (M - 1))

# Function to find a string in the hash table
def find(s):
    key = get_key(s)  # Get the key for the string
    i = 0  # Initialize index for probing
    while True:
        # Compute the hash index using double hashing
        hash_index = (h1(key) + i * h2(key)) % M
        if H[hash_index] == s:
            return True  # String found
        elif H[hash_index] == '':
            return False  # Empty slot indicates string not found
        i += 1  # Increment index for next probe

# Function to insert a string into the hash table
def insert(s):
    key = get_key(s)  # Get the key for the string
    i = 0  # Initialize index for probing
    while True:
        # Compute the hash index using double hashing
        hash_index = (h1(key) + i * h2(key)) % M
        if H[hash_index] == s:
            return True  # String already exists
        elif H[hash_index] == '':  # If the slot is empty
            H[hash_index] = s  # Insert the string
            return False  # Insertion successful
        i += 1  # Increment index for next probe

# Main function
def main():
    n = int(input())  # Read the number of commands

    # Process each command
    for _ in range(n):
        com, str_input = input().split()  # Read command and string

        # Check if the command is to insert a string
        if com[0] == 'i':
            insert(str_input)  # Insert the string into the hash table
        else:
            # If the command is not insert, check if the string exists
            if find(str_input):
                print("yes")  # String found
            else:
                print("no")  # String not found

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
