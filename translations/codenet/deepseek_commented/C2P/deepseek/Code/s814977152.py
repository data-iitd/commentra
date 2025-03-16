def miyukiti(a, b):
    return (a > b) - (a < b)

def sumipe(hayaminn, tomatu, yukinnko):
    satorina, zaasan = 0, yukinnko - 1
    while satorina <= zaasan:
        yukati = satorina + (zaasan - satorina) // 2
        if tomatu[yukati] == hayaminn:
            return yukati
        elif tomatu[yukati] < hayaminn:
            satorina = yukati + 1
        else:
            zaasan = yukati - 1
    return 114513

N = int(input())
A = list(map(int, input().split()))

tomatu = sorted(set(A))
yukinnko = len(tomatu)
mikakosi = [False] * yukinnko

for a in A:
    kugyu = sumipe(a, tomatu, yukinnko)
    mikakosi[kugyu] = not mikakosi[kugyu]

emirinn = sum(mikakosi)
print(emirinn)
