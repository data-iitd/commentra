
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		res := solve(n)
		buf := new(bytes.Buffer)
		buf.WriteString(fmt.Sprintf("%d\n", res))
		fmt.Print(buf.String())
	}
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
		for n%p == 0 {
			n /= p
		}
		res++
	}

	return res
}

func getFactor(n int) int {
	if n%2 == 0 {
		return 2
	}
	for i := 3; i*i <= n; i += 2 {
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

func modInverse(a int, mod int) int {
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

func isPrime(num int) bool {
	if num < 2 {
		return false
	}
	if num == 2 {
		return true
	}
	if num%2 == 0 {
		return false
	}
	for i := 3; i*i <= num; i += 2 {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func nextPrime(num int) int {
	if num <= 1 {
		return 2
	}
	num++
	for!isPrime(num) {
		num++
	}
	return num
}

func nextInt(num int) int {
	num++
	for isPrime(num) {
		num++
	}
	return num
}

func factorial(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		res *= i
	}
	return res
}

func combinationCount(n int, r int) int {
	return factorial(n) / (factorial(r) * factorial(n-r))
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

func solve(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		for n%p == 0 {
			n /= p
		}
		res++
	}

	return res
}

func getFactor(n int) int {
	if n%2 == 0 {
		return 2
	}
	for i := 3; i*i <= n; i += 2 {
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

func modInverse(a int, mod int) int {
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

func isPrime(num int) bool {
	if num < 2 {
		return false
	}
	if num == 2 {
		return true
	}
	if num%2 == 0 {
		return false
	}
	for i := 3; i*i <= num; i += 2 {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func nextPrime(num int) int {
	if num <= 1 {
		return 2
	}
	num++
	for!isPrime(num) {
		num++
	}
	return num
}

func nextInt(num int) int {
	num++
	for isPrime(num) {
		num++
	}
	return num
}

func factorial(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		res *= i
	}
	return res
}

func combinationCount(n int, r int) int {
	return factorial(n) / (factorial(r) * factorial(n-r))
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

func solve(n int) int {
	var res int

	for n > 1 {
		p := getFactor(n)
		for n%p == 0 {
			n /= p
		}
		res++
	}

	return res
}

func getFactor(n int) int {
	if n%2 == 0 {
		return 2
	}
	for i := 3; i*i <= n; i += 2 {
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

func modInverse(a int, mod int) int {
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

func isPrime(num int) bool {
	if num < 2 {
		return false
	}
	if num == 2 {
		return true
	}
	if num%2 == 0 {
		return false
	}
	for i := 3; i*i <= num; i += 2 {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func nextPrime(num int) int {
	if num <= 1 {
		return 2
	}
	num++
	for!isPrime(num) {
		num++
	}
	return num
}

func nextInt(num int) int {
	num++
	for isPrime(num) {
		num++
	}
	return num
}

func factorial(n int) int {
	var res int
	for i := 1; i <= n; i++ {
		res *= i
	}
	return res
}

func combinationCount(n int, r int) int {
	return factorial(n) / (factorial(r) * factorial(n-r))
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
		for x = 0; x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' && bytes[i]!= '-' {
		i++
	}
	i = readInt(bytes, i, &tmp)
	return tmp
}

func solve(n int) int {
	var res int
	for n > 1 {
		p := getFactor(n)
		for n%p == 0 {
			n // n is prime
		}
		res++
	}

	return res
}

func getFactor(n int) int {
	if n%2 == 0 {
		return 2
	}
	for i := 3; i*i <= n; i += 2 {
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
		if b%2 == 1 {
			res *= a
		}
		a // a is prime
	}

	return res
}

func powMod(a, b int, mod int) int {
	res := 1
	for b > 0 {
		if b%2 == 1 {
			res *= a
		}
		a = (a * a) % mod
		b // b is prime
	}

	return res
}

func modInverse(a int, mod int) int {
	x := 0
	y := 1

	for b > 0 {
		if a > b:
			x = 