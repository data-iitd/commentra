
import sys

def main():
    N = int(input())
    M = int(input())
    H = [int(x) for x in input().split()]
    ans = [True for i in range(N)]
    for i in range(M):
        temp1, temp2 = [int(x) for x in input().split()]
        if H[temp1-1] < H[temp2-1]:
            ans[temp1-1] = False
        elif H[temp1-1] > H[temp2-1]:
            ans[temp2-1] = False
        else:
            ans[temp1-1] = False
            ans[temp2-1] = False
    ans2 = 0
    for i in range(N):
        if ans[i]:
            ans2 += 1
    print(ans2)

if __name__ == "__main__":
    main()

