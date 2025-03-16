
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
		n, k := readTwoNums(reader)
		A := readNNums(reader, n)
		res := solve(n, k, A)
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

func solve(n int, k int64, A []int) int64 {
	sort.Ints(A)

	var l, r int64

	for i := 0; i < n; i++ {
		if A[i] < 0 {
			l = max(l, -A[i])
		} else {
			r = max(r, int64(A[i]))
		}
	}

	for l < r {
		mid := (l + r) / 2
		cnt := count(A, mid)
		if cnt < k {
			r = mid
		} else {
			l = mid + 1
		}
	}

	return l
}

func count(A []int, mid int64) int64 {
	var res int64

	for i := 0; i < len(A); i++ {
		if A[i] >= 0 {
			x := search(A, i+1, len(A), func(x int) bool {
				return int64(A[i])*int64(A[x]) >= mid
			})
			res += int64(x - i - 1)
		} else {
			x := search(A, 0, i, func(x int) bool {
				return int64(A[i])*int64(A[x]) < mid
			})
			res += int64(i - x)
		}
	}

	return res / 2
}

func search(nums []int, l, r func(int) bool) int {
	for l < r {
		mid := l + (r-l)/2
		if!r(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return r
}

func max(a, b int64) int64 {
	if a >= b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a <= b {
		return a
	}
	return b
}