def main():
    N = int(input())
    
    A = [int(input()) for _ in range(N)]
    sum_A = sum(A)
    wa = sum(range(1, N + 1))
    
    if sum_A % wa != 0:
        ans = 0
    else:
        shou = sum_A // wa
        sa = [(A[(i + 1) % N] - A[i] - shou) for i in range(N)]
        
        ans = 1
        for i in range(N - 1):
            if sa[i] <= 0 and sa[i] % N == 0:
                ans = 1
            else:
                ans = 0
                break
    
    if ans:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
