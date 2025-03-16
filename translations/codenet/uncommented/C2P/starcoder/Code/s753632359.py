# <START-OF-CODE>

N, D = map(int, input().split())

ans = N // (D*2+1)
rem = N % (D*2+1)

if rem!= 0:
    ans += 1

print(ans)

# 