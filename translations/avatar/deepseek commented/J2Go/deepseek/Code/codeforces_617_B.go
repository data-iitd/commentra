package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := 0
	fmt.Sscan(scanner.Text(), &n)

	arr := []int{}

	for i := 0; i < n; i++ {
		scanner.Scan()
		num := 0
		fmt.Sscan(scanner.Text(), &num)
		if num == 1 {
			arr = append(arr, i)
		}
	}

	if len(arr) == 0 {
		fmt.Println(0)
	} else {
		result := 1
		for i := 1; i < len(arr); i++ {
			result *= arr[i] - arr[i-1]
		}
		fmt.Println(result)
	}
}
