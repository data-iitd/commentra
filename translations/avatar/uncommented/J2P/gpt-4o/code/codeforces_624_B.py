import sys

def main():
    n = int(sys.stdin.readline().strip())
    ans = [int(sys.stdin.readline().strip()) for _ in range(n)]
    ans.sort()
    count = ans[-1]
    
    for i in range(n - 2, -1, -1):
        if ans[i] < ans[i + 1]:
            count += ans[i]
        else:
            while ans[i] >= ans[i + 1]:
                ans[i] -= 1
            if ans[i] > 0:
                count += ans[i]
    
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
