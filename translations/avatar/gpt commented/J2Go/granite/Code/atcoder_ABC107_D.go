
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
	var buf bytes.Buffer
	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNNums(reader, n)
		res := solve(A)
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

func solve(A []int) int {
	n := len(A)
	B := make([]int, n)
	copy(B, A)
	sort.Ints(B)

	var find func(x int) int

	find = func(x int) int {
		left, right := 0, n-1

		for left < right {
			mid := (left + right) / 2
			if B[mid] < x {
				left = mid + 1
			} else {
				right = mid
			}
		}

		return left
	}

	var count func(x int) int64

	count = func(x int) int64 {
		var res int64

		cur := 0
		bit := make([]int, n+1)

		for i := 0; i < n; i++ {
			cur += int(A[i] <= x)
			for cur > 0 {
				res += int64(bit[cur])
				cur -= cur & -cur
			}
			bit[cur+1]++
		}

		return res
	}

	left, right := 0, n-1

	for left < right {
		mid := (left + right) / 2
		if count(B[mid]) >= int64(n)*(n+1)/4 {
			right = mid
		} else {
			left = mid + 1
		}
	}

	return B[left]
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

func maxInt(a...int) int {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minInt(a...int) int {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func max64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func min64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func pow(a, b int) int {
	res := 1
	for i := 0; i < b; i++ {
		res *= a
	}
	return res
}

func powMod(a, b, mod int) int {
	res := 1
	for i := 0; i < b; i++ {
		res = (res * a) % mod
	}
	return res
}

func modInverse(a, m int) int {
	g := gcd(a, m)
	if g!= 1 {
		panic("mod inverse does not exist")
	} else {
		if a > 0 {
			return powMod(a, m-2, m)
		} else {
			return powMod(-a, m-2, m)
		}
	}
}

func gcd(a, b int) int {
	for b > 0 {
		a, b = b, a%b
	}
	return a
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

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	res, err := strconv.Atoi(sc.Text())
	if err!= nil {
		panic(err)
	}
	return res
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func minInt64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxInt64(a...int64) int64 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func minInt32(a...int32) int32 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] < res {
			res = a[i]
		}
	}
	return res
}

func maxInt32(a...int32) int32 {
	res := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > res {
			res = a[i]
		}
	}
	return res
}

func sortInt64(arr []int64) []int64 {
	return sort.Int64s(arr)
}

func readInt64(bytes []byte, from int, val *int64) int {
	i := from
	var sign int64 = 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	var tmp int64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int64(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
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

func readInt32(bytes []byte, from int, val *int32) int {
	i := from
	var sign int32 = 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	var tmp int32
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int32(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readUint32(bytes []byte, from int, val *uint32) int {
	i := from

	var tmp uint32
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint32(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readInt16(bytes []byte, from int, val *int16) int {
	i := from
	var sign int16 = 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	var tmp int16
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int16(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readUint16(bytes []byte, from int, val *uint16) int {
	i := from

	var tmp uint16
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint16(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readInt8(bytes []byte, from int, val *int8) int {
	i := from
	var sign int8 = 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	var tmp int8
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int8(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readUint8(bytes []byte, from int, val *uint8) int {
	i := from

	var tmp uint8
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint8(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func readIntN(reader *bufio.Reader, n int) []int {
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

func main() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)
	var buf bytes.Buffer
	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNNums(reader, n)
		res := solve(A)
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

func solve(A []int) int {
	n := len(A)
	B := make([]int, n)
	copy(B, A)
	sort.Ints(B)

	var find func(x int) int

	find = func(x int) int {
		left, right := 0, n-1

		for left < right {
			mid := (left + right) / 2
			if B[mid] < x {
				left = mid + 1
			} else {
				right = mid
			}
		}

		return left
	}

	var count func(x int) int64

	count = func(x int) int64 {
		var res int64
		cur := 0
		bit := make([]int, n+1)

		for i := 0; i < n; i++ {
			cur += int(A[i] <= x)
			for cur > 0 {
				res += int64(bit[cur])
				cur -= cur & -cur
			}
			bit[cur+1]++
		}

		return res
	}

	left, right := 0, n-1

	for left < right {
		mid := (left + right) / 2
		if count(B[mid]) >= int64(n)*(n+1)/4 {
			right = mid
		} else {
			left = mid + 1
		}
	}

	for left < right {
		mid := (left + right) / 2
		if count(B[mid]) >= int64(n)*(n+1)/4 {
			right = mid
		} else {
			left = mid + 1
		}
	}

	for left < right {
		mid := (left + right) / 2
		if count(B[mid]) >= int64(n)*(n+1)/4 {
			right = mid
		} else {
			left = mid + 1
		}
	}

	for left < right {
		mid := (left + right) / 2
		if count(B[mid]) >= int64(n)*(n+1)/4 {
			right = mid
		} else {
			left = mid + 1
		}
	}

	for left < right {
		mid := (left + right) / 2
		if count(B[mid]) >= int64(n)*(n+1)/4 {
			right = mid
		} else {
			left = mid + 1
		}
	}

	for left < right {
		mid := (left + right) / 2
		if count(B[mid]) >= int64(n)*(n+1)/4 {
			right = mid
		} else {
			left = mid + 1
		}
	}

	for left < right {
		mid := (left + right) / 2
		if count(B[mid]) >= int64(n)*(n+1)/4 {
			right = mid
		} else {
			left = mid + 1
		}
	}

	for left < right {
		mid := (left + right) / 2
		if count(B[mid]) >= int64(n)*(n+1)/4 {
			right = mid
		} else {
			left = mid + 1
		}
	}

	for left < right {
		mid := (left + right) / 2
		if count(B[mid]) >= int64(n)*(n+1)/4 {
			right = mid
		