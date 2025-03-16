
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
		A, B := readTwoNums(reader)
		res := solve(A, B)
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

func solve(A int64, B int64) int {
	const MAX = 707106
	const PRIME_SIZE = 147
	tbl := make([]bool, MAX)
	prime := make([]int, PRIME_SIZE)
	sz := 0

	for i := 2; i < PRIME_SIZE; i++ {
		p := prime[i]
		for j := p * p; j < MAX; j += p {
			tbl[j] = true
		}
	}

	for i := 853; i < MAX; i += 2 {
		if!tbl[i] {
			prime[sz] = i
			sz++
		}
	}

	var idx [MAX]int
	var base [MAX]int

	for i := 0; i < sz; i++ {
		p := prime[i]
		for j := p * p; j <= B; j *= p {
			var k int
			var x int64 = j
			for x <= B {
				if idx[x-A] == 0 || base[x-A] == p {
					x *= int64(p)
					continue
				}
				idx[x-A] = k
				base[x-A] = p
				k++
				x *= int64(p)
			}
		}
	}

	var res int

	for i := int64(B - A + 1); i > 0; i-- {
		if idx[i-1] > 0 {
			res++
		}
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
	if a <= b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
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

func powMod(a, b, mod int) int {
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
			q = b / a
		}
		a -= q * b
		swap(&a, &b)
		x -= q * y
		swap(&x, &y)
	}

	return x
}

func swap(a, b *int) {
	tmp := *a
	*a = *b
	*b = tmp
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

func readString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
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

func main() {
	reader := bufio.NewReader(os.Stdin)

	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		A, B := readTwoNums(reader)
		res := solve(A, B)
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

func solve(A int64, B int64) int {
	const MAX = 707106
	const PRIME_SIZE = 147
	tbl := make([]bool, MAX)
	prime := make([]int, PRIME_SIZE)
	sz := 0

	for i := 2; i < PRIME_SIZE; i++ {
		p := prime[i]
		for j := p * p; j < MAX; j += p {
			tbl[j] = true
		}
	}

	for i := 853; i < MAX; i += 2 {
		if!tbl[i] {
			prime[sz] = i
			sz++
		}
	}

	var idx [MAX]int
	var base [MAX]int

	for i := 0; i < sz; i++ {
		p := prime[i]
		for j := p * p; j <= B; j *= p {
			var k int
			var x int64 = j
			for x <= B {
				if idx[x-A] == 0 || base[x-A] == p {
					x *= int64(p)
					continue
				}
				idx[x-A] = k
				base[x-A] = p
				k++
				x *= int64(p)
			}
		}

	var res int
	for i := int64(B - A + 1); i > 0; i-- {
		if idx[i-1] > 0 {
			res++
		}

	return res
}

func max(a, b int) int {
	if a > b {
		return a;
	}
	return b;
}

func min(a, b int) int {
	if a > b {
		return a;
	}
	return b;
}

func abs(x int) int {
	if x < 0 {
		return -x;
	}
	return x;
}

func pow(x, n int) int {
	if n == 0 {
		return 1;
	}
	return x * pow(x, n);
}

func powMod(x, n, mod int) int {
	if n == 1 {
		return x;
	}

func modInverse(a, mod int) int {
	if a == 1 {
		return a;
	}

func gcd(a, b int) int {
	if a == 1 {
		return a;
	}

func lcm(a, b int) int {
	if a == 1 {
		return a;
	}

func sqrt(x int) int {
	if x == 1 {
		return (int)sqrt(x);
	}

func cbrt(x int) int {
	if x == 1 {
		return (int)cbrt(x);
	}

func max(a, b int) int {
	if x == 1 {
		return a;
	}

func min(a, b int) int {
	if x == 1 {
		return a;
	}

func max(a, b int) int {
	if x == 1 {
		return b;
	}

func min(a, b int) int {
	if x == 1 {
		return a;
	}

func abs(x int) int {
	if x == 1 {
		return x;
	}

func pow(x, n int) int {
	if n == 1 {
		return pow(x, n int) int {
	if n == 1 {
		return n;
	}

func powMod(x, n, mod int) int {
	if n == 1 {
		return x;
	}

func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return a;
	}

func max(a, b int) int {
	if n == 1 {
		return b;
	}

func min(a, b int) int {
	if n == 1 {
		return a;
	}

func max(a, b int) int {
	if n == 1 {
		return b;
	}

func min(a, b int) int {
	if n == 1 {
		return a;
	}

func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return b;
	}

func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return a;
	}

func max(a, b int) int {
	if n == 1 {
		return b;
	}

func min(a, b int) int {
	if n == 1 {
		return a;
	}

func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return b;
	}

func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return b;
	}

func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return a;
	}

func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return b;
	}

func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return a;
	}


func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return b;
	}

func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return b;
	}

func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return b;
	}

func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return b;
	}

func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return a;
	}

func max(a, b int) int {
	if n == 1 {
		return b;
	}

func min(a, b int) int {
	if n == 1 {
		return a;
	}

func max(a, b int) int {
	if n == 1 {
		return b;
	}

func min(a, b int) int {
	if n == 1 {
		return a;
	}

func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return a;
	if n == 1 {
		return b;
	}

func max(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
	if n == 1 {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return a;
	}

func min(a, b int) int {
	if n == 1 {
		return a;
	}
func min(a, b int) int {
	if n == 1 {
		return a;
	}
func min(a, b int) int {
	if n == 1 {
		return a;
	}
func min(a, b int) int {
	if n == 1 {
	if n == 1 {
	return a;
	}
func min(a, b int) int {
	if n == 1 {
	if n == 1 {
	if n == 1 {
	if n == 1 {
	if n == 1 {
	return a;
	}
func min(a, b int) int {
	if n == 1 {
	if n == 1 {
	if n == 1 {
	if n =