#include<stdio.h>
def swap(a , b):
	tmp = a
	a = b
	b = tmp

while(1):
	a , b = input().split()
	if a == '0' and b == '0': break
	if int(b) < int(a): swap(a , b)
	print(a , b)

