package main

import (
	"fmt"
	"sort"
)

func cutRibbon() {
	var length int
	var arr [3]int

	// Read input
	fmt.Scan(&length)
	for i := 0; i < 3; i++ {
		fmt.Scan(&arr[i])
	}

	// Sort the array
	sort.Ints(arr[:])

	if length%arr[0] == 0 {
		fmt.Println(length / arr[0])
		return
	}

	ans := 0
	if arr[0] == arr[1] {
		for i := 0; i <= length/arr[2]; i++ {
			check := length - i*arr[2]
			if check >= 0 && check%arr[0] == 0 {
				k := check / arr[0]
				ans = max(ans, k+i)
			}
		}
	} else {
		for i := 0; i <= length/arr[2]; i++ {
			for j := 0; j <= length/arr[1]; j++ {
				check := length - i*arr[2] - j*arr[1]
				if check >= 0 && check%arr[0] == 0 {
					k := check / arr[0]
					ans = max(ans, k+i+j)
				}
			}
		}
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	cutRibbon()
}

// <END-OF-CODE>
