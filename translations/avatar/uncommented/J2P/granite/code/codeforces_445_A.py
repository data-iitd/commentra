
import sys

def main():
    n, m = map(int, sys.stdin.readline().split())
    ans = []
    for i in range(n):
        s = sys.stdin.readline().strip()
        t = ""
        for j in range(m):
            if s[j] == "-":
                t += "-"
            else:
                if (i + j) % 2 == 1:
                    t += "W"
                else:
                    t += "B"
        ans.append(t)
    for i in range(n):
        print(ans[i])

if __name__ == "__main__":
    main()

