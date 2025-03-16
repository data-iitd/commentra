def miyukiti(a, b):
    return a - b

def sumipe(hayaminn, tomatu):
    satorina = 0
    zaasan = len(tomatu) - 1
    while satorina <= zaasan:
        yukati = satorina + (zaasan - satorina) // 2
        if tomatu[yukati] == hayaminn:
            return yukati
        elif tomatu[yukati] < hayaminn:
            satorina = yukati + 1
        else:
            zaasan = yukati - 1
    return len(tomatu)

def main():
    N = int(input())
    A = list(map(int, input().split()))
    
    tomatu = A.copy()
    tomatu.sort()
    
    yukinnko = 1
    for i in range(1, N):
        if tomatu[i] != tomatu[yukinnko - 1]:
            tomatu[yukinnko] = tomatu[i]
            yukinnko += 1
    
    mikakosi = [0] * N
    
    for a in A:
        kugyu = sumipe(a, tomatu)
        mikakosi[kugyu] = 1
    
    emirinn = sum(mikakosi[:yukinnko])
    
    print(emirinn)

if __name__ == "__main__":
    main()
