import sys
from typing import List

# Reads a single string from the input.
def scan_string() -> str:
    return input().strip()

# Converts a scanned string to a list of characters.
def scan_runes() -> List[str]:
    return list(scan_string())

# Main function where the program execution begins.
def main():
    s = scan_runes()  # Reads the first string.
    t = scan_runes()  # Reads the second string.

    ans = []  # List to store possible valid strings.
    for i in range(len(s) - len(t) + 1):
        f = True  # Flag to check if the current position is valid.
        ss = s[:]  # Temporary list to hold the modified string.

        for j in range(len(t)):
            if s[i + j] != t[j] and s[i + j] != '?':  # Checks if there's a mismatch.
                f = False
                break
            else:
                ss[i + j] = t[j]  # Replaces the character in the temporary list.

        if f:
            ans.append(''.join(ss).replace('?', 'a'))  # Adds the valid string to the answer list.

    ans.sort()  # Sorts the answer list.
    if len(ans) == 0:
        print("UNRESTORABLE")  # Prints "UNRESTORABLE" if no valid string is found.
    else:
        print(ans[0])  # Prints the smallest valid string.

if __name__ == "__main__":
    main()

# <END-OF-CODE>
