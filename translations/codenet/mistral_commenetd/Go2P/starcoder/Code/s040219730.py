
import sys

MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = 1 << 60
INF_BIT60 = 1 << 60
INF_INT32 = 1 << 30
INF_BIT30 = 1 << 30
NIL = -1

# for dijkstra, prim, and so on
WHITE = 0
GRAY = 1
BLACK = 2

def main():
	# Read input
	n, q = map(int, input().split())
	C = list(map(int, input().split()))

	# Initialize P array and Fenwick Tree
	P = [-1] * (n + 50)

	# Process queries
	for i in range(q):
		l, r = map(int, input().split())
		query = Query(i, l, r)
		Q.append(query)

	Q.sort(key=lambda x: x.r)
	ft = NewFenwickTree(n + 50)

	k = 0
	for query in Q:
		# Process each query
		for k < query.r:
			if P[C[k]]!= -1:
				ft.Add(P[C[k]] + 1, -1)
			P[C[k]] = k
			ft.Add(k + 1, 1)

			k += 1

		# Calculate answer and print it
		Answers[query.idx] = ft.Sum(query.r) - ft.Sum(query.l - 1)

	# Print answers
	for i in range(q):
		print(Answers[i])

# Public methods
# ft := NewFenwickTree(200000 + 5)
# s := ft.Sum(i) 						# Sum of [1, i](1-based)
# ft.Add(i, x) 							# Add x to i(1-based)
# idx := ft.LowerBound(w) 		# minimum idx such that bit.Sum(idx) >= w

class FenwickTree:
	def __init__(self, n):
		self.dat = [0] * (n + 1)
		self.n = n
		self.minPow2 = 1
		for {
			if (self.minPow2 << 1) > n {
				break
			}
			self.minPow2 <<= 1
		}

	# Sum of [1, i](1-based)
	def Sum(self, i):
		s = 0

		for i > 0 {
			s += self.dat[i]
			i -= i & (-i)
		}

		return s

	# Add x to i(1-based)
	def Add(self, i, x):
		for i <= self.n {
			self.dat[i] += x
			i += i & (-i)
		}

	# LowerBound returns minimum i such that bit.Sum(i) >= w.
	def LowerBound(self, w):
		if w <= 0 {
			return 0
		}

		x = 0
		for k in range(self.minPow2, 0, -1):
			if x + k <= self.n and self.dat[x + k] < w {
				w -= self.dat[x + k]
				x += k
			}

		return x + 1

class Query:
	def __init__(self, idx, l, r):
		self.idx = idx
		self.l = l
		self.r = r

def newReadString(ior io.Reader, sf SplitFunc) -> Callable[[], str]:
	r = bufio.NewScanner(ior)
	r.Buffer(make([]byte, 1024), int(1e+11))
	r.Split(sf)

	return r.Text

def ReadInt() -> int:
	return int(input())

def ReadIntSlice(n int) -> List[int]:
	return list(map(int, input().split()))

def ReadInt2() -> Tuple[int, int]:
	return map(int, input().split())

def ReadInt3() -> Tuple[int, int, int]:
	return map(int, input().split())

def ReadInt4() -> Tuple[int, int, int, int]:
	return map(int, input().split())

def ReadInt5() -> Tuple[int, int, int, int, int]:
	return map(int, input().split())

def ReadInt6() -> Tuple[int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt7() -> Tuple[int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt8() -> Tuple[int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt9() -> Tuple[int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt10() -> Tuple[int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt11() -> Tuple[int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt12() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt13() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt14() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt15() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt16() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt17() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt18() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt19() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt20() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt21() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt22() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt23() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt24() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt25() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt26() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt27() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt28() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt29() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt30() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt31() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt32() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt33() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt34() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt35() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt36() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt37() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt38() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt39() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt40() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt41() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt42() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt43() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt44() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt45() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int]:
	return map(int, input().split())

def ReadInt46() -> Tuple[int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int,