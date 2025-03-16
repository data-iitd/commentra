
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
	ris = readInt64Slice
)

func main() {
	const inf = 1 << 30
	dp := make([]int, 101000)
	for i := range dp {
		dp[i] = inf
	}
	dp[0] = 0
	n, k := ri(), ri()
	h := make([]int, n)
	for i := range h {
		h[i] = ri()
	}
	for i := 0; i < n; i++ {
		for j := 1; j <= k; j++ {
			dp[i+j] = min(dp[i+j], dp[i]+abs(h[i]-h[i+j]))
		}
	}
	fmt.Fprintln(w, dp[n-1])
	w.Flush()
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func readString() string {
	s, _ := r.ReadString('\n')
	return s[:len(s)-1]
}

func readBytes() []byte {
	s, _ := r.ReadBytes('\n')
	return s[:len(s)-1]
}

func readInt64() int64 {
	i, _ := ri64()
	return i
}

func readInt64Slice(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = ri64()
	}
	return a
}

func ri() int {
	i, _ := ri64()
	return int(i)
}

func ri64() (int64, error) {
	return r.ReadInt64()
}

func rf() float64 {
	f, _ := rf64()
	return f
}

func rf64() (float64, error) {
	return r.ReadFloat64()
}

func debug(args...interface{}) {
	fmt.Fprintln(os.Stderr, args...)
}

func debugf(format string, args...interface{}) {
	fmt.Fprintf(os.Stderr, format, args...)
}

func minInt64(a...int64) int64 {
	res := a[0]
	for _, v := range a[1:] {
		if v < res {
			res = v
		}
	}
	return res
}

func maxInt64(a...int64) int64 {
	res := a[0]
	for _, v := range a[1:] {
		if v > res {
			res = v
		}
	}
	return res
}

func minInt(a...int) int {
	res := a[0]
	for _, v := range a[1:] {
		if v < res {
			res = v
		}
	}
	return res
}

func maxInt(a...int) int {
	res := a[0]
	for _, v := range a[1:] {
		if v > res {
			res = v
		}
	}
	return res
}

func sortInt64(a []int64) {
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
}

func sortInt(a []int) {
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
}

func reverseInt64(a []int64) {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}

func reverseInt(a []int) {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}

func reverseInt64Slice(a []int64) {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}

func reverseIntSlice(a []int) {
	for i, j := 0, len(a)-1; i < len(a)/2; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}

func canProceed(s string) bool {
	stack := []rune{}
	for _, c := range s {
		if c == '(' {
			stack = append(stack, c)
		} else if c == ')' {
			if len(stack) == 0 {
				return false
			}
			stack = stack[:len(stack)-1]
		}
	}
	return len(stack) == 0
}

func isPalindrome(s string) bool {
	n := len(s)
	for i := 0; i < n/2; i++ {
		if s[i]!= s[n-1-i] {
			return false
		}
	}
	return true
}

func isPermutation(s1 string, s2 string) bool {
	if len(s1)!= len(s2) {
		return false
	}
	count := make(map[rune]int)
	for _, c := range s1 {
		count[c]++
	}
	for _, c := range s2 {
		if count[c] == 0 {
			return false
		}
		count[c]--
	}
	return true
}

func gcd(a, b int) int {
	for b!= 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int) int {
	return a * b / gcd(a, b)
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

func prevPrime(n int) int {
	if n <= 1 {
		return 2
	}
	n--
	for!isPrime(n) {
		n--
	}
	return n
}

func modInverse(a, m int) int {
	a %= m
	for a!= 0 && m%a!= 0 {
		tmp := m % a
		m = a
		a = tmp
	}
	if a == 0 {
		return 0
	}
	res := modInverse(m/a, a)
	return (m - res*a) / a
}

func modPow(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow2(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow3(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow4(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow5(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow6(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow7(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow8(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow9(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow10(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow11(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow12(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow13(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow14(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow15(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow16(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow17(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow18(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow19(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow20(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow21(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow22(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow23(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow24(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow25(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow26(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow27(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow28(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow29(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow30(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow31(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow32(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow33(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow34(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow35(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow36(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow37(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	}
	return res
}

func modPow38(x, n, mod int) int {
	res := 1
	x %= mod
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % mod
		}
		x = (x * x) % mod
		n >>= 1
	