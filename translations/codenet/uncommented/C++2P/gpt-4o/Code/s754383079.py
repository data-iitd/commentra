def main():
    a = input().strip()
    b = input().strip()
    
    n = len(a)
    m = len(b)
    ans = float('inf')
    
    for i in range(n - m + 1):
        sum_diff = 0
        for j in range(m):
            if a[i + j] != b[j]:
                sum_diff += 1
        ans = min(ans, sum_diff)
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
