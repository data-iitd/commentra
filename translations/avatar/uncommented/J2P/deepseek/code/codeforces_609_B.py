import sys

def main():
    n, m = map(int, sys.stdin.readline().split())
    arr = list(map(int, sys.stdin.readline().split()))
    gen = [0] * (m + 1)
    
    for num in arr:
        gen[num] += 1
    
    ans = 0
    for i in range(1, m + 1):
        for k in range(1, m + 1):
            if i != k:
                ans += gen[i] * gen[k]
    
    print(ans // 2)

if __name__ == "__main__":
    main()
