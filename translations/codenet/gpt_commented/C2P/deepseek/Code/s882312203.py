def main():
    # Read a string from standard input
    s = input()

    # Loop through each character in the string
    for j in range(len(s)):
        # Compare the current character with every other character in the string
        for i in range(len(s)):
            # Check if the characters are the same and they are not the same position
            if (i != j) and (s[i] == s[j]):
                # If a duplicate character is found, print "no" and exit the program
                print("no")
                return

    # If no duplicates were found, print "yes"
    print("yes")


main()
