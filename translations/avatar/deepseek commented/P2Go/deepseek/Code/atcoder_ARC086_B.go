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

func readInt() int {
	sc.Scan()
	num, _ := strconv.Atoi(sc.Text())
	return num
}

func readInts() []int {
	sc.Scan()
	nums := make([]int, 0)
	for _, s := range strings.Split(sc.Text(), " ") {
		num, _ := strconv.Atoi(s)
		nums = append(nums, num)
	}
	return nums
}

func readLine() string {
	sc.Scan()
	return sc.Text()
}

func mySign(x int) int {
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
	
	// Find the element with the maximum absolute value
	for i := 0; i < N; i++ {
		if math.Abs(float64(a[i])) > float64(maxVal) {
			maxVal = int(math.Abs(float64(a[i])))
			maxSign = mySign(a[i])
			maxIndex = i
		}
	}
	
	// If the maximum value is zero, print 0
	if maxSign == 0 {
		fmt.Println(0)
	// If the maximum value is positive, print the sequence of operations
	} else if maxSign == 1 {
		fmt.Println(2*N - 1)
		for i := 0; i < N; i++ {
			fmt.Println(maxIndex + 1, i + 1) // Print the swap operations
		}
		for i := 0; i < N - 1; i++ {
			fmt.Println(i + 1, i + 2) // Print the increment operations
		}
	// If the maximum value is negative, print the sequence of operations in reverse
	} else {
		fmt.Println(2*N - 1)
		for i := 0; i < N; i++ {
			fmt.Println(maxIndex + 1, i + 1) // Print the swap operations
		}
		for i := N - 2; i >= 0; i-- {
			fmt.Println(i + 2, i + 1) // Print the decrement operations in reverse
		}
	}
}
