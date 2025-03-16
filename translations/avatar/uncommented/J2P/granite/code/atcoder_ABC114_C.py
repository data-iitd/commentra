
import sys

def main():
    N = int(input())
    i = 357
    c = 0
    while i <= N:
        s = str(i)
        if "3" in s and "5" in s and "7" in s:
            c += 1
        s = s[::-1]
        f = False
        for j in range(len(s)):
            a = s[j]
            if f:
                s = s[:j] + a + s[j+1:]
            else:
                if a == "3":
                    s = s[:j] + "5" + s[j+1:]
                    f = True
                elif a == "5":
                    s = s[:j] + "7" + s[j+1:]
                    f = True
                else:
                    s = s[:j] + "3" + s[j+1:]
        if not f:
            s = "3" + s
        i = int(s[::-1])
    print(c)

if __name__ == "__main__":
    main()

