
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
		res := solve(n)
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

func solve(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		for n%p == 0 {
			n /= p
			e++
		}
		for i := 1; i <= e; i++ {
			res += e / i
		}
	}

	return res
}

func getFactor(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func pow(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res *= a
		}
		a *= a
		b >>= 1
	}
	return res
}

func powMod(a, b int, mod int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = (res * a) % mod
		}
		a = (a * a) % mod
		b >>= 1
	}
	return res
}

func modInverse(a, mod int) int {
	a %= mod
	if a == 0 {
		return 0
	}
	b := mod
	x := 0
	y := 1

	for b > 0 {
		var q int
		if a > b {
			q = a / b
		} else {
			return 0
		}
		a -= q * b
		x -= q * y
		swap(&a, &b)
		swap(&x, &y)
	}

	return x
}

func swap(x, y *int) {
	*x, *y = *y, *x
}

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	if n <= 3 {
		return true
	}
	if n%2 == 0 || n%3 == 0 {
		return false
	}
	i := 5
	for i*i <= n {
		if n%i == 0 || n%(i+2) == 0 {
			return false
		}
		i += 6
	}
	return true
}

func nextPrime(n int) int {
	if n <= 2 {
		return 2
	}
	n++
	for!isPrime(n) {
		n++
	}
	return n
}

func generatePrimes(n int) []int {
	primes := make([]int, 0, n/10)
	for i := 2; i <= n; i++ {
		if isPrime(i) {
			primes = append(primes, i)
		}
	}
	return primes
}

func generateFactorial(n int, mod int) []int {
	fac := make([]int, n+1)
	fac[0] = 1
	for i := 1; i <= n; i++ {
		fac[i] = (fac[i-1] * i) % mod
	}
	return fac
}

func modInv(n int, p int) int {
	return powMod(n, p-2, p)
}

func nCr(n int, r int, p int) int {
	num := generateFactorial(n, p)[n]
	den := (generateFactorial(r, p)[r] * generateFactorial(n-r, p)[n-r]) % p
	return (num * modInv(den, p)) % p
}

func min3(a, b, c int) int {
	return min(a, min(b, c))
}

func max3(a, b, c int) int {
	return max(a, max(b, c))
}

func min4(a, b, c, d int) int {
	return min(min(a, b), min(c, d))
}

func max4(a, b, c, d int) int {
	return max(max(a, b), max(c, d))
}

func readNBits(reader *bufio.Reader, n int) uint64 {
	bits := make([]byte, n)
	for i := 0; i < n; i++ {
		c, _ := reader.ReadByte()
		bits[i] = c
	}
	res := uint64(0)
	for i := 0; i < n; i++ {
		res <<= 1
		if bits[i] == '1' {
			res++
		}
	}
	return res
}

func main1() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve(n)
		fmt.Println(res)
	}
}

func solve1(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		for n%p == 0 {
			n /= p
			e++
		}
		for i := 1; i <= e; i++ {
			res += e / i
		}
	}

	return res
}

func getFactor(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func main2() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve1(n)
		fmt.Println(res)
	}
}

func solve2(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		for n%p == 0 {
			n /= p
			e++
		}
		for i := 1; i <= e; i++ {
			res += e / i
		}
	}

	return res
}

func getFactor(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func main3() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve2(n)
		fmt.Println(res)
	}
}

func solve3(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		for n%p == 0 {
			n /= p
			e++
		}
		for i := 1; i <= e; i++ {
			res += e / i
		}
	}

	return res
}

func getFactor(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func main4() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve3(n)
		fmt.Println(res)
	}
}

func solve4(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		for n%p == 0 {
			n /= p
			e++
		}
		for i := 1; i <= e; i++ {
			res += e / i
		}
	}

	return res
}

func getFactor(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func main5() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve4(n)
		fmt.Println(res)
	}
}

func solve5(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		for n%p == 0 {
			n /= p
			e++
		}
		for i := 1; i <= e; i++ {
			res += e / i
		}
	}

	return res
}

func getFactor(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func main6() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve5(n)
		fmt.Println(res)
	}
}

func solve6(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		for n%p == 0 {
			n /= p
			e++
		}
		for i := 1; i <= e; i++ {
			res += e / i
		}
	}

	return res
}

func getFactor(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func main7() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve6(n)
		fmt.Println(res)
	}
}

func solve7(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		for n%p == 0 {
			n /= p
			e++
		}
		for i := 1; i <= e; i++ {
			res += e / i
		}
	}

	return res
}

func getFactor(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func main8() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve7(n)
		fmt.Println(res)
	}
}

func solve8(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		for n%p == 0 {
			n /= p
			e++
		}
		for i := 1; i <= e; i++ {
			res += e / i
		}
	}

	return res
}

func getFactor(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func main9() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve8(n)
		fmt.Println(res)
	}
}

func solve9(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		for n%p == 0 {
			n /= p
			e++
		}
		for i := 1; i <= e; i++ {
			res += e / i
		}
	}

	return res
}

func getFactor(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func main10() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve9(n)
		fmt.Println(res)
	}
}

func solve10(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		for n%p == 0 {
			n /= p
			e++
		}
		for i := 1; i <= e; i++ {
			res += e / i
		}
	}

	return res
}

func getFactor(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func main11() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve10(n)
		fmt.Println(res)
	}
}

func solve11(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		for n%p == 0 {
			n /= p
			e++
		}
		for i := 1; i <= e; i++ {
			res += e / i
		}
	}

	return res
}

func getFactor(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func main12() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve11(n)
		fmt.Println(res)
	}
}

func solve12(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		for n%p == 0 {
			n /= p
			e++
		}
		for i := 1; i <= e; i++ {
			res += e / i
		}
	}

	return res
}

func getFactor(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return i
		}
	return n
}

func main13() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve12(n)
		fmt.Println(res)
	}
}

func solve13(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		for n%p == 0 {
			n /= p
			e++
		}
		for i := 1; i <= e; i++ {
			res += e / i
		}
	}

	return res
}

func getFactor(n int) int {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return i
		}
	return n
}

func main14() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve13(n)
		fmt.Println(res)
	}
}

func solve14(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		e := 0
		fo