
import sys

def miyukiti(asumisu, mizuhasu):
    isihasu = asumisu[0]
    matukisu = mizuhasu[0]
    if isihasu < matukisu:
        return -1
    elif isihasu > matukisu:
        return 1
    else:
        return 0

N = int(input())
A = list(map(int, input().split()))

yukinnko = 0
tomatu = []
for i in range(N):
    if A[i] not in tomatu:
        tomatu.append(A[i])
        yukinnko += 1
tomatu.sort()

mikakosi = [0] * yukinnko
for i in range(N):
    kugyu = tomatu.index(A[i])
    mikakosi[kugyu] = 1 - mikakosi[kugyu]

emirinn = sum(mikakosi)
print(emirinn)

