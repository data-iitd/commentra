
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	rw  = bufio.NewReadWriter(bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout))
	r   = bufio.NewReader(os.Stdin)
	w   = bufio.NewWriter(os.Stdout)
	rf  = readFloat64
	ri  = readInt64
	ris = readInt64Slice
	rs  = readString
	ris = readStringSlice
)

func main() {
	N, X := ri(), ri()
	A := ris(N)
	sort.Slice(A, func(i, j int) bool {
		return A[i] < A[j]
	})
	ans := int64(0)
	for _, a := range A {
		X -= a
		ans++
	}
	ans += X / A[0]
	fmt.Fprintln(w, ans)
	w.Flush()
}

func readStringSlice(n int) []string {
	s := make([]string, n)
	for i := range s {
		s[i] = rs()
	}
	return s
}

func readString() string {
	s, _ := r.ReadString('\n')
	return s[:len(s)-1]
}

func readInt64Slice(n int) []int64 {
	s := make([]int64, n)
	for i := range s {
		s[i] = ri()
	}
	return s
}

func readInt64() int64 {
	i, _ := ri(), ri()
	return i
}

func readFloat64() float64 {
	f, _ := rf(), rf()
	return f
}

func readLine() string {
	line, _ := r.ReadString('\n')
	return line
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func pow(a, b int) int {
	return int(math.Pow(float64(a), float64(b)))
}

func abs(a int) int {
	return int(math.Abs(float64(a)))
}

func mod(a, b int) int {
	return a - b*int(math.Floor(float64(a)/float64(b)))
}

func isPrime(n int) bool {
	if n == 2 {
		return true
	}
	if n < 2 || n%2 == 0 {
		return false
	}
	for i := 3; i <= int(math.Sqrt(float64(n))); i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func numDigits(n int) int {
	return len(fmt.Sprintf("%d", n))
}

func isPermutation(s string) bool {
	count := make(map[rune]int)
	for _, r := range s {
		count[r]++
	}
	for _, n := range count {
		if n%2!= 0 {
			return false
		}
	}
	return true
}

func fact(n int) int {
	res := 1
	for i := 1; i <= n; i++ {
		res *= i
	}
	return res
}

func comb(n, r int) int {
	return fact(n) / fact(r) / fact(n-r)
}

func gcm(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcm(a, b)
}

func readNInt64s(n int) []int64 {
	res := make([]int64, n)
	for i := 0; i < n; i++ {
		res[i] = ri()
	}
	return res
}

func readNInt64s2(n int) [][]int64 {
	res := make([][]int64, n)
	for i := 0; i < n; i++ {
		res[i] = readNInt64s(n)
	}
	return res
}

func readInt64s() []int64 {
	return readNInt64s(ri())
}

func readInt64s2(n int) [][]int64 {
	return readNInt64s2(n)
}

func readInt64s3(n int) []int64 {
	res := make([]int64, n)
	for i := 0; i < n; i++ {
		res[i] = ri() - 1
	}
	return res
}

func readInt64s4(n int) [][]int64 {
	res := make([][]int64, n)
	for i := 0; i < n; i++ {
		res[i] = readInt64s3(n)
	}
	return res
}

func readRunes() []rune {
	return []rune(rs())
}

func isDebug() bool {
	_, ok := os.LookupEnv("LOCAL")
	return ok
}

func debug(args...interface{}) {
	if isDebug() {
		fmt.Fprintln(os.Stderr, args...)
	}
}

func debugf(format string, args...interface{}) {
	if isDebug() {
		fmt.Fprintf(os.Stderr, format, args...)
	}
}

func minInt64(a...int64) int64 {
	res := a[0]
	for _, n := range a {
		if n < res {
			res = n
		}
	}
	return res
}

func maxInt64(a...int64) int64 {
	res := a[0]
	for _, n := range a {
		if n > res {
			res = n
		}
	}
	return res
}

func sumInt64(a...int64) int64 {
	res := int64(0)
	for _, n := range a {
		res += n
	}
	return res
}

func powInt64(n, p int64) int64 {
	res := int64(1)
	for p > 0 {
		if p%2 == 1 {
			res *= n
		}
		n *= n
		p /= 2
	}
	return res
}

func powModInt64(n, p, mod int64) int64 {
	res := int64(1)
	for p > 0 {
		if p%2 == 1 {
			res = res * n % mod
		}
		n = n * n % mod
		p /= 2
	}
	return res
}

func allBitsSet(n int64) bool {
	return n == int64(math.Pow(2, float64(numDigits(int(n)))))-1
}

func bitCount(n int64) int {
	count := 0
	for n > 0 {
		count += n & 1
		n >>= 1
	}
	return count
}

func isPowerOfTwo(n int64) bool {
	return n > 0 && (n&n-1) == 0
}

func gcd(a, b int64) int64 {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

func lcmMod(a, b, mod int64) int64 {
	return a * b % mod * modInt64(a, mod) % mod
}

func lcm(a, b int64) int64 {
	return a * b / gcd(a, b)
}

func modInt64(n, mod int64) int64 {
	return (n % mod + mod) % mod
}

func modInt642(n, mod int64) int64 {
	res := n % mod
	if res < 0 {
		res += mod
	}
	return res
}

func modInverse(n, mod int64) int64 {
	return modInt64(n, mod)
}

func modDiv(a, b, mod int64) int64 {
	a %= mod
	return a * modInverse(b, mod) % mod
}

func modAdd(a, b, mod int64) int64 {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modMul(a, b, mod int64) int64 {
	return a * b % mod
}

func modSub(a, b, mod int64) int64 {
	a -= b
	if a < 0 {
		a += mod
	}
	return a
}

func modPow(n, p, mod int64) int64 {
	res := int64(1)
	for p > 0 {
		if p%2 == 1 {
			res = modMul(res, n, mod)
		}
		n = modMul(n, n, mod)
		p /= 2
	}
	return res
}

func modPow2(n, p, mod int64) int64 {
	res := int64(1)
	for p > 0 {
		if p%2 == 1 {
			res = modMul(res, n, mod)
		}
		n = modMul(n, n, mod)
		p /= 2
	}
	return res
}

func modPow3(n, p, mod int64) int64 {
	res := int64(1)
	for p > 0 {
		if p%2 == 1 {
			res = modMul(res, n, mod)
		}
		n = modMul(n, n, mod)
		p /= 2
	}
	return res
}

func extGCD(a, b int64) (x, y int64) {
	if b == 0 {
		return 1, 0
	}
	x1, y1 := extGCD(b, a%b)
	return y1, x1 - a/b*y1
}

func modInv(a, mod int64) int64 {
	x, _ := extGCD(a, mod)
	return modInt64(x, mod)
}

func modDiv2(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv3(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv4(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv5(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv6(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv7(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv8(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv9(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv10(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv11(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv12(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv13(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv14(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv15(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv16(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv17(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv18(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv19(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv20(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv21(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv22(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv23(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv24(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv25(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv26(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv27(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv28(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv29(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv30(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv31(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv32(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv33(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv34(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv35(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv36(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv37(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv38(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv39(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv40(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv41(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv42(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv43(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv44(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv45(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv46(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv47(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv48(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv49(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv50(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv51(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv52(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv53(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv54(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, mod) % mod
}

func modDiv55(a, b, mod int64) int64 {
	a %= mod
	return a * modInv(b, 