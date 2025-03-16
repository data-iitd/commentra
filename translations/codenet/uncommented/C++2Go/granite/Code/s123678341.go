
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
	tc := 1
	for tc > 0 {
		tc--
		var x, y, z, k int
		fmt.Fscanf(reader, "%d %d %d %d\n", &x, &y, &z, &k)
		A := readNInt64s(reader, x)
		B := readNInt64s(reader, y)
		C := readNInt64s(reader, z)
		res := solve(x, y, z, k, A, B, C)
		for i := 0; i < k; i++ {
			fmt.Fprintf(&buf, "%d\n", res[i])
		}
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

func readInt64(bytes []byte, from int, val *int64) int {
	i := from
	var tmp int64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int64(bytes[i]-'0')
		i++
	}
	*val = tmp
	return i
}

func readNInt64s(reader *bufio.Reader, n int) []int64 {
	res := make([]int64, n)
	s, _ := reader.ReadBytes('\n')

	var pos int

	for i := 0; i < n; i++ {
		pos = readInt64(s, pos, &res[i])
	}

	return res
}

func readUint64s(reader *bufio.Reader, n int) []uint64 {
	res := make([]uint64, n)
	s, _ := reader.ReadBytes('\n')

	var pos int

	for i := 0; i < n; i++ {
		pos = readUint64(s, pos, &res[i])
	}

	return res
}

func solve(x, y, z, k int, A []int64, B []int64, C []int64) []int64 {
	sort.Slice(A, func(i, j int) bool {
		return A[i] > A[j]
	})

	sort.Slice(B, func(i, j int) bool {
		return B[i] > B[j]
	})

	sort.Slice(C, func(i, j int) bool {
		return C[i] > C[j]
	})

	var res []int64

	for i := 0; i < min(x, k); i++ {
		for j := 0; j < min(y, k); j++ {
			tmp := A[i] + B[j]
			pos := search(C, tmp)
			for pos < len(C) && len(res) < k {
				res = append(res, tmp+C[pos])
				pos++
			}
		}
	}

	sort.Slice(res, func(i, j int) bool {
		return res[i] > res[j]
	})

	return res[:k]
}

func search(nums []int64, target int64) int {
	l, r := 0, len(nums)-1

	for l <= r {
		mid := (l + r) / 2
		if nums[mid] >= target {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}

	return l
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}