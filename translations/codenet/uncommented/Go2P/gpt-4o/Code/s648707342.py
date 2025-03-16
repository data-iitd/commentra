import sys

def scan_int():
    return int(sys.stdin.readline().strip())

def main():
    n = scan_int()
    arms = []
    
    for _ in range(n):
        x, l = map(int, sys.stdin.readline().strip().split())
        arms.append((x - l, x + l))
    
    arms.sort(key=lambda arm: arm[1])
    
    ans = 1
    r = arms[0][1]
    
    for i in range(1, n):
        if arms[i][0] >= r:
            ans += 1
            r = arms[i][1]
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
