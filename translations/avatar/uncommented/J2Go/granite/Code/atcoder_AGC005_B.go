
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	a := readNInt64s(reader, n)
	leftl := make([]int, n)
	rightl := make([]int, n)
	que := make([]int, 0)
	index := 0
	for index < n {
		for len(que) > 0 && a[que[len(que)-1]] > a[index] {
			ind := que[len(que)-1]
			que = que[:len(que)-1]
			rightl[ind] = index - ind - 1
		}
		que = append(que, index)
		index++
	}
	for len(que) > 0 {
		ind := que[len(que)-1]
		que = que[:len(que)-1]
		rightl[ind] = n - ind - 1
	}
	index = n - 1
	for index >= 0 {
		for len(que) > 0 && a[que[len(que)-1]] > a[index] {
			ind := que[len(que)-1]
			que = que[:len(que)-1]
			leftl[ind] = ind - index - 1
		}
		que = append(que, index)
		index--
	}
	for len(que) > 0 {
		ind := que[len(que)-1]
		que = que[:len(que)-1]
		leftl[ind] = ind - index - 1
	}
	ans := int64(0)
	for i := 0; i < n; i++ {
		ans += (a[i] * int64(leftl[i]+1) * int64(rightl[i]+1))
	}
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
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

func main1() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNInt64s(reader, n)
		res := solve(n, A)
		fmt.Println(res)
	}
}

func solve(n int, A []int64) int64 {
	left := make([]int, n)
	right := make([]int, n)

	stack := make([]int, 0, n)

	for i := 0; i < n; i++ {
		for len(stack) > 0 && A[stack[len(stack)-1]] > A[i] {
			right[stack[len(stack)-1]] = i - stack[len(stack)-1] - 1
			stack = stack[:len(stack)-1]
		}
		stack = append(stack, i)
	}

	for len(stack) > 0 {
		right[stack[len(stack)-1]] = n - stack[len(stack)-1] - 1
		stack = stack[:len(stack)-1]
	}

	stack = make([]int, 0, n)

	for i := n - 1; i >= 0; i-- {
		for len(stack) > 0 && A[stack[len(stack)-1]] > A[i] {
			left[stack[len(stack)-1]] = stack[len(stack)-1] - i - 1
			stack = stack[:len(stack)-1]
		}
		stack = append(stack, i)
	}

	for len(stack) > 0 {
		left[stack[len(stack)-1]] = stack[len(stack)-1] - i - 1
		stack = stack[:len(stack)-1]
	}

	var res int64

	for i := 0; i < n; i++ {
		res += A[i] * int64(left[i]+1) * int64(right[i]+1)
	}

	return res
}

func main2() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n := readNum(reader)
		A := readNInt64s(reader, n)
		res := solve1(n, A)
		fmt.Println(res)
	}
}

func solve1(n int, A []int64) int64 {
	left := make([]int, n)
	right := make([]int, n)

	stack := make([]int, 0, n)

	for i := 0; i < n; i++ {
		for len(stack) > 0 && A[stack[len(stack)-1]] > A[i] {
			right[stack[len(stack)-1]] = i - stack[len(stack)-1] - 1
			stack = stack[:len(stack)-1]
		}
		stack = append(stack, i)
	}

	for len(stack) > 0 {
		right[stack[len(stack)-1]] = n - stack[len(stack)-1] - 1
		stack = stack[:len(stack)-1]
	}

	stack = make([]int, 0, n)

	for i := n - 1; i >= 0; i-- {
		for len(stack) > 0 && A[stack[len(stack)-1]] > A[i] {
			left[stack[len(stack)-1]] = stack[len(stack)-1] - i - 1
			stack = stack[:len(stack)-1]
		}
		stack = append(stack, i)
	}

	for len(stack) > 0 {
		left[stack[len(stack)-1]] = stack[len(stack)-1] - i - 1
		stack = stack[:len(stack)-1]
	}

	var res int64

	for i := 0; i < n; i++ {
		res += A[i] * int64(left[i]+1) * int64(right[i]+1)
	}

	return res
}
