
import sys

# Read three words from the input, remove non-alphabetic characters, and convert them to lowercase
word1 = input().strip().lower()
word2 = input().strip().lower()
word3 = input().strip().lower()

# Generate all possible permutations of the three words
permutations = [word1 + word2 + word3, word1 + word3 + word2, word2 + word1 + word3, word2 + word3 + word1, word3 + word2 + word1, word3 + word1 + word2]

# Read the number of students (test cases)
students = int(input())

# Loop through each student's test case
for i in range(students):
    # Read the test case input, remove non-alphabetic characters, and convert to lowercase
    testCase = input().strip().lower()

    # Check if the test case matches any of the generated permutations
    if testCase in permutations:
        # If it matches, print "ACC" (Accepted)
        print("ACC")
    else:
        # If it doesn't match, print "WA" (Wrong Answer)
        print("WA")

