def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    x = int(data[1])
    A = list(map(int, data[2:n+2]))

    A.sort()

    ans = 0
    i, j = 0, 0
    while j < len(A):
        if x >= A[i]:
            ans += 1
            x -= A[i]
            i += 1
        else:
            j += 1

    if x > 0 and len(A) == ans:
        ans -= 1

    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
