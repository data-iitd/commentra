package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := parseInt(scanner.Text())
	scanner.Scan()
	k := parseInt(scanner.Text())
	arr := make([]int64, n)
	set := make(map[int64]bool)

	for i := 0; i < n; i++ {
		scanner.Scan()
		arr[i] = parseInt(scanner.Text())
	}

	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	count := 0

	for i := 0; i < n; i++ {
		if arr[i]%k != 0 {
			if !set[arr[i]] {
				count++
				set[arr[i]] = true
			}
		} else {
			quotient := arr[i] / k
			if !set[quotient] {
				count++
				set[quotient] = true
			}
		}
	}

	fmt.Println(count)
}

func parseInt(s string) int64 {
	var result int64
	for i := 0; i < len(s); i++ {
		result = result*10 + int64(s[i]-'0')
	}
	return result
}

