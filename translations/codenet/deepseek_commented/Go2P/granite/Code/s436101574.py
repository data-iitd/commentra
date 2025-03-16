
import sys

def main():
    s = input()
    t = input()

    ans = []
    for i in range(len(s) - len(t) + 1):
        f = True
        ss = list(s)
        for j in range(len(t)):
            if s[i+j]!= t[j] and s[i+j]!= '?':
                f = False
                break
            else:
                ss[i+j] = t[j]
        if f:
            ans.append(''.join(ss).replace('?', 'a'))

    if len(ans) == 0:
        print("UNRESTORABLE")
    else:
        print(min(ans))

if __name__ == "__main__":
    main()

