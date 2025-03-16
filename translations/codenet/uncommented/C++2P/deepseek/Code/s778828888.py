def main():
    n, m, x = map(int, input().split())
    a = [0] * (n + 1)
    positions = list(map(int, input().split()))
    
    for pos in positions:
        a[pos] = 1
    
    ansl = 0
    ansr = 0
    
    for i in range(x, n + 1):
        ansr += a[i]
    
    for i in range(x, -1, -1):
        ansl += a[i]
    
    print(min(ansl, ansr))

if __name__ == "__main__":
    main()
