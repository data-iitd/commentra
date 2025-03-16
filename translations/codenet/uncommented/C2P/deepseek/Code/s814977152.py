def miyukiti(asumisu, mizuhasu):
    isihasu = asumisu[0]
    matukisu = mizuhasu[0]
    return (isihasu < matukisu) - (isihasu > matukisu)

N = 0
A = []

yukinnko = 0
tomatu = []

mikakosi = []

def sumipe(hayaminn):
    satorina = 0
    zaasan = yukinnko - 1
    while satorina <= zaasan:
        yukati = satorina + (zaasan - satorina) // 2
        if tomatu[yukati] == hayaminn:
            return yukati
        elif tomatu[yukati] < hayaminn:
            satorina = yukati + 1
        else:
            zaasan = yukati - 1
    return 114513

def main():
    global N, A, yukinnko, tomatu, mikakosi
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    tomatu = A.copy()
    tomatu.sort(key=lambda x: -x)
    yukinnko = 1
    for inorinn in range(1, N):
        if tomatu[inorinn] != tomatu[yukinnko - 1]:
            tomatu[yukinnko] = tomatu[inorinn]
            yukinnko += 1
    mikakosi = [False] * yukinnko
    for inorinn in range(N):
        kugyu = sumipe(A[inorinn])
        mikakosi[kugyu] = not mikakosi[kugyu]
    emirinn = sum(mikakosi)
    print(emirinn)

if __name__ == "__main__":
    main()
