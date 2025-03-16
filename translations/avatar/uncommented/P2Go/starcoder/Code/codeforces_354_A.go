package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

	n, L, R, QL, QR := readNum(reader), readNum(reader), readNum(reader), readNum(reader), readNum(reader)
	W := readNNums(reader, n)
	sum_el := make([]int, n+1)
	for i := 1; i <= n; i++ {
		sum_el[i] = W[i-1] + sum_el[i-1]
	}
	answer := QR * (n-1) + sum_el[n] * R
	for i := 1; i <= n; i++ {
		energy := L * sum_el[i] + R * (sum_el[n] - sum_el[i])
		if i > (n-i) {
			energy = energy + (i - (n-i)-1) * QL
		} else if (n-i) > i {
			energy = energy + ((n-i) - i - 1) * QR
		}
		if energy < answer {
			answer = energy
	}
	fmt.Println(answer)
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
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-':
			x++
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

func solve(n int, L, R, QL, QR int, W []int) int {
	sum_el := make([]int, n+1)
	for i := 1; i <= n; i++ {
		sum_el[i] = W[i-1] + sum_el[i-1]
	}
	answer := QR * (n-1) + sum_el[n] * R
	for i := 1; i <= n; i++ {
		energy := L * sum_el[i] + R * (sum_el[n] - sum_el[i])
		if i > (n-i) {
			energy = energy + (i - (n-i)-1) * QL
		} else if (n-i) > i {
			energy = energy + ((n-i) - i - 1) * QR
		}
		if energy < answer {
			answer = energy
	}
	return answer
}

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

	n, L, R, QL, QR := readNum(reader), readNum(reader), readNum(reader), readNum(reader), readNum(reader)
	W := readNNums(reader, n)
	fmt.Println(solve(n, L, R, QL, QR, W))
}

