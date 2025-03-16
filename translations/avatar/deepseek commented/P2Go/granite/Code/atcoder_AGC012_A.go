
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNNums(reader, n)
		res := solve(n, A)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	res := readNNums(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func solve(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func min(a, b int) int {
	return a + b - max(a, b)
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func add(a, b int) int {
	a += b
	if a >= MOD {
		a -= MOD
	}
	return a
}

func mul(a, b int) int {
	return int(int64(a) * int64(b) % MOD)
}

func pow(a, b int) int {
	r := 1
	for b > 0 {
		if b&1 == 1 {
			r = mul(r, a)
		}
		a = mul(a, a)
		b >>= 1
	}
	return r
}

func powMod(a, b int) int {
	r := 1
	a %= MOD
	for b > 0 {
		if b&1 == 1 {
			r = mul(r, a)
		}
		a = mul(a, a)
		b >>= 1
	}
	return r
}

func inverse(a int) int {
	return powMod(a, MOD-2)
}

func div(a, b int) int {
	return mul(a, inverse(b))
}

func allFactors(n int) []int {
	res := make([]int, 0, 8)
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			res = append(res, i)
			if i*i!= n {
				res = append(res, n/i)
			}
		}
	}
	return res
}

func inFactor(n int, factors []int) bool {
	for _, factor := range factors {
		if n%factor == 0 {
			return true
		}
	}
	return false
}

func sumFactor(n int, factors []int) int {
	res := 0
	for _, factor := range factors {
		if n%factor == 0 {
			res += factor
		}
	}
	return res
}

func minFactor(n int, factors []int) int {
	res := 1 << 30
	for _, factor := range factors {
		if n%factor == 0 {
			res = min(res, factor)
		}
	}
	return res
}

func maxFactor(n int, factors []int) int {
	res := 0
	for _, factor := range factors {
		if n%factor == 0 {
			res = max(res, factor)
		}
	}
	return res
}

func countFactors(n int, factors []int) int {
	cnt := 0
	for _, factor := range factors {
		if n%factor == 0 {
			cnt++
		}
	}
	return cnt
}

func sumDivisors(n int) int {
	res := 0
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			res += i
			if i*i!= n {
				res += n / i
			}
		}
	}
	return res
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

func factors(n int) []int {
	res := make([]int, 0, 8)
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			res = append(res, i)
			if i*i!= n {
				res = append(res, n/i)
			}
		}
	}
	return res
}

func primeFactors(n int) []int {
	var res []int
	for n > 1 {
		p := smallPrimes[n]
		if p < 0 {
			break
		}
		res = append(res, p)
		n /= p
	}
	return res
}

func factorCount(n int) map[int]int {
	cnt := make(map[int]int)
	for n > 1 {
		p := smallPrimes[n]
		if p < 0 {
			break
		}
		cnt[p]++
		n /= p
	}
	return cnt
}

func modAdd(a, b int, mod int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	return a
}

func modMul(a, b int, mod int) int {
	return int(int64(a) * int64(b) % int64(mod))
}

func modPow(a, b int, mod int) int {
	res := 1
	a %= mod
	for b > 0 {
		if b&1 == 1 {
			res = modMul(res, a, mod)
		}
		a = modMul(a, a, mod)
		b >>= 1
	}
	return res
}

func modInverse(a int, mod int) int {
	return modPow(a, mod-2, mod)
}

func modDiv(a, b int, mod int) int {
	a %= mod
	inv := modInverse(b, mod)
	if inv < 0 {
		inv += mod
	}
	return modMul(a, inv, mod)
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

func isEven(n int) bool {
	return n&1 == 0
}

func isOdd(n int) bool {
	return n&1 == 1
}

func randInt(n int) int {
	return rand.Intn(n)
}

func randInt63(n int64) int64 {
	return rand.Int63n(n)
}

func randUInt64(n uint64) uint64 {
	return rand.Uint64() % n
}

func randFloat64() float64 {
	return rand.Float64()
}

func randFloat64Range(min, max float64) float64 {
	return rand.Float64()*(max-min) + min
}

func randNFloat64(n int) []float64 {
	res := make([]float64, n)
	for i := 0; i < n; i++ {
		res[i] = rand.Float64()
	}
	return res
}

func randIntN(n int, limit int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = rand.Intn(limit)
	}
	return res
}

func solve1(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve2(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve3(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve4(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve5(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve6(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve7(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve8(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve9(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve10(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve11(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve12(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve13(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve14(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve15(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve16(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve17(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve18(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve19(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve20(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve21(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve22(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve23(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve24(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve25(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve26(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve27(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve28(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve29(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve30(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve31(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve32(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve33(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve34(n int, A []int) int {
	sort.Ints(A)

	var res int

	for i := n * 2; i < len(A); i += 2 {
		res += A[i]
	}

	return res
}

func solve35(n int, A []int) int {
	sort.I