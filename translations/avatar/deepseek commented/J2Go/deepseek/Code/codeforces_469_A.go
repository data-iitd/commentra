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
	n := parseInt(scanner.Text())
	scanner.Scan()
	levels := parseInt(scanner.Text())

	arr := make([]int, levels)
	for i := 0; i < levels; i++ {
		scanner.Scan()
		arr[i] = parseInt(scanner.Text())
	}

	scanner.Scan()
	level2 := parseInt(scanner.Text())
	level3 := levels + level2
	arr2 := make([]int, level3)

	copy(arr2, arr)
	for i := levels; i < level3; i++ {
		scanner.Scan()
		arr2[i] = parseInt(scanner.Text())
	}

	arr3 := make([]int, n)
	for i := 0; i < n; i++ {
		arr3[i] = i + 1
	}

	count := 0
	for i := 0; i < n; i++ {
		for x := 0; x < len(arr2); x++ {
			if arr3[i] == arr2[x] {
				count++
				break
			}
		}
	}

	if count == n {
		fmt.Println("I become the guy.")
	} else {
		fmt.Println("Oh, my keyboard!")
	}
}

func parseInt(s string) int {
	var res int
	for i := 0; i < len(s); i++ {
		res = res*10 + int(s[i]-'0')
	}
	return res
}

