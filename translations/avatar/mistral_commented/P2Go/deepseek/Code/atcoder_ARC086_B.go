package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"math"
)

const mod = 1000000007

var scanner = bufio.NewScanner(os.Stdin)

func readInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readInts() []int {
	scanner.Scan()
	ints := []int{}
	for _, s := range strings.Split(scanner.Text(), " ") {
		num, _ := strconv.Atoi(s)
		ints = append(ints, num)
	}
	return ints
}

func main() {
	scanner.Split(bufio.ScanWords)
	N := readInt()
	a := readInts()
	maxVal := 0
	maxSign := 0
	maxIndex := -1

	for i, a0 := range a {
		if math.Abs(float64(a0)) > float64(maxVal) {
			maxVal = int(math.Abs(float64(a0)))
			maxSign = sign(a0)
			maxIndex = i
		}
	}

	if maxSign == 0 {
		fmt.Println(0)
	} else if maxSign == 1 {
		fmt.Println(2 * N - 1)
		fmt.Println(maxIndex + 1, 1)
		for i := 1; i < N; i++ {
			fmt.Println(i + 1, i)
		}
	} else {
		fmt.Println(2 * N - 1)
		fmt.Println(maxIndex + 1, 1)
		for i := N - 1; i > 0; i-- {
			fmt.Println(i + 1, i)
		}
	}
}

func sign(x int) int {
	if x > 0 {
		return 1
	} else if x < 0 {
		return -1
	} else {
		return 0
	}
}

