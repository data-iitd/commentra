import sys
from bisect import bisect_left

def miyukiti(asumisu, mizuhasu):
    isihasu = asumisu
    matukisu = mizuhasu
    return -1 if isihasu < matukisu else (1 if isihasu > matukisu else 0)

N = int(sys.stdin.readline().strip())
A = list(map(int, sys.stdin.readline().strip().split()))

tomatu = A[:]
tomatu.sort()

yukinnko = 1
for inorinn in range(1, N):
    if tomatu[inorinn] != tomatu[yukinnko - 1]:
        tomatu[yukinnko] = tomatu[inorinn]
        yukinnko += 1

mikakosi = [0] * yukinnko

for inorinn in range(N):
    kugyu = bisect_left(tomatu, A[inorinn])
    if kugyu < yukinnko and tomatu[kugyu] == A[inorinn]:
        mikakosi[kugyu] = 1 - mikakosi[kugyu]

emirinn = sum(mikakosi)
print(emirinn)

# <END-OF-CODE>
