
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

type BIT struct {
	size int
	tree []int
}

func (bit *BIT) _bitsum(i int) int {
	ret := 0
	for i > 0 {
		ret += bit.tree[i]
		i -= i & -i
	}
	return ret
}

func (bit *BIT) bitsum(l, r int) int {
	if r < 0 {
		r = bit.size
	}
	return bit._bitsum(r) - bit._bitsum(l)
}

func (bit *BIT) bitadd(i, x int) {
	i++
	for i <= bit.size {
		bit.tree[i] += x
		i += i & -i
	}
}

func main() {
	const MOD = 100000007

	scan := bufio.NewScanner(os.Stdin)
	scan.Buffer([]byte{}, 1000000)
	scan.Split(bufio.ScanWords)

	n := nextInt(scan)
	m := n * (n + 1) / 4
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = nextInt(scan)
	}

	var _a []int
	for _, x := range a {
		_a = append(_a, x)
	}
	_a = append(_a, 0)
	sort.Ints(_a)
	_a = _a[:len(set(_a))]

	d := make(map[int]int)
	for i, x := range _a {
		d[x] = i
	}
	for i, x := range a {
		a[i] = d[x]
	}

	check := func(x int) bool {
		b := make([]int, n+1)
		for i, y := range a {
			if y >= x {
				b[i] = 2
			} else {
				b[i] = -1
			}
		}
		for i := 1; i <= n; i++ {
			b[i] += b[i-1]
		}
		c := min(b...)
		b = make([]int, n+1)
		for i, y := range b {
			b[i] = y - c + 1
		}
		bit := &BIT{size: max(b...), tree: make([]int, bitSize(bit.size))}
		ans := 0
		for _, y := range b {
			ans += bit.bitsum(y, bit.size)
			bit.bitadd(y, 1)
		}
		return ans >= m
	}

	lo, hi := 0, len(_a)
	for lo < hi {
		mid := (lo + hi) / 2
		if check(mid) {
			hi = mid
		} else {
			lo = mid + 1
		}
	}
	fmt.Println(_a[lo])
}

func nextInt(scan *bufio.Scanner) int {
	scan.Scan()
	i, _ := strconv.Atoi(scan.Text())
	return i
}

func set(a []int) []int {
	var b []int
	set := make(map[int]bool)
	for _, x := range a {
		if!set[x] {
			set[x] = true
			b = append(b, x)
		}
	}
	return b
}

func min(a...int) int {
	m := a[0]
	for _, x := range a {
		if m > x {
			m = x
		}
	}
	return m
}

func max(a...int) int {
	m := a[0]
	for _, x := range a {
		if m < x {
			m = x
		}
	}
	return m
}

func bitSize(n int) int {
	m := 1
	for m < n {
		m *= 2
	}
	return m
}

func readInt(buf []byte, i int) int {
	idx := 0
	x := 0
	for i < len(buf) && buf[i]!='' {
		idx = idx*10 + int(buf[i]-'0')
		i++
	}
	return idx
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	x := 0
	for i := 0; i < len(bs); i++ {
		if bs[i] == '\n' {
			break
		}
		x = x*10 + int(bs[i]-'0')
	}
	return x
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
		x = readInt(bs, x)
		res[i] = x
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

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNNums(reader, n)
		res := solve(n, A)
		fmt.Println(res)
	}
}

func solve(n int, A []int) int {
	B := make([]int, n+1)
	for i := 0; i < n; i++ {
		if A[i] >= 0 {
			B[i] = 2
		} else {
			B[i] = -1
		}
	}
	B[n] = 0

	for i := 1; i <= n; i++ {
		B[i] += B[i-1]
	}

	c := min(B...)
	B = make([]int, n+1)
	for i := 0; i <= n; i++ {
		B[i] = B[i] - c + 1
	}

	bit := NewBIT(max(B...))

	var ans int

	for i := 0; i <= n; i++ {
		ans += bit.Sum(B[i])
		bit.Update(B[i], 1)
	}

	return ans
}

type BIT struct {
	arr []int
}

func NewBIT(n int) *BIT {
	arr := make([]int, n+1)
	return &BIT{arr}
}

func (bit *BIT) Update(num int, val int) {
	for num <= len(bit.arr) {
		bit.arr[num] += val
		num += num & -num
	}
}

func (bit *BIT) Sum(num int) int {
	var sum int
	for num > 0 {
		sum += bit.arr[num]
		num -= num & -num
	}
	return sum
}

func min(a...int) int {
	m := a[0]
	for _, x := range a {
		if m > x {
			m = x
		}
	}
	return m
}

func max(a...int) int {
	m := a[0]
	for _, x := range a {
		if m < x {
			m = x
		}
	}
	return m
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

func main() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNNums(reader, n)
		res := solve(n, A)
		fmt.Println(res)
	}
}

func solve(n int, A []int) int {
	B := make([]int, n+1)
	for i := 0; i < n; i++ {
		if A[i] >= 0 {
			B[i] = 2
		} else {
			B[i] = -1
		}
	}
	B[n] = 0

	for i := 1; i <= n; i++ {
		B[i] += B[i-1]
	}

	c := min(B...)
	B = make([]int, n+1)
	for i := 0; i <= n; i++ {
		B[i] = B[i] - c + 1
	}

	bit := NewBIT(max(B...))

	var ans int

	for i := 0; i <= n; i++ {
		ans += bit.Sum(B[i])
		bit.Update(B[i], 1)
	}

	return ans
}

type BIT struct {
	arr []int
}

func NewBIT(n int) *BIT {
	arr := make([]int, n+1)
	return &BIT{arr}
}

func (bit *BIT) Update(num int, val int) {
	for num <= len(bit.arr) {
		bit.arr[num] += val
		num += num & -num
	}
}

func (bit *BIT) Sum(num int) int {
	var sum int
	for num > 0 {
		sum += bit.arr[num]
		num -= num & -num
	}
	return sum
}

func min(a...int) int {
	m := a[0]
	for _, x := range a {
		if m > x {
			m = x
		}
	}
	return m
}

func max(a...int) int {
	m := a[0]
	for _, x := range a {
		if m < x {
			m = x
		}
	}
	return m
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