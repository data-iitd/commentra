
#URL_HERE
#This is the main Python file for solving a problem. Replace URL_HERE with the URL of the problem statement.
#Disable the warning for the use of old-style file I/O functions like fscanf and fprintf which are deprecated in newer compilers.
import sys
import math
import string
import collections
import re
import itertools
import functools
import operator
import bisect
import random
import time
import heapq
import array
import os
import sys
import math
import string
import collections
import re
import itertools
import functools
import operator
import bisect
import random
import time
import heapq
import array

_fin = sys.stdin
_fout = sys.stdout
#define PI 3.141592653589793238462643383279502884197169399375105820974
#define ten5p1 100001
#define ten6p1 1000001
#define ten8p1 100000001
#define ten9p1 1000000001
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define rep(var,n) for(int var=0;var<n;++var)
#define repi(n) rep(i,n)
#define repj(n) rep(j,n)
#define repi1(n) for(int i=1;i<n;++i)
#define repj1(n) for(int j=1;j<n;++j)
#define _min(a,b) (a)<(b)?(a):(b)
#define _max(a,b) (a)>(b)?(a):(b)
#define zeroi(data,n) memset(data,0,sizeof(int)*n);
#define zeroll(data,n) memset(data,0,sizeof(long long)*n);
#define one(data,n) {for(int _ONEI=0;_ONEI<n;++_ONEI) data[_ONEI]=1;}
def readc(): return sys.stdin.read(1)
def readi(): return int(sys.stdin.readline())
def readll(): return int(sys.stdin.readline())
def repread(data, n): repi(n) data[i] = readi()
def repread(data, n): repi(n) data[i] = readll()
def reads(str, maxsize):
	for _ in range(maxsize):
		if (_fin.readline() == '\n'): break
	return sys.stdin.readline()

#define writec(var) sys.stdout.write(var)
#define writecsp(var) sys.stdout.write(var +'')
#define writecln(var) sys.stdout.write(var + '\n')
#define writei(var) sys.stdout.write(str(var))
#define writeisp(var) sys.stdout.write(str(var) +'')
#define writellsp(var) sys.stdout.write(str(var) +'')
#define writeiln(var) sys.stdout.write(str(var) + '\n')
#define writellln(var) sys.stdout.write(str(var) + '\n')
#define writeulln(var) sys.stdout.write(str(var) + '\n')
#define writefln(var) sys.stdout.write(str(var) + '\n')
#define writes(str) sys.stdout.write(str)
#define writesp() sys.stdout.write(' ')
#define writeln() sys.stdout.write('\n')
#define iseven(x) ((x&1)==0? 1:0)
#define RUN_LOCAL(testfilename) {_fin = open(testfilename, "r"); if(_fin==None) _fin=sys.stdin;}
#define swap(type,a, b) {type t=a;a=b;b=t;}
#define swapxor(a,b) {a^=b;b^=a;a^=b;}
#define sort(data,n) data.sort()
#define mod(a,b) b==0? 0 : a==0? 0 :(a>0? a%b : b + a % b)
def gcd(a, b): return b == 0 and a or gcd(b, a % b)

def reversei(data, n):
	k = n >> 1
	repi(k) {
		tmp = data[i]
		data[i] = data[n - i - 1]
		data[n - i - 1] = tmp
	}

def bsearch(val, data, n):
	if (data[0] > val): return -1
	if (data[n - 1] < val): return n
	l = 0
	r = n - 1
	for (; l < r;) {
		mid = (l + r + 1) >> 1
		if (data[mid] <= val): l = mid
		else r = mid - 1
	}
	if (data[r]!= val): r += 1
	return r

#define _Vec(type, name) \
class name: \
	def __init__(self, size): \
		self.data = [0] * size \
		self.size = size \
		self.n = 0 \
	def resize(self): \
		ns = self.size * 1.2f \
		self.data = self.data + [0] * (ns - self.size) \
		self.size = ns \
	def add(self, val): \
		if (self.n >= self.size): self.resize() \
		k = self.n \
		self.data[k] = val \
		self.n = k + 1 \
	def free(self): \
		del self.data
_Vec(int, Veci)
_Vec(long long, Vecll)
_Vec(char, Vecs)
#Define the vector data structures for handling dynamic arrays.

if __name__ == '__main__':
	RUN_LOCAL("dataabc155A.txt")
	#Open the input file for reading.
	a = readi()
	b = readi()
	#Read the two integers a and b from the input file.
	if (a < b):
		repi(b) writei(a)
		writeln()
		#If a is smaller than b, print a b times.
	else:
		repi(a) writei(b)
		writeln()
		#If b is smaller than a, print b a times.
	#