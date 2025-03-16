
#include<stdio.h>

def main():
	x = [0]*10000
	i = 0
	x[i] = int(input())
	while(x[i]!= 0):
		i = i + 1
		x[i] = int(input())
	for j in range(0,i):
		print("Case %d: %d" %(j+1,x[j]))

if __name__ == "__main__":
	main()

