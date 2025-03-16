import sys

def main():
    n = int(input().strip())
    words = {}
    for i in range(n):
        words[i] = input().strip()
    
    ans = True
    past = {}
    next_char = ""
    
    for i in range(n):
        if words[i] in past.values():
            ans = False
            break
        past[i] = words[i]
        if i != 0:
            if next_char != words[i][0]:
                ans = False
                break
        next_char = words[i][-1]
    
    if ans:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
