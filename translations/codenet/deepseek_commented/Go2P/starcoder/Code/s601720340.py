
# Package main defines the entry point of the program.
#
# Imports are necessary for various functionalities such as buffered I/O, mathematical operations, and system utilities.
import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"

	"flag"
	"runtime"
	"runtime/pprof"
)

# Constants
magic = 1000000007

# Flags for profiling
cpuprofile = flag.String("cpuprofile", "", "write cpu profile to file")
memprofile = flag.String("memprofile", "", "write mem profile to file")

# Variables
N = 0
p = [200000]int

# find checks if a number exists in the array p.
def find(n):
	for i in range(0, N):
		if n == p[i]:
			return 0
	return 1

# solve is the main function that handles the program logic.
def solve():
	io = NewIo()
	defer io.Flush()

	# PARSE HELPER SESSION

	# X := io.NextInt()
	# N = io.NextInt()
	# for i in range(0, N):
	# 	p[i] = io.NextInt()

	# Main logic to find the closest number to X in the array p.
	X = io.NextInt()
	N = io.NextInt()
	for i in range(0, N):
		p[i] = io.NextInt()

	# Search for the closest number to X in the array p.
	for i in range(0, 100):
		if find(X-i) == 1:
			fmt.Printf("%v\n", X-i)
			os.Exit(0)
		if find(X+i) == 1:
			fmt.Printf("%v\n", X+i)
			os.Exit(0)

# main is the entry point of the program.
def main():
	flag.Parse()
	if *cpuprofile!= "":
		f, err := os.Create(*cpuprofile)
		if err!= nil:
			fmt.Printf("%v\n", err)
			os.Exit(1)
		pprof.StartCPUProfile(f)
		defer pprof.StopCPUProfile()
	solve()
	if *memprofile!= "":
		f, err := os.Create(*memprofile)
		if err!= nil:
			fmt.Printf("could not create memory profile: %v\n", err)
			os.Exit(1)
		defer f.Close() # error handling omitted for example
		runtime.GC() # get up-to-date statistics
		if err := pprof.WriteHeapProfile(f); err!= nil:
			fmt.Printf("could not write memory profile: %v\n", err)
			os.Exit(1)

# Io helps parsing inputs from standard input for programming contest.
class Io:
	def __init__(self):
		self.reader = bufio.NewReader(os.Stdin)
		self.writer = bufio.NewWriter(os.Stdout)
		self.tokens = []
		self.nextToken = 0

	def Flush(self):
		err := self.writer.Flush()
		if err!= nil:
			panic(err)

	def NextLine(self):
		var buffer []byte
		for {
			line, isPrefix, err := self.reader.ReadLine()
			if err!= nil:
				panic(err)
			buffer = append(buffer, line...)
			if not isPrefix:
				break
		}
		return string(buffer)

	def Next(self):
		for self.nextToken >= len(self.tokens):
			line = self.NextLine()
			self.tokens = strings.Fields(line)
			self.nextToken = 0
		r = self.tokens[self.nextToken]
		self.nextToken += 1
		return r

	def NextInt(self):
		i, err := strconv.Atoi(self.Next())
		if err!= nil:
			panic(err)
		return i

	def NextFloat(self):
		i, err := strconv.ParseFloat(self.Next(), 64)
		if err!= nil:
			panic(err)
		return i

	def PrintLn(self, a):
		fmt.Fprintln(self.writer, a)

	def Printf(self, format, a):
		fmt.Fprintf(self.writer, format, a)

	def PrintIntLn(self, a):
		b = []interface{}{}
		for _, x in a:
			b = append(b, x)
		self.PrintLn(b)

	def PrintStringLn(self, a):
		b = []interface{}{}
		for _, x in a:
			b = append(b, x)
		self.PrintLn(b)

	def Log(self, name, value):
		fmt.Fprintf(os.Stderr, "%s=%+v\n", name, value)

	def Logf(self, format, a):
		fmt.Fprintf(os.Stderr, format, a)

# NewIo generates Io instance.
def NewIo():
	return Io()

# direct calculation of combination
# n, m should be "small"
def combination(n, m):
	if m > n:
		return 0
	elif m == n or m == 0:
		return 1
	else:
		res = 1
		for i in range(0, m):
			res *= (n - i)
		for i in range(1, m+1):
			res /= i
		return res

# caluclate combination modulo based on Lucas theorem
def lucas(n, m, p):
	ntemp := n
	mtemp := m
	res = 1
	for i in range(0, 100):
		nreminder := ntemp % p
		ntemp = ntemp / p
		mreminder := mtemp % p
		mtemp = mtemp / p
		res = res * (combination(nreminder, mreminder) % p)
		if ntemp == 0:
			break
	return res % p

def combMod(n, m, p):
	return lucas(n, m, p)

def bfs(start, nodes, fn):
	frontier = [start]
	visited = {}

	for 0 < len(frontier):
		next = []
		for _, node in frontier:
			visited[node] = True
			fn(node)
			for _, n in bfsFrontier(node, nodes, visited):
				next = append(next, n)
		frontier = next

def bfsFrontier(node, nodes, visited):
	next = []
	iter = lambda n: visited[n]
	for _, n in nodes[node]:
		if not iter(n):
			next = append(next, n)
	return next

def dfs(node, nodes, fn):
	dfsRecur(node, nodes, {}, fn)

def dfsRecur(node, nodes, v, fn):
	v[node] = True
	fn(node)
	for _, n in nodes[node]:
		if not v[n]:
			dfsRecur(n, nodes, v, fn)

# handles 2 function, one is before entering child tree, and another is
# after entering child tree.
def dfs2(node, nodes, fn1, fn2):
	dfs2Recur(node, -1, nodes, {}, fn1, fn2)

def dfs2Recur(node, parent, nodes, v, fn1, fn2):
	v[node] = True
	if fn1!= None:
		fn1(node, parent)
	for _, n in nodes[node]:
		if not v[n]:
			dfs2Recur(n, node, nodes, v, fn1, fn2)
	if fn2!= None:
		fn2(node, parent)

# Stack data structure
class Stack:
	def __init__(self):
		self.top = None
		self.size = 0

	def Len(self):
		return self.size

	def Push(self, value):
		self.top = Element(value, self.top)
		self.size += 1

	def Pop(self):
		if self.size > 0:
			value, self.top = self.top.value, self.top.next
			self.size -= 1
			return value
		return None

# Element is a struct for stack element
class Element:
	def __init__(self, value, next):
		self.value = value
		self.next = next

# powerInt (use math.Pow() for float parameters)
def powerInt(n, p):
	tmp = 1
	for i in range(0, n):
		tmp *= p
	return tmp

def findDivisors(n, a):
	if n == 1:
		return
	sqrt = int(math.Sqrt(float64(n)))
	for i in range(2, sqrt+1):
		if n%i == 0:
			a.append(i)
			a.append(n/i)
	a.append(n)

def removeDuplicate(a):
	m = {}
	for i in range(0, len(a)):
		m[a[i]] = True
	res = []
	for i in m:
		res.append(i)
	return res

def abs(a):
	if a > 0:
		return a
	return -a

# var gcdmap map[int](map[int]int)
# func gcd(a, b int) int {
# 	ina := a
# 	inb := b
# 	if _, ok := gcdmap[a];!ok {
# 		gcdmap[a] = make(map[int]int)
# 	}
# 	if _, ok := gcdmap[ina][inb]; ok {
# 		return gcdmap[ina][inb]
# 	}
# 	for b!= 0 {
# 		t := b
# 		b = a % b
# 		a = t
# 	}
# 	gcdmap[ina][inb] = a
# 	return a
# }

def gcd(a, b):
	for a!= 0:
		a, b = b % a, a
	return b

def power2mod(n, mod):
	res, x = 1, 2
	for ; n > 0; n >>= 1:
		if n&1 == 1:
			res = res * x % mod
		x = x * x % mod
	return res

def power2(n):
	return power2mod(n, magic)

