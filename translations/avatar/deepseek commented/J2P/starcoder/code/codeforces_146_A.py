
import sys

def main():
    n = int(input())
    s = input()
    x = 0
    y = 0
    for i in range(n):
        if s[i]!= '4' and s[i]!= '7':
            x += int(s[i])
        else:
            y += int(s[i])
    if x == y:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()

