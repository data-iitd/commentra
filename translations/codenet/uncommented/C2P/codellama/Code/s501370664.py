#include <stdio.h>
#include <stdlib.h>

flag = [0] * 50001

def prime(num):
	for i in range(2,int(num**0.5)+1):
		if flag[i] == 0:
			for j in range(i*i,num+1,i):
				flag[j] = 1

prime(50000)

while True:
	n = int(input())
	if n == 0:
		break
	i = 2
	cnt = 0
	while i*2 <= n:
		if flag[i] == 0 and flag[n-i] == 0:
			cnt += 1
		i += 1
	print(cnt)

