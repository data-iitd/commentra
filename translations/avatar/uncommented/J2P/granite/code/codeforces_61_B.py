
import sys

def main():
    word1 = input().replace(r'[^a-zA-Z]', '').lower()
    word2 = input().replace(r'[^a-zA-Z]', '').lower()
    word3 = input().replace(r'[^a-zA-Z]', '').lower()
    perm1 = word1 + word2 + word3
    perm2 = word1 + word3 + word2
    perm3 = word2 + word1 + word3
    perm4 = word2 + word3 + word1
    perm5 = word3 + word2 + word1
    perm6 = word3 + word1 + word2
    students = int(input())
    for i in range(students):
        testCase = input().replace(r'[^a-zA-Z]', '').lower()
        if testCase == perm1 or testCase == perm2 or testCase == perm3 or testCase == perm4 or testCase == perm5 or testCase == perm6:
            print("ACC")
        else:
            print("WA")

if __name__ == "__main__":
    main()

