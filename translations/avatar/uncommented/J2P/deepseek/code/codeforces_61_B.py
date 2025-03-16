import re

def main():
    word1 = re.sub(r'[^a-zA-Z]', '', input().lower())
    word2 = re.sub(r'[^a-zA-Z]', '', input().lower())
    word3 = re.sub(r'[^a-zA-Z]', '', input().lower())
    
    perm1 = word1 + word2 + word3
    perm2 = word1 + word3 + word2
    perm3 = word2 + word1 + word3
    perm4 = word2 + word3 + word1
    perm5 = word3 + word2 + word1
    perm6 = word3 + word1 + word2
    
    students = int(input())
    for _ in range(students):
        test_case = re.sub(r'[^a-zA-Z]', '', input().lower())
        if test_case in [perm1, perm2, perm3, perm4, perm5, perm6]:
            print("ACC")
        else:
            print("WA")

if __name__ == "__main__":
    main()
