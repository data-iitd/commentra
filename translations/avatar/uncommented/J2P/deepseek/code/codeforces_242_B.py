INF = int(1e9) + 5

def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    left = INF
    right = 0
    
    for i in range(n):
        left = min(left, a[i])
        right = max(right, b[i])
    
    for i in range(n):
        if left == a[i] and right == b[i]:
            print(i + 1)
            return
    
    print(-1)

if __name__ == "__main__":
    main()
