package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func readString() string {
	sc.Scan()
	return sc.Text()
}

func readInt() int {
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

func readLineInts() []int {
	sc.Scan()
	words := sc.Text()
	nums := []int{}
	for _, w := range words {
		n, _ := strconv.Atoi(string(w))
		nums = append(nums, n)
	}
	return nums
}

func main() {
	sc.Split(bufio.ScanWords)
	a, b := readInt(), readInt()
	if a > 0 {
		fmt.Println("Positive")
	} else if a <= 0 && b >= 0 {
		fmt.Println("Zero")
	} else {
		if (a+b)%2 == 0 {
			fmt.Println("Negative")
		} else {
			fmt.Println("Positive")
		}
	}
}

