M = 1046527  # Define the size of the hash table
L = 14       # Define the length of each string in the hash table

H = [''] * M  # Declare a list named H as the hash table

def get_char(ch):
    """A helper function to convert a single character into its corresponding integer value."""
    if ch == 'A':
        return 1
    elif ch == 'C':
        return 2
    elif ch == 'G':
        return 3
    elif ch == 'T':
        return 4
    return 0

def get_key(s):
    """A function to convert a string into an integer value."""
    sum = 0
    p = 1
    for char in s:
        sum += p * get_char(char)
        p *= 5
    return sum

def h1(key):
    """A helper function to calculate the first hash index."""
    return key % M

def h2(key):
    """A helper function to calculate the second hash index."""
    return 1 + (key % (M - 1))

def find(s):
    """A function to check if a string is already present in the hash table."""
    key = get_key(s)  # Calculate the key for the given string
    i = 0
    while True:
        hash_index = (h1(key) + i * h2(key)) % M
        if H[hash_index] == s:
            return True
        elif H[hash_index] == '':
            return False
        i += 1

def insert(s):
    """A function to insert a string into the hash table."""
    key = get_key(s)  # Calculate the key for the given string
    i = 0
    while True:
        hash_index = (h1(key) + i * h2(key)) % M
        if H[hash_index] == '':
            H[hash_index] = s  # Copy the string into the empty index
            return
        i += 1

def main():
    n = int(input())  # Read the number of operations
    for _ in range(n):
        command, string = input().split()  # Read a command and a string
        if command[0] == 'i':
            # If the command is 'insert', insert the string into the hash table
            insert(string)
        else:
            # If the command is 'find', check if the string is present in the hash table
            if find(string):
                print("yes")
            else:
                print("no")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
