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
	k := parseInt64(scanner.Text())

	arr := make([]int64, n)
	set := make(map[int64]bool)

	for i := 0; i < n; i++ {
		scanner.Scan()
		arr[i] = parseInt64(scanner.Text())
	}

	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	count := 0

	for i := 0; i < n; i++ {
		if arr[i]%k != 0 {
			count++
			set[arr[i]] = true
		} else if !set[arr[i]/k] {
			count++
			set[arr[i]] = true
		}
	}

	fmt.Println(count)
}

func parseInt(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}

func parseInt64(s string) int64 {
	var res int64
	fmt.Sscanf(s, "%d", &res)
	return res
}

