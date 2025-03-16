package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func S() string {
	sc.Scan()
	return sc.Text()
}

func I() int {
	num, _ := strconv.Atoi(S())
	return num
}

func LI() []int {
	strs := S()
	nums := []int{}
	for _, str := range strs {
		num, _ := strconv.Atoi(str)
		nums = append(nums, num)
	}
	return nums
}

func LS() []string {
	return strings.Split(S(), " ")
}

func main() {
	sc.Split(bufio.ScanWords)
	a, b := I(), I()

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
