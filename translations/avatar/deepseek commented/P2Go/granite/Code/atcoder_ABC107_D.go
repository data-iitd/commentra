
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
	depth int
}

func (bit *BIT) _bitsum(i int) int {
	ret := 0
	for i > 0 {
		ret += bit.tree[i]
		i ^= i & -i
	}
	return ret
}

func (bit *BIT) bitsum(l, r int) int {
	if r < 0 {
		r = 0
	}
	if r >= bit.size {
		r = bit.size - 1
	}
	if l > r {
		return 0
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
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	n := readNum(reader)
	m := n * (n + 1) / 4
	a := readNNums(reader, n)
	d := make(map[int]int)
	_a := make([]int, n)
	for i := 0; i < n; i++ {
		d[a[i]] = i
		_a[i] = a[i]
	}
	sort.Ints(_a)
	for i := 0; i < n; i++ {
		a[i] = d[_a[i]]
	}
	check := func(X int) bool {
		b := make([]int, n+1)
		for i := 0; i < n; i++ {
			if a[i] >= X {
				b[i+1]++
			}
		}
		for i := 1; i <= n; i++ {
			b[i] += b[i-1]
		}
		c := b[n]
		b = b[:n]
		for i := 0; i < n; i++ {
			b[i] -= c
		}
		bit := NewBIT(n+2)
		var ans int
		for i := 0; i < n; i++ {
			ans += bit.bitsum(b[i]+1, n+1)
			bit.bitadd(b[i], 1)
		}
		return ans >= m
	}
	l, r := 0, n
	for l < r {
		mid := (l + r) / 2
		if check(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	writer.WriteString(fmt.Sprintf("%d\n", _a[l]))
	writer.Flush()
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

func solve(n int, m int, a []int) int {
	d := make(map[int]int)
	_a := make([]int, n)
	for i := 0; i < n; i++ {
		d[a[i]] = i
		_a[i] = a[i]
	}
	sort.Ints(_a)
	for i := 0; i < n; i++ {
		a[i] = d[_a[i]]
	}
	check := func(X int) bool {
		b := make([]int, n+1)
		for i := 0; i < n; i++ {
			if a[i] >= X {
				b[i+1]++
			}
		}
		for i := 1; i <= n; i++ {
			b[i] += b[i-1]
		}
		c := b[n]
		b = b[:n]
		for i := 0; i < n; i++ {
			b[i] -= c
		}
		bit := NewBIT(n+2)
		var ans int
		for i := 0; i < n; i++ {
			ans += bit.bitsum(b[i]+1, n+1)
			bit.bitadd(b[i], 1)
		}
		return ans >= m
	}
	l, r := 0, n
	for l < r {
		mid := (l + r) / 2
		if check(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return _a[l]
}

type BIT struct {
	arr []int
}

func NewBIT(n int) *BIT {
	arr := make([]int, n)
	return &BIT{arr}
}

func (bit *BIT) bitsum(l, r int) int {
	r = min(r, len(bit.arr))
	if r < 0 {
		r = 0
	}
	if r >= len(bit.arr) {
		r = len(bit.arr) - 1
	}
	if l > r {
		return 0
	}
	return bit.query(r) - bit.query(l-1)
}

func (bit *BIT) query(x int) int {
	res := 0
	for x >= 0 {
		res += bit.arr[x]
		x = (x & (x + 1)) - 1
	}
	return res
}

func (bit *BIT) bitadd(x int, val int) {
	for x < len(bit.arr) {
		bit.arr[x] += val
		x |= (x + 1)
	}
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}