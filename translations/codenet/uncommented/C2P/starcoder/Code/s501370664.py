
#include <stdio.h>
#include <stdlib.h>

def prime(num):
	flag = [0]*(num+1)
	for i in range(2,num+1):
		if flag[i] == 0:
			for j in range(2,num+1):
				if i*j <= num:
					flag[i*j] = 1

def main():
	while True:
		n = int(input())
		if n == 0:
			break
		prime(50000)
		i = 2
		cnt = 0
		while i*2 <= n:
			if not flag[i] and not flag[n-i]:
				cnt += 1
			i += 1
		print(cnt)

main()

