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
	n, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}
	return n
}

func readInts() []int {
	sc.Scan()
	ss := sc.Text()
	ss = strings.ReplaceAll(ss, " ", "")
	ss = strings.ReplaceAll(ss, "\t", "")
	ss = strings.ReplaceAll(ss, "\n", "")
	var nums []int
	for _, s := range ss {
		num, err := strconv.Atoi(string(s))
		if err != nil {
			panic(err)
		}
		nums = append(nums, num)
	}
	return nums
}

func main() {
	sc.Split(bufio.ScanWords)
	a := readInt()
	b := readInt()

	if a > 0 {
		fmt.Println("Positive")
	} else if a <= 0 && b >= 0 {
		fmt.Println("Zero")
	} else {
		if (a + b) % 2 == 0 {
			fmt.Println("Negative")
		} else {
			fmt.Println("Positive")
		}
	}
}
