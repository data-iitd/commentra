

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, m := readTwoNums(reader)
	A := readNNums(reader, n)
	res := solve(n, m, A)
	fmt.Println(res)
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

func solve(n int, m int, A []int) int64 {
	var heap []int

	push := func(x int) {
		i := len(heap)
		heap = append(heap, x)
		for i > 0 {
			p := (i - 1) / 2
			if heap[p] >= x {
				break
			}
			heap[i] = heap[p]
			i = p
		}
		heap[i] = x
	}

	pop := func() int {
		ret := heap[0]
		x := heap[len(heap)-1]
		heap = heap[:len(heap)-1]
		i := 0
		for i*2 + 1 < len(heap) {
			a := i * 2 + 1
			b := i * 2 + 2
			if b < len(heap) && heap[b] > heap[a] {
				a = b
			}
			if heap[a] <= x {
				break
			}
			heap[i] = heap[a]
			i = a
		}
		heap[i] = x
		return ret
	}

	for i := 0; i < n; i++ {
		push(A[i])
	}

	for i := 0; i < m; i++ {
		x := pop()
		push(x / 2)
	}

	var res int64

	for i := 0; i < len(heap); i++ {
		res += int64(heap[i])
	}

	return res
}