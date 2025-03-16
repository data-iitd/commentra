

import sys

# Constructor for creating an instance of Main class and setting output stream to sys.stdout
class Main:
    def __init__(self):
        self.out = sys.stdout
        self.flush = self.out.flush
        self.write = self.out.write
        self.readable = self.out.readable
        self.readline = self.out.readline
        self.readlines = self.out.readlines

# Method to compare two character arrays aa and bb starting from their respective indices i and j
def compare(aa, i, bb, j, m):
    # Iterating through the character arrays until the length m is reached
    for _ in range(m):
        a = aa[i].upper()
        b = bb[j].upper()

        if a!= b:
            # If characters are not equal, return the difference of their ASCII values
            return ord(a) - ord(b)

        i += 1
        j += 1

    # If all characters match, return 0
    return 0

# Main method to read input and process it
def main():
    n = int(input())
    ss = [input().upper() for _ in range(n)]
    cc = input().upper()
    m = len(cc)
    c = input()[0].upper()
    a = 'A' if c == 'B' else 'B'
    c_ = c.lower()
    a_ = a.lower()
    lucky = [False] * m

    # Iterating through each character in cc and comparing it with all characters in each character array in ss
    for j in range(m):
        for i in range(n):
            l = len(ss[i])

            if m - j >= l and compare(cc, j, ss[i], 0, l) == 0:
                # If the length of cc minus the current index j is greater than or equal to the length of the character array in ss at the current index i, and if the comparison of the substrings starting from the current indices in cc and ss returns 0, then set the boolean value at the current index j in lucky to true
                for h in range(l):
                    lucky[j + h] = True

    # Iterating through each character in cc and updating it based on the boolean values in lucky
    for j in range(m):
        if lucky[j]:
            # If the boolean value at the current index j in lucky is true
            if cc[j] == c:
                # If the character at the current index j in cc is equal to the character c in lowercase
                cc = cc[:j] + a + cc[j + 1:]
            else:
                cc = cc[:j] + c + cc[j + 1:]

    # Printing the updated character array cc
    print(cc)

if __name__ == "__main__":
    main()

