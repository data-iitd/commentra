
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
	li := make([][]int, m)
	for i := 0; i < m; i++ {
		li[i] = readNNums(reader, n)
	}
	p := readNNums(reader, m)
	q, r, v := countSwitches(n, m, li, p)
	ans := countCombinations(q, r, v)
	fmt.Println(ans)
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

func countSwitches(n int, m int, li [][]int, p []int) (int, int, int) {
	q := make(map[int]bool)
	r := make(map[int]bool)
	v := make(map[int]bool)

	for i := 0; i < m; i++ {
		for j := 0; j < len(li[i]); j++ {
			q[li[i][j]] = true
		}
	}

	for i := 1; i <= n; i++ {
		if!q[i] {
			r[i] = true
		} else {
			v[i] = true
		}
	}

	var res int

	for i := 1; i <= n; i++ {
		if!q[i] {
			res++
		}
	}

	return len(q), len(r), res
}

func countCombinations(q int, r int, v int) int {
	var res int

	for i := 0; i <= q; i++ {
		tmp := 1
		for j := 0; j < i; j++ {
			tmp *= 2
		}
		for j := 0; j < v; j++ {
			tmp *= 2
		}
		res += tmp
	}

	return res
}

