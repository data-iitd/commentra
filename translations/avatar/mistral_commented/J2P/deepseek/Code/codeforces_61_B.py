# Importing necessary packages
import re

# Reading the first word from the user input
word1 = re.sub(r'[^a-zA-Z]', '', input().lower())

# Reading the second word from the user input
word2 = re.sub(r'[^a-zA-Z]', '', input().lower())

# Reading the third word from the user input
word3 = re.sub(r'[^a-zA-Z]', '', input().lower())

# Creating six permutations of the given words
perm1 = word1 + word2 + word3
perm2 = word1 + word3 + word2
perm3 = word2 + word1 + word3
perm4 = word2 + word3 + word1
perm5 = word3 + word2 + word1
perm6 = word3 + word1 + word2

# Reading the number of students
students = int(input())

# Looping through each student's test case
for _ in range(students):
    # Reading a test case from the user input
    test_case = re.sub(r'[^a-zA-Z]', '', input().lower())

    # Checking if the test case matches any of the permutations
    if test_case == perm1 or test_case == perm2 or test_case == perm3 or test_case == perm4 or test_case == perm5 or test_case == perm6:
        # Printing 'ACC' if the test case matches any of the permutations
        print("ACC")
    else:
        # Printing 'WA' if the test case doesn't match any of the permutations
        print("WA")
