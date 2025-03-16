import sys
from typing import List

# Function to read a single string
def scan_string() -> str:
    return sys.stdin.readline().strip()

# Function to read a single integer
def scan_int() -> int:
    return int(scan_string())

# Function to read multiple integers
def scan_ints(n: int) -> List[int]:
    return list(map(int, scan_string().split()))

# Main function
def main():
    # Reading input strings s and t
    s = list(scan_string())
    t = list(scan_string())

    # Initializing an empty list to store answers
    ans = []

    # Iterating through all possible substrings of s that have the same length as t
    for i in range(len(s) - len(t) + 1):
        # Initializing a list to store the modified string s
        ss = s[:]

        # Checking if the current substring matches the pattern t
        f = True
        for j in range(len(t)):
            # If the current character of s does not match the current character of t or is not '?'
            if ss[i + j] != t[j] and ss[i + j] != '?':
                # Setting flag to false and breaking the loop
                f = False
                break
            else:
                # Replacing the current character of s with the corresponding character of t
                ss[i + j] = t[j]

        # If the current substring matches the pattern t
        if f:
            # Appending the modified string to the answer list
            ans.append(''.join(ss).replace('?', 'a'))

    # Sorting the answer list in ascending order
    ans.sort()

    # Checking if the answer list is empty
    if not ans:
        # Printing "UNRESTORABLE" if the answer list is empty
        print("UNRESTORABLE")
    else:
        # Printing the first element of the answer list
        print(ans[0])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
