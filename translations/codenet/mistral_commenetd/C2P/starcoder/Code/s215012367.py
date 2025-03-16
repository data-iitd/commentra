#include<stdio.h>

def main():
	a, b = map(int, input().split())
	s = (a*b) - (a + b) + 1
	print(s)

if __name__ == '__main__':
	main()

