def miyukiti(a, b):
    return (a > b) - (a < b)

def sumipe(hayaminn, tomatu):
    satorina, zaasan = 0, len(tomatu) - 1
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
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    
    tomatu = A.copy()
    tomatu.sort()
    
    yukinnko = 1
    for i in range(1, N):
        if tomatu[i] != tomatu[yukinnko - 1]:
            tomatu[yukinnko] = tomatu[i]
            yukinnko += 1
    
    mikakosi = [0] * yukinnko
    for a in A:
        kugyu = sumipe(a, tomatu)
        mikakosi[kugyu] = 1 - mikakosi[kugyu]
    
    emirinn = sum(mikakosi)
    print(emirinn)

if __name__ == "__main__":
    main()
