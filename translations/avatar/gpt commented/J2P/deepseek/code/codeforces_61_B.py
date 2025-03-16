import re

def main():
    # Read three words from the input, remove non-alphabetic characters, and convert them to lowercase
    word1 = re.sub('[^a-zA-Z]', '', input().lower())
    word2 = re.sub('[^a-zA-Z]', '', input().lower())
    word3 = re.sub('[^a-zA-Z]', '', input().lower())
    
    # Generate all possible permutations of the three words
    perm1 = word1 + word2 + word3
    perm2 = word1 + word3 + word2
    perm3 = word2 + word1 + word3
    perm4 = word2 + word3 + word1
    perm5 = word3 + word2 + word1
    perm6 = word3 + word1 + word2
    
    # Read the number of students (test cases)
    students = int(input())
    
    # Loop through each student's test case
    for _ in range(students):
        # Read the test case input, remove non-alphabetic characters, and convert to lowercase
        test_case = re.sub('[^a-zA-Z]', '', input().lower())
        
        # Check if the test case matches any of the generated permutations
        if test_case == perm1 or test_case == perm2 or \
           test_case == perm3 or test_case == perm4 or \
           test_case == perm5 or test_case == perm6:
            # If it matches, print "ACC" (Accepted)
            print("ACC")
        else:
            # If it doesn't match, print "WA" (Wrong Answer)
            print("WA")

if __name__ == "__main__":
    main()
