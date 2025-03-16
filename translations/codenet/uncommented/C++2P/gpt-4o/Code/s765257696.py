def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    p = list(map(int, data[1:n+1]))

    ans = 0
    for i in range(n - 2):
        if p[i] > p[i + 1] and p[i + 1] > p[i + 2]:
            ans += 1
        if p[i] < p[i + 1] and p[i + 1] < p[i + 2]:
            ans += 1

    print(ans)

if __name__ == "__main__":
    main()
# <END-OF-CODE>
