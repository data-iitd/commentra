
import sys

def miyukiti(a, b):
	return a < b and -1 or 1

def main():
	N = int(sys.stdin.readline())
	A = [int(sys.stdin.readline()) for i in range(N)]
	tomatu = sorted(A)
	yukinnko = 1
	for i in range(1, N):
		if tomatu[i]!= tomatu[yukinnko - 1]:
			tomatu[yukinnko] = tomatu[i]
			yukinnko += 1
	mikakosi = [False] * yukinnko
	for i in range(N):
		kugyu = sumipe(A[i])
		mikakosi[kugyu] = not mikakosi[kugyu]
	emirinn = 0
	for i in range(yukinnko):
		if mikakosi[i]: emirinn += 1
	print emirinn

def sumipe(hayaminn):
	satorina = 0
	zaasan = yukinnko - 1
	while satorina <= zaasan:
		yukati = satorina + (zaasan - satorina) / 2
		if tomatu[yukati] == hayaminn: return yukati
		elif tomatu[yukati] < hayaminn: satorina = yukati + 1
		else: zaasan = yukati - 1
	return 114513

main()

