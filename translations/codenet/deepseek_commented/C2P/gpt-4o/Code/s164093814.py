M = 1046527  # Size of the hash table
L = 14       # Maximum length of strings

H = [''] * M  # Hash Table

# Convert a character to an integer value
def get_char(ch):
    if ch == 'A':
        return 1
    elif ch == 'C':
        return 2
    elif ch == 'G':
        return 3
    elif ch == 'T':
        return 4
    return 0

# Convert a string into an integer value
def get_key(s):
    sum = 0
    p = 1
    for char in s:
        sum += p * get_char(char)
        p *= 5
    return sum

# First hash function
def h1(key):
    return key % M

# Second hash function
def h2(key):
    return 1 + (key % (M - 1))

# Search for a string in the hash table
def find(s):
    key = get_key(s)
    i = 0
    while True:
        hash_index = (h1(key) + i * h2(key)) % M
        if H[hash_index] == s:
            return True
        elif H[hash_index] == '':
            return False
        i += 1

# Insert a string into the hash table
def insert(s):
    key = get_key(s)
    i = 0
    while True:
        hash_index = (h1(key) + i * h2(key)) % M
        if H[hash_index] == s:
            return True
        elif H[hash_index] == '':
            H[hash_index] = s
            return False
        i += 1

# Main function to handle commands
def main():
    n = int(input())
    for _ in range(n):
        command, string = input().split()
        if command[0] == 'i':
            insert(string)
        else:
            if find(string):
                print("yes")
            else:
                print("no")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
