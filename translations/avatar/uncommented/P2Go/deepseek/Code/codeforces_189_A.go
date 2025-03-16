package main

import (
	"fmt"
	"sort"
)

func cutRibbon() {
	var arr [4]int
	fmt.Scan(&arr[0], &arr[1], &arr[2], &arr[3])
	length := arr[0]
	sort.Slice(arr[1:4], func(i, j int) bool {
		return arr[i+1] < arr[j+1]
	})
	if length%arr[0] == 0 {
		fmt.Println(length / arr[0])
		return
	}
	ans := 0
	if arr[0] == arr[1] {
		k := 0
		for i := 0; i <= length/arr[2]; i++ {
			check := length - i*arr[2]
			if check >= 0 && check%arr[0] == 0 {
				k = check / arr[0]
				if k+i > ans {
					ans = k + i
				}
			}
		}
	} else {
		k := 0
		for i := 0; i <= length/arr[2]; i++ {
			for j := 0; j <= length/arr[1]; j++ {
				check := length - i*arr[2] - j*arr[1]
				if check >= 0 && check%arr[0] == 0 {
					k = check / arr[0]
					if k+i+j > ans {
						ans = k + i + j
					}
				}
			}
		}
	}
	fmt.Println(ans)
}

func main() {
	cutRibbon()
}

