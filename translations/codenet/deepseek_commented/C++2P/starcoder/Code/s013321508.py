
# <START-OF-CODE>

N, M = map(int, input().split())
L = list(map(int, input().split()))
L.sort()

for i in range(M):
    max_L = L[-1]
    if max_L == 0:
        break
    max_L //= 2
    itr = L.index(max_L)
    L.insert(itr, max_L)
    L.pop()

print(sum(L))

# 