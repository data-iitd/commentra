import sys
import math

def main():
    n = int(sys.stdin.readline())
    ans = []
    for i in range(n):
        ans.append(int(sys.stdin.readline()))
    ans.sort()
    count = ans[n-1]
    for i in range(n-2, -1, -1):
        if ans[i] < ans[i+1]:
            count += ans[i]
        else:
            while ans[i] >= ans[i+1]:
                ans[i] -= 1
            if ans[i] > 0:
                count += ans[i]
    print(count)

if __name__ == "__main__":
    main()

