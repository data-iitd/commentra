M = 1046527  # your task
L = 14

H = [''] * M  # Hash Table

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

# convert a string into an integer value
def get_key(s):
    sum = 0
    p = 1
    for char in s:
        sum += p * get_char(char)
        p *= 5
    return sum

def h1(key):
    return key % M

def h2(key):
    return 1 + (key % (M - 1))

def find(s):
    key = get_key(s)
    i = 0
    while True:
        hash_index = (h1(key) + i * h2(key)) % M
        if H[hash_index] == s:
            return True
        elif len(H[hash_index]) == 0:
            return False
        i += 1

def insert(s):
    key = get_key(s)
    i = 0
    while True:
        hash_index = (h1(key) + i * h2(key)) % M
        if H[hash_index] == s:
            return True
        elif len(H[hash_index]) == 0:
            H[hash_index] = s
            return False
        i += 1

def main():
    n = int(input())
    for _ in range(n):
        com, str_input = input().split()
        if com[0] == 'i':
            insert(str_input)
        else:
            if find(str_input):
                print("yes")
            else:
                print("no")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
