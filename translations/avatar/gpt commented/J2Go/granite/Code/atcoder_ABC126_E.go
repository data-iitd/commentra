
package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = 1000000007

type UnionFindTree struct {
	n   int
	par []int
	rank []int
}

func NewUnionFindTree(n int) *UnionFindTree {
	utf := &UnionFindTree{
		n: n,
		par: make([]int, n),
		rank: make([]int, n),
	}
	for i := 0; i < n; i++ {
		utf.par[i] = i
		utf.rank[i] = 0
	}
	return utf
}

func (utf *UnionFindTree) Find(x int) int {
	if utf.par[x] == x {
		return x
	} else {
		utf.par[x] = utf.Find(utf.par[x])
		return utf.par[x]
	}
}

func (utf *UnionFindTree) Unite(x, y int) {
	x = utf.Find(x)
	y = utf.Find(y)
	if x == y {
		return
	}
	if utf.rank[x] < utf.rank[y] {
		utf.par[x] = y
	} else {
		utf.par[y] = x
		if utf.rank[x] == utf.rank[y] {
			utf.rank[x]++
		}
	}
}

func (utf *UnionFindTree) Same(x, y int) bool {
	return utf.Find(x) == utf.Find(y)
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)
	utf := NewUnionFindTree(n)
	m := nextInt(sc)
	for i := 0; i < m; i++ {
		x := nextInt(sc) - 1
		y := nextInt(sc) - 1
		z := nextInt(sc)
		utf.Unite(x, y)
	}
	cnt := 0
	for i := 0; i < n; i++ {
		if utf.par[i] == i {
			cnt++
		}
	}
	fmt.Println(cnt)
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func nextNumber(sc *bufio.Scanner) float64 {
	sc.Scan()
	f, err := strconv.ParseFloat(sc.Text(), 32)
	if err!= nil {
		panic(err)
	}
	return f
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, err := strconv.Atoi(sc.Text())
	if err!= nil {
		panic(err)
	}
	return n
}

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func max(x, y int) int {
	if x < y {
		return y
	} else {
		return x
	}
}

func pow(a, b int) int {
	r := 1
	for i := 0; i < b; i++ {
		r *= a
	}
	return r
}

func powMod(a, b, mod int) int {
	r := 1
	for i := 0; i < b; i++ {
		r = (r * a) % mod
	}
	return r
}

func modInv(a, mod int) int {
	b := mod
	u := 1
	v := 0
	for b > 0 {
		t := a / b
		a -= t * b
		a, b = b, a
		u -= t * v
		u, v = v, u
	}
	u %= mod
	if u < 0 {
		u += mod
	}
	return u
}

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func nextPrime(n int) int {
	if n <= 1 {
		return 2
	}
	n++
	for!isPrime(n) {
		n++
	}
	return n
}

func gcd(a, b int) int {
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func comb(n, r int) int {
	return fact(n) / fact(n-r) / fact(r)
}

func fact(n int) int {
	if n <= 1 {
		return 1
	}
	return n * fact(n-1)
}

func modFact(n, mod int) int {
	res := 1
	for i := 1; i <= n; i++ {
		res = (res * i) % mod
	}
	return res
}

func modPow(a, b, mod int) int {
	if b == 0 {
		return 1
	}
	if b%2 == 0 {
		return modPow((a*a)%mod, b/2, mod)
	} else {
		return (a * modPow(a, b-1, mod)) % mod
	}
}

func modInv(a, mod int) int {
	return modPow(a, mod-2, mod)
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	return (a * b) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modSub(a, b, mod int) int {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modMul(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modDiv(a, b, mod int) int {
	a %= mod
	b %= mod
	return (a * modInv(b, mod)) % mod
}

func modAdd(a, b, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func m