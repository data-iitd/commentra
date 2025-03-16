
import sys

def main():
    x = 0
    y = 0
    k = 0
    dx = 0
    dy = 0
    flag = True
    s = input()
    for i in range(len(s)):
        if s[i] == 'L':
            x -= 1
        elif s[i] == 'R':
            x += 1
        elif s[i] == 'U':
            y += 1
        elif s[i] == 'D':
            y -= 1
        if abs(x) > 1 or abs(y) > 1:
            flag = False
            break
    if flag:
        print("OK")
    else:
        print("BUG")

if __name__ == "__main__":
    main()

