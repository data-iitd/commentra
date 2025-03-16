def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])
    a = list(map(int, data[1:n+1]))
    s = data[n+1]
    
    sum_b = sum(a[i] for i in range(len(s)) if s[i] == 'B')
    ans = sum_b
    sum1 = sum_b
    
    for i in range(len(s)):
        if s[i] == 'A':
            sum1 += a[i]
        else:
            sum1 -= a[i]
        ans = max(ans, sum1)
    
    sum1 = sum_b
    for i in range(len(s) - 1, -1, -1):
        if s[i] == 'A':
            sum1 += a[i]
        else:
            sum1 -= a[i]
        ans = max(ans, sum1)
    
    print(ans)

if __name__ == "__main__":
    main()
# <END-OF-CODE>
