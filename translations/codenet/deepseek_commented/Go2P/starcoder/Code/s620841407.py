import sys
import io
import os
import math
import collections

# <START-OF-CODE>

MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = 1 << 60
INF_BIT60 = 1 << 60
INF_INT32 = 1 << 30
INF_BIT30 = 1 << 30
NIL = -1

WHITE = 0
GRAY = 1
BLACK = 2

# General purpose
def init():
	global ReadString, stdout
	ReadString = lambda: sys.stdin.readline()
	stdout = io.BytesIO()

def ReadInt():
	return int(input())

def ReadInt2():
	return int(input()), int(input())

def ReadInt3():
	return int(input()), int(input()), int(input())

def ReadInt4():
	return int(input()), int(input()), int(input()), int(input())

def ReadInt64():
	return int(input())

def ReadInt64_2():
	return int(input()), int(input())

def ReadInt64_3():
	return int(input()), int(input()), int(input())

def ReadInt64_4():
	return int(input()), int(input()), int(input()), int(input())

def ReadFloat():
	return float(input())

def ReadFloat2():
	return float(input()), float(input())

def ReadFloat3():
	return float(input()), float(input()), float(input())

def ReadFloat4():
	return float(input()), float(input()), float(input()), float(input())

def ReadFloat64():
	return float(input())

def ReadFloat64_2():
	return float(input()), float(input())

def ReadFloat64_3():
	return float(input()), float(input()), float(input())

def ReadFloat64_4():
	return float(input()), float(input()), float(input()), float(input())

def ReadRuneSlice():
	return list(map(ord, input()))

def ReadStr():
	return input()

def ReadStr2():
	return input(), input()

def ReadStr3():
	return input(), input(), input()

def ReadStr4():
	return input(), input(), input(), input()

def ReadStr5():
	return input(), input(), input(), input(), input()

def ReadStr6():
	return input(), input(), input(), input(), input(), input()

def PrintIntsLine(A):
	return''.join(map(str, A))

def PrintIntsLine2(A, B):
	return '%s %s' % (A, B)

def PrintIntsLine3(A, B, C):
	return '%s %s %s' % (A, B, C)

def PrintIntsLine4(A, B, C, D):
	return '%s %s %s %s' % (A, B, C, D)

def PrintIntsLine5(A, B, C, D, E):
	return '%s %s %s %s %s' % (A, B, C, D, E)

def PrintIntsLine6(A, B, C, D, E, F):
	return '%s %s %s %s %s %s' % (A, B, C, D, E, F)

def PrintStrsLine(A):
	return''.join(A)

def PrintStrsLine2(A, B):
	return '%s %s' % (A, B)

def PrintStrsLine3(A, B, C):
	return '%s %s %s' % (A, B, C)

def PrintStrsLine4(A, B, C, D):
	return '%s %s %s %s' % (A, B, C, D)

def PrintStrsLine5(A, B, C, D, E):
	return '%s %s %s %s %s' % (A, B, C, D, E)

def PrintStrsLine6(A, B, C, D, E, F):
	return '%s %s %s %s %s %s' % (A, B, C, D, E, F)

def PrintFloatsLine(A):
	return''.join(map(str, A))

def PrintFloatsLine2(A, B):
	return '%s %s' % (A, B)

def PrintFloatsLine3(A, B, C):
	return '%s %s %s' % (A, B, C)

def PrintFloatsLine4(A, B, C, D):
	return '%s %s %s %s' % (A, B, C, D)

def PrintFloatsLine5(A, B, C, D, E):
	return '%s %s %s %s %s' % (A, B, C, D, E)

def PrintFloatsLine6(A, B, C, D, E, F):
	return '%s %s %s %s %s %s' % (A, B, C, D, E, F)

def ZeroPadding(n, digitsNum):
	sn = str(n)

	residualLength = digitsNum - len(sn)
	if residualLength <= 0:
		return sn

	zeros = '0' * residualLength
	return zeros + sn

def IsPrime(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n == 2 or n == 3:
		return True

	if n < 2 or n % 2 == 0:
		return False

	if n < 9:
		return True

	if n % 3 == 0:
		return False

	r = int(n ** 0.5)
	f = 5

	while f <= r:
		if n % f == 0:
			return False
		if n % (f + 2) == 0:
			return False
		f += 6

	return True

def IsPrimeList(n):
	if n