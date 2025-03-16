
# <START-OF-CODE>
import sys

def main():
    word1 = sys.stdin.readline().strip().lower()
    word2 = sys.stdin.readline().strip().lower()
    word3 = sys.stdin.readline().strip().lower()
    perm1 = word1 + word2 + word3
    perm2 = word1 + word3 + word2
    perm3 = word2 + word1 + word3
    perm4 = word2 + word3 + word1
    perm5 = word3 + word2 + word1
    perm6 = word3 + word1 + word2
    students = int(sys.stdin.readline().strip())
    for i in range(students):
        testCase = sys.stdin.readline().strip().lower()
        if testCase == perm1 or testCase == perm2 or testCase == perm3 or testCase == perm4 or testCase == perm5 or testCase == perm6:
            print("ACC")
        else:
            print("WA")

if __name__ == "__main__":
    main()
# 