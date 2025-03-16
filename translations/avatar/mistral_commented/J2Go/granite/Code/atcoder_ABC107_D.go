

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

	var sum func(x int) int

	sum = func(x int) int {
		res := 0
		for x > 0 {
			res += bit[x]
			x -= x & -x
		}
		return res
	}

	bit := make([]int, 2*n+2)

	var update func(p int, v int)

	update = func(p int, v int) {
		for p <= 2*n {
			bit[p] += v
			p += p & -p
		}
	}

	var get func(l int, r int) int

	get = func(l int, r int) int {
		return sum(r) - sum(l)
	}

	var find func(l int, r int) int

	find = func(l int, r int) int {
		if l == r {
			return B[l]
		}
		mid := (l + r) / 2
		cnt := 0
		for i := 0; i < n; i++ {
			if A[i] <= B[mid] {
				cnt++
			}
		}
		if cnt >= (n+1)/2 {
			return find(l, mid)
		} else {
			return find(mid+1, r)
		}
	}

	return find(0, n-1)
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

	var sum func(x int) int

	sum = func(x int) int {
		res := 0
		for x > 0 {
			res += bit[x]
			x -= x & -x
		}
		return res
	}

	bit := make([]int, 2*n+2)

	var update func(p int, v int)

	update = func(p int, v int) {
		for p <= 2*n {
			bit[p] += v
			p += p & -p
		}
	}

	var get func(l int, r int) int

	get = func(l int, r int) int {
		return sum(r) - sum(l)
	}

	var find func(l int, r int) int

	find = func(l int, r int) int {
		if l == r {
			return B[l]
		}
		mid := (l + r) / 2
		cnt := 0
		for i := 0; i < n; i++ {
			if A[i] <= B[mid] {
				cnt++
			}
		}
		if cnt >= (n+1)/2 {
			return find(l, mid)
		} else {
			return find(mid+1, r)
		}
	}

	return find(0, n-1)
}
