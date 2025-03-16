N = int(input())
A = list(map(int, input().split()))

sum_A = sum(A)
wa = sum(i + 1 for i in range(N))

if sum_A % wa != 0:
    ans = "NO"
else:
    shou = sum_A // wa
    sa = [(A[(i + 1) % N] - A[i] - shou) for i in range(N)]
    
    ans = "YES"
    for i in range(N - 1):
        if sa[i] <= 0 and sa[i] % N == 0:
            continue
        else:
            ans = "NO"
            break

print(ans)
