
import re

def main():
    # Read and process the three input words
    word1 = re.sub(r'[^a-zA-Z]', '', input().lower())
    word2 = re.sub(r'[^a-zA-Z]', '', input().lower())
    word3 = re.sub(r'[^a-zA-Z]', '', input().lower())

    # Generate all possible permutations of the three words
    perm1 = word1 + word2 + word3
    perm2 = word1 + word3 + word2
    perm3 = word2 + word1 + word3
    perm4 = word2 + word3 + word1
    perm5 = word3 + word2 + word1
    perm6 = word3 + word1 + word2

    # Read the number of test cases
    students = int(input())
    input()

    # Process each test case
    for i in range(students):
        testCase = re.sub(r'[^a-zA-Z]', '', input().lower())
        # Check if the test case matches any of the generated permutations
        if testCase == perm1 or testCase == perm2 or testCase == perm3 or testCase == perm4 or testCase == perm5 or testCase == perm6:
            print("ACC")
        else:
            print("WA")

if __name__ == '__main__':
    main()

