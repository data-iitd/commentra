

import sys

def main():
    # Initialize a buffered reader to read input
    r = sys.stdin.buffer
    n, m, R = map(int, r.readline().split())
    rs = list(map(int, r.readline().split()))
    rs = [r - 1 for r in rs]
    costs = [[float('inf')] * n for _ in range(n)]
    for i in range(n):
        costs[i][i] = 0
    for _ in range(m):
        a, b, c = map(int, r.readline().split())
        a -= 1
        b -= 1
        costs[a][b] = c
        costs[b][a] = c
    for k in range(n):
        for i in range(n):
            for j in range(n):
                costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])
    perms = permutations(rs)
    ans = float('inf')
    for perm in perms:
        tmp = 0
        for j in range(1, len(perm)):
            from_ = perm[j - 1]
            to = perm[j]
            tmp += costs[from_][to]
        ans = min(ans, tmp)
    print(ans)

def permutations(arr):
    res = []
    def helper(arr, n):
        if n == 1:
            res.append(arr[:])
        else:
            for i in range(n):
                helper(arr, n - 1)
                if n % 2 == 1:
                    arr[i], arr[n - 1] = arr[n - 1], arr[i]
                else:
                    arr[0], arr[n - 1] = arr[n - 1], arr[0]
    helper(arr, len(arr))
    return res

class UnionFind:
    def __init__(self, n):
        self.d = [-1] * n

    def find(self, x):
        if self.d[x] < 0:
            return x
        self.d[x] = self.find(self.d[x])
        return self.d[x]

    def unite(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x == root_y:
            return False
        if self.d[root_x] < self.d[root_y]:
            self.d[root_x] += self.d[root_y]
            self.d[root_y] = root_x
        else:
            self.d[root_y] += self.d[root_x]
            self.d[root_x] = root_y
        return True

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def size(self, x):
        return -self.d[self.find(x)]

def modpow(a, n, mod):
    res = 1
    while n > 0:
        if n % 2!= 0:
            res = res * a % mod
        a = a * a % mod
        n = n // 2
    return res

def modinv(n, mod):
    return modpow(n, mod - 2, mod)

def modcomb(n, a, mod):
    x = 1
    y = 1
    for i in range(a):
        x = x * (n - i) % mod
        y = y * (i + 1) % mod
    return x * modpow(y, mod - 2, mod) % mod

def modfactorial(n, mod):
    res = 1
    for i in range(1, n + 1):
        res = (res * i) % mod
    return res

class Combination:
    def __init__(self, n, mod):
        self.facts = [1] * (n + 1)
        self.invs = [1] * (n + 1)
        self.mod = mod

    def calc(self, n, k):
        res = self.facts[n] * self.invs[k]
        res %= self.mod
        res = res * self.invs[n - k]
        res %= self.mod
        return res

    def init(self, n):
        self.facts[0] = 1
        for i in range(1, n + 1):
            self.facts[i] = self.facts[i - 1] * i % self.mod
        self.invs[n] = modinv(self.facts[n], self.mod)
        for i in range(n - 1, -1, -1):
            self.invs[i] = self.invs[i + 1] * (i + 1) % self.mod

def min(x, y):
    if x < y:
        return x
    return y

def max(x, y):
    if x > y:
        return x
    return y

def abs(x):
    if x < 0:
        return -x
    return x

def primeFactor(x):
    res = {}
    for i in range(2, x + 1):
        while x % i == 0:
            res[i] = res.get(i, 0) + 1
            x = x // i
    if x!= 1:
        res[x] = res.get(x, 0) + 1
    return res

def divisor(x):
    res = []
    for i in range(1, x + 1):
        if x % i == 0:
            res.append(i)
            if i!= x // i:
                res.append(x // i)
    return res

def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x % y)

def lcm(x, y):
    return x // gcd(x, y) * y

def reverseString(s):
    r = list(s)
    for i, j := 0, len(r)-1
    for i := 0; i < len(r)/2; i++ {
        r[i], r[j] = r[j], r[i]
        j--
    }
    return string(r)

def pow(a, n):
    res := 1
    for i := 1; i <= n; i++ {
        res *= a
    }
    return res

type Queue []int

func (q *Queue) empty() bool {
    return len(*q) == 0
}

func (q *Queue) push(i int) {
    *q = append(*q, i)
}

func (q *Queue) pop() (int, bool) {
    if q.empty() {
        return 0, false
    } else {
        res := (*q)[0]
        *q = (*q)[1:]
        return res, true
    }
}

type Stack []int

func (s *Stack) empty() bool {
    return len(*s) == 0
}

func (s *Stack) push(i int) {
    *s = append(*s, i)
}

func (s *Stack) pop() (int, bool) {
    if s.empty() {
        return 0, false
    } else {
        res := (*s)[0]
        *s = (*s)[1:]
        return res, true
    }
}

type priority_queue []int

func (h priority_queue) Len() int {
    return len(h)
}

func (h priority_queue) Less(i, j int) bool {
    return h[i] > h[j]
}

func (h priority_queue) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

func (h *priority_queue) Push(x interface{}) {
    *h = append(*h, x.(int))
}

func (h *priority_queue) Pop() (interface{}, bool) {
    if h.empty() {
        return nil, false
    } else {
        res := h[0]
        *h = h[1:]
        return res, true
    }
}

type point struct {
    x int
    y int
}

type points []point

func (p points) Len() int {
    return len(p)
}

func (p points) Less(i, j int) bool {
    return p[i].x < p[j].x
}

func (p points) Swap(i, j int) {
    p[i], p[j] = p[j], p[i]
}

func (p points) Push(x interface{}) {
    *p = append(*p, x.(int))
}

func (p points) Pop() (interface{}, bool) {
    if p.empty() {
        return nil, false
    } else {
        res := p[0]
        *p = p[1:]
        return res, true
    }
}

func min(x, y int) int {
    return min(x, y)
}

func max(x, y int) int {
    return max(x, y)
}

func (p points) Len() int {
    return len(p)
}

func (p points) Less(i, j int) bool {
    return p[i].x < p[j].x
}

func (p points) Swap(i, j int) {
    p[i], p[j] = p[j], p[i]
    return p[i], p[j] = p[j], p[i]
}

func (p points) Pop() (interface{}, bool) {
    if p.empty() {
        return nil, false
    } else {
        res := p[0]
        *p = p[1:]
        return res, true
    }
}

func (p points) Len() int {
    return len(p)
}

func (p points) Less(i, j int) bool {
    return p[i].x < p[j].x
}

func (p points) Swap(i, j int) {
    p[i], p[j] = p[j], p[i]
    return p[i], p[j] = p[j], p[i]
    }

func (p points) Pop() (interface{}, bool) {
    if p.empty() {
        return nil, false
    } else {
        res := p[0]
        *p = p[1:]
        return res, true
    }
}

func (p points) Len() int {
    return len(p)
}

func (p points) Less(i, j int) bool {
    return p[i].x < p[j].x
}

func (p points) Swap(i, j int) {
    p[i], p[j] = p[j], p[i]
    return p[i], p[j] = p[j], p[i]
    }

func (p points) Pop() (interface{}, bool) {
    if p.empty() {
        return nil, false
    } else {
        res := p[0]
        *p = p[1:]
        return res, true
    }
}

func (p points) Len() int {
    return len(p)
}

func (p points) Less(i, j int) bool {
    return p[i].x < p[j].x
}

func (p points) Swap(i, j int) {
    p[i], p[j] = p[j], p[i]
    return p[i], p[j] = p[j], p[i]
    }

func (p points) Pop() (interface{}, bool) {
    if p.empty() {
        return nil, false
    } else {
        res := p[0]
        *p = p[1:]
        return res, true
    }
}

func (p points) Len() int {
    return len(p)
}

func (p points) Less(i, j int) bool {
    return p[i].x < p[j].x
}

func (p points) Swap(i, j int) {
    p[i], p[j] = p[j], p[i]
    return p[i], p[j] = p[j], p[i]
    }

func (p points) Pop() (interface{}, bool) {
    if p.empty() {
        return nil, false
    } else {
        res := p[0]
        *p = p[1:]
        return res, true
    }
}

func (p points) Len() int {
    return len(p)
}

func (p points) Less(i, j int) bool {
    return p[i].x < p[j].x
}

func (p points) Swap(i, j int) {
    p[i], p[j] = p[j], p[i]
    return p[i], p[j] = p[j], p[i]
    }
}

func (p points) Pop() (interface{}, bool) {
    return p[i], p[j] = p[j], p[i]
    }
}

func (p points) Less(i, j int) bool {
    return p[i].x < p[j].x
}

func (p points) Swap(i, j int) {
    p[i], p[j] = p[j], p[i]
    return p[i], p[j] = p[j], p[i]
    }
}

func (p points) Len() int {
    return len(p)
}

func (p points) Less(i, j int) bool {
    return p[i].x < p[j].x
}

func (p points) Swap(i, j int) {
    p[i], p[j] = p[j]
		return p[0]
		return p[1:]
		return p[0]
	}
}

func (p points) Pop() (interface{}, bool) {
    return nil, false
}

func (p points) Less(i, j int) bool {
    return p[i].x < p[j].x
}

func (p points) Swap(i, j int) {
    p[i], p[j] = p[j], p[i]
    return p[i], p[j] = p[j], p[i]
}


func (p points) Pop() (interface{}, bool) {
    return p[j] = p[j], p[i]
    return p[i], p[j] = p[j], p[i]
}

func (p points) Less(i, j int) bool {
    return p[i].x < p[j].x
}

func (p points) Swap(i, j int) {
    p[i], p[j] = p[j]
}

func (p points) Len() int {
    return len(p)
}

func (p points) Less(i, j int) bool {
    return p[i], p[j] = p[j]
}

func (p points) Swap(i, j int) {
    p[i], p[j] = p[j]
	}
	func (p points) Pop() (interface{}, bool) {
    return p[i] = p[j]
	}

func (p points) Len() int {
    return len(p)
	}

func (p points) Less(i, j int) bool {
    return p[i] = p[j]
	}

func (p points) Swap(i, j int) {
    return p[i] = p[j]
	}

func (p points) Less(i) {
    return p[i], p[j] = p[j]
	}
	}

func (p points) Swap(i) {
    return p[i] = p[j]
	}
	}

func (p points) Len() int {
    return len(p)
	}
	return p[i], p[j] = p[j]
	}
	}
	func (p points) Swap(i, j int) {
    return p[i] = p[j]
	}
	}
	}
	}
	}
	}
	func (p points) Less(i, j int) {
    return p[i] = p[j]
	}
	}
	func (p points) Swap(i), p[j] = p[j]
	}
	}
	return p[i], p[j] = p[j]
	}
	}

func (p points) Len() int {
    return len(p)
}


	}
	}
	return p[i], p[j] = p[j]
	}
	}

	return p[i], p[j] = p[j]
}


	}
	func (p points) Len() int {
    return len(p)
}

func (p points)
	return p[i], p