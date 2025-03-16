import sys

def main():
    n, m = map(int, sys.stdin.readline().split())
    ans = []
    for _ in range(n):
        s = sys.stdin.readline().strip()
        temp = ""
        for j in range(m):
            if s[j] == '-':
                temp += "-"
            else:
                if (i + j) % 2 == 1:
                    temp += "W"
                else:
                    temp += "B"
        ans.append(temp)
    for i in range(n):
        print(ans[i])

if __name__ == "__main__":
    main()
