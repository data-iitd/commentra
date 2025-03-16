
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
		X, Y, Z, K := readFourNums(reader)
		A := readNNums(reader, X)
		B := readNNums(reader, Y)
		C := readNNums(reader, Z)
		res := solve(X, Y, Z, K, A, B, C)
		for i := 0; i < K; i++ {
			buf.WriteString(fmt.Sprintf("%d\n", res[i]))
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

func readFourNums(reader *bufio.Reader) (a int, b int, c int, d int) {
	res := readNNums(reader, 4)
	a, b, c, d = res[0], res[1], res[2], res[3]
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

func solve(X, Y, Z, K int, A []int, B []int, C []int) []int {
	sort.Slice(A, func(i, j int) bool {
		return A[i] > A[j]
	})

	sort.Slice(B, func(i, j int) bool {
		return B[i] > B[j]
	})

	sort.Slice(C, func(i, j int) bool {
		return C[i] > C[j]
	})

	var res []int

	for i := 0; i < X && i < K; i++ {
		for j := 0; j < Y && i+j < K; j++ {
			res = append(res, A[i]+B[j])
		}
	}

	sort.Slice(res, func(i, j int) bool {
		return res[i] > res[j]
	})

	var tmp []int

	for i := 0; i < min(K, len(res)); i++ {
		for j := 0; j < Z && i+j < K; j++ {
			tmp = append(tmp, res[i]+C[j])
		}
	}

	sort.Slice(tmp, func(i, j int) bool {
		return tmp[i] > tmp[j]
	})

	return tmp[:K]
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}