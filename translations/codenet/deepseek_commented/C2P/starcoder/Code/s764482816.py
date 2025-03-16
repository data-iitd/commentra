#include<stdio.h>

def main():
	io = [0,0,0,0,0]
	for i in range(5):
		io[i] = int(input())
	for i in range(5):
		max = io[i]
		max_j = i
		for j in range(i+1,5):
			if max < io[j]:
				max = io[j]
				max_j = j
		buf = io[i]
		io[i] = io[max_j]
		io[max_j] = buf
		i<4?print(io[i],end=" "):print(io[i])

main()

