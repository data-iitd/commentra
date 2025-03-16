# Importing necessary packages
import re

# Main function
def main():
    # Reading the first word from the user input
    word1 = re.sub(r'[^a-zA-Z]', '', input()).lower()
    # This block of code reads a line from the user input, removes all non-alphabetic characters, and converts it to lowercase.
    # The resulting string is stored in the 'word1' variable.

    # Reading the second word from the user input
    word2 = re.sub(r'[^a-zA-Z]', '', input()).lower()
    # This block of code reads a line from the user input, removes all non-alphabetic characters, and converts it to lowercase.
    # The resulting string is stored in the 'word2' variable.

    # Reading the third word from the user input
    word3 = re.sub(r'[^a-zA-Z]', '', input()).lower()
    # This block of code reads a line from the user input, removes all non-alphabetic characters, and converts it to lowercase.
    # The resulting string is stored in the 'word3' variable.

    # Creating six permutations of the given words
    perm1 = word1 + word2 + word3
    perm2 = word1 + word3 + word2
    perm3 = word2 + word1 + word3
    perm4 = word2 + word3 + word1
    perm5 = word3 + word2 + word1
    perm6 = word3 + word1 + word2

    # Reading the number of students
    students = int(input())
    # This block of code reads an integer value from the user input.
    # The number of students is stored in the 'students' variable.

    # Looping through each student's test case
    for _ in range(students):
        # Reading a test case from the user input
        testCase = re.sub(r'[^a-zA-Z]', '', input()).lower()
        # This block of code reads a line from the user input, removes all non-alphabetic characters, and converts it to lowercase.
        # The resulting string is stored in the 'testCase' variable.

        # Checking if the test case matches any of the permutations
        if testCase in {perm1, perm2, perm3, perm4, perm5, perm6}:
            # Printing 'ACC' if the test case matches any of the permutations
            print("ACC")
        else:
            # Printing 'WA' if the test case doesn't match any of the permutations
            print("WA")

# Calling the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
