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

    # Process each test case
    for _ in range(students):
        test_case = re.sub(r'[^a-zA-Z]', '', input().lower())
        # Check if the test case matches any of the generated permutations
        if test_case == perm1 or test_case == perm2 or test_case == perm3 or \
           test_case == perm4 or test_case == perm5 or test_case == perm6:
            print("ACC")  # Print "ACC" if a match is found
        else:
            print("WA")  # Print "WA" if no match is found

if __name__ == "__main__":
    main()
