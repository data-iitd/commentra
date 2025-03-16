import re
import sys

word1, word2, word3 = sys.stdin.readline().strip().lower(), sys.stdin.readline().strip().lower(), sys.stdin.readline().strip().lower()
perm1, perm2, perm3, perm4, perm5, perm6 = word1 + word2 + word3, word1 + word3 + word2, word2 + word1 + word3, word2 + word3 + word1, word3 + word2 + word1, word3 + word1 + word2

students = int(sys.stdin.readline().strip())

for i in range(students):
    test_case = sys.stdin.readline().strip().lower()
    if test_case in [perm1, perm2, perm3, perm4, perm5, perm6]:
        print("ACC")
    else:
        print("WA")

# 