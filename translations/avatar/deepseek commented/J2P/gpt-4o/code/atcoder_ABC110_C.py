# Importing sys for input
import sys

def main():
    S = sys.stdin.readline().strip()  # Read input string S
    T = sys.stdin.readline().strip()  # Read input string T

    A = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]  # Array of all lowercase letters

    res = True  # Initialize result as true

    # Loop through each letter in the alphabet
    for s in A:
        sIdx = S.find(s)  # Find the index of the current letter in S
        if sIdx < 0:
            continue  # If the letter is not in S, continue to the next letter

        t = T[sIdx]  # Find the corresponding letter in T

        idx = 0  # Initialize index for comparison
        while idx < len(S):
            if S.find(s, idx) >= 0:  # If the letter appears in S from the current index
                if S.find(s, idx) != T.find(t, idx):  # Check if the positions match
                    res = False  # If positions do not match, set res to false
                    break  # Break out of the loop
                else:
                    idx = S.find(s, idx) + 1  # Update index to check the next position
            elif T.find(t, idx) >= 0:  # If the letter appears in T from the current index
                res = False  # If positions do not match, set res to false
                break  # Break out of the loop
            else:
                break  # If neither letter appears, break out of the loop
        if not res:
            break  # If res is false, break out of the outer loop

    if res:
        print("Yes")  # If res is true, print "Yes"
    else:
        print("No")  # If res is false, print "No"

if __name__ == "__main__":
    main()

# <END-OF-CODE>
