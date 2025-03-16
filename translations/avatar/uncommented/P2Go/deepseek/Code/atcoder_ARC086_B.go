package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const mod = 1000000007

func input() string {
	reader := bufio.NewReader(os.Stdin)
	buf, _ := reader.ReadString('\n')
	return strings.TrimRight(buf, "\r\n")
}

func I() int {
	i, _ := strconv.Atoi(input())
	return i
}

func II() []int {
	parts := strings.Split(input(), " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

func III() []int {
	parts := strings.Split(input(), " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

func Line(N int, num int) [][]int {
	if N <= 0 {
		return make([][]int, num)
	} else if num == 1 {
		arr := make([]int, N)
		for i := 0; i < N; i++ {
			arr[i] = I()
		}
		return [][]int{arr}
	} else {
		readAll := make([][]int, N)
		for i := 0; i < N; i++ {
			readAll[i] = II()
		}
		transposed := make([][]int, len(readAll[0]))
		for _, row := range readAll {
			for j, val := range row {
				if j >= len(transposed) {
					transposed = append(transposed, []int{})
				}
				transposed[j] = append(transposed[j], val)
			}
		}
		return transposed
	}
}

func mySign(x int) int {
	if x > 0 {
		return 1
	}
	return -1
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	N := I()
	a := III()
	maxVal := 0
	maxSign := 0
	maxIndex := -1
	for i, a0 := range a {
		if abs(a0) > maxVal {
			maxVal = abs(a0)
			maxSign = mySign(a0)
			maxIndex = i
		}
	}

	if maxSign == 0 {
		fmt.Fprintln(writer, 0)
	} else if maxSign == 1 {
		fmt.Fprintln(writer, 2*N-1)
		for i := 0; i < N; i++ {
			fmt.Fprintln(writer, maxIndex+1, i+1)
		}
		for i := 0; i < N-1; i++ {
			fmt.Fprintln(writer, i+1, i+2)
		}
	} else {
		fmt.Fprintln(writer, 2*N-1)
		for i := 0; i < N; i++ {
			fmt.Fprintln(writer, maxIndex+1, i+1)
		}
		for i := N - 1; i > 0; i-- {
			fmt.Fprintln(writer, i+1, i)
		}
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

