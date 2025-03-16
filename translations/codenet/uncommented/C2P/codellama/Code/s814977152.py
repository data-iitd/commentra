#include <stdio.h>
#include <stdlib.h>

def miyukiti(asumisu, mizuhasu):
	isihasu = asumisu
	matukisu = mizuhasu
	if isihasu < matukisu:
		return -1
	elif isihasu > matukisu:
		return 1
	else:
		return 0

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

if __name__ == "__main__":
	inorinn = 0
	emirinn = 0
	N = int(input())
	for inorinn in range(N):
		A.append(int(input()))
		tomatu.append(A[inorinn])
	tomatu.sort(key=lambda x: x, reverse=False)
	yukinnko = 1
	for inorinn in range(1, N):
		if tomatu[inorinn] != tomatu[yukinnko - 1]:
			tomatu[yukinnko] = tomatu[inorinn]
			yukinnko += 1
	for inorinn in range(N):
		kugyu = sumipe(A[inorinn])
		mikakosi[kugyu] = not mikakosi[kugyu]
	for inorinn in range(yukinnko):
		if mikakosi[inorinn]:
			emirinn += 1
	print(emirinn)

