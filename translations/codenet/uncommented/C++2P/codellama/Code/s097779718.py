#include <iostream>
using namespace std;

def Euclid(x, y):
	tmp = 0

	if x < y:
		tmp = x
		x = y
		y = tmp

	if not x%y:
		return y
	return Euclid(y, x%y)

A = int(input())
B = int(input())

print((A*B) // Euclid(A, B))

