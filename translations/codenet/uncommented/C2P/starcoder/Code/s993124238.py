#include <stdio.h>
#include <math.h>

def main():
	n,d = map(int,raw_input().split())
	point = [[0 for i in range(d+1)] for j in range(n+1)]
	
	for i in range(1,n+1):
		for j in range(1,d+1):
			point[i][j] = int(raw_input())
	
	count = 0
	for i in range(1,n):
		for j in range(i+1,n+1):
			sum = 0
			for k in range(1,d+1):
				sum = sum + (point[i][k] - point[j][k])*(point[i][k] - point[j][k])
			kyori = sqrt(sum)
			if (ceil(kyori) == floor(kyori)):
				count = count + 1
	
	print count

main()

