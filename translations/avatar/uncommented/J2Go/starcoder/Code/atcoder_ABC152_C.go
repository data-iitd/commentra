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
	fmt.Println(solve(reader))
}

func solve(reader *bufio.Reader) int {
	N, _ := strconv.Atoi(readLine(reader))
	arr := make([]int, N)
	for i := 0; i < N; i++ {
		arr[i], _ = strconv.Atoi(readLine(reader))
	}
	sum := 0
	q := make(Queue, 0)
	for i := 0; i < N; i++ {
		q = append(q, arr[i])
		if arr[i] <= q[0] {
			sum++
		}
	}
	return sum
}

func readLine(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

type Queue []int

func (q Queue) Len() int {
	return len(q)
}

func (q Queue) Less(i, j int) bool {
	return q[i] < q[j]
}

func (q Queue) Swap(i, j int) {
	q[i], q[j] = q[j], q[i]
}

func (q *Queue) Push(x interface{}) {
	*q = append(*q, x.(int))
}

func (q *Queue) Pop() interface{} {
	old := *q
	n := len(old)
	x := old[n-1]
	*q = old[0 : n-1]
	return x
}

