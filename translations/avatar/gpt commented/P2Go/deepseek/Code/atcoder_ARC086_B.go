package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"math"
)

const mod = 1000000007

var sc = bufio.NewScanner(os.Stdin)

func readLine() string {
	sc.Scan()
	return sc.Text()
}

func readInt() int {
	num, _ := strconv.Atoi(readLine())
	return num
}

func readInts() []int {
	parts := readLine()
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(string(part))
	}
	return ints
}

func readLines(N int) [][]int {
	lines := make([][]int, N)
	for i := 0; i < N; i++ {
		lines[i] = readInts()
	}
	return lines
}

func sign(x int) int {
	if x > 0 {
		return 1
	}
	return -1
}

func main() {
	sc.Split(bufio.ScanWords)
	
	N := readInt()
	a := readInts()
	
	maxVal := 0
	maxSign := 0
	maxIndex := -1
	
	for i, a0 := range a {
		if int(math.Abs(float64(a0))) > maxVal {
			maxVal = int(math.Abs(float64(a0)))
			maxSign = sign(a0)
			maxIndex = i
		}
	}
	
	if maxSign == 0 {
		fmt.Println(0)
	} else if maxSign == 1 {
		fmt.Println(2 * N - 1)
		for i := 0; i < N; i++ {
			fmt.Println(maxIndex + 1, i + 1)
		}
		for i := 0; i < N - 1; i++ {
			fmt.Println(i + 1, i + 2)
		}
	} else {
		fmt.Println(2 * N - 1)
		for i := 0; i < N; i++ {
			fmt.Println(maxIndex + 1, i + 1)
		}
		for i := N - 1; i > 0; i-- {
			fmt.Println(i + 1, i)
		}
	}
}
