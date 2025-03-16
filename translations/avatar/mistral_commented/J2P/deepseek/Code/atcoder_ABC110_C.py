def main():
    # Read the first input line from the console
    S = input()

    # Read the second input line from the console
    T = input()

    # Initialize an array of strings A with all possible characters from a to z
    A = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]

    # Initialize a boolean variable res to store the result of the comparison
    res = True

    # Iterate through each string s in the array A
    for s in A:
        # Find the index of string s in string S
        s_idx = S.find(s)

        # If string s is not found in string S, continue to the next string in the array
        if s_idx == -1:
            continue

        # Convert the character at the index s_idx in string T to a string
        t = str(T[s_idx])

        # Initialize an index variable idx to 0
        idx = 0

        # Iterate through each character in string S starting from the index s_idx
        while idx < len(S):
            # If string s is found in string S starting from index idx, compare the corresponding characters in strings S and T
            if S.find(s, idx) >= 0:
                if S.find(s, idx) != T.find(t, idx):
                    # If the characters do not match, set the boolean variable res to False and break out of the loop
                    res = False
                    break
                else:
                    # If the characters match, increment the index variable idx by the length of string s
                    idx = S.find(s, idx) + 1
            # If string s is not found in string T starting from index idx, set the boolean variable res to False and break out of the loop
            elif T.find(t, idx) >= 0:
                res = False
                break
            # If string s is not found in both strings S and T starting from index idx, break out of the loop
            else:
                break

        # If the boolean variable res is still True after the loop, print "Yes" to the console
        if res:
            print("Yes")
        # If the boolean variable res is False, print "No" to the console and break out of the main loop
        else:
            print("No")
            break

# Call the main function
main()
