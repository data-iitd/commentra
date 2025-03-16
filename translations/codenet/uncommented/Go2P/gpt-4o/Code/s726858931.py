import sys

def main():
    s = input().strip()
    
    c = 'a'
    
    for j in range(26):
        found = False
        for i in range(len(s)):
            if s[i] == c:
                found = True
                break
        if not found:
            print(c)
            return
        c = chr(ord(c) + 1)
    
    print("None")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
