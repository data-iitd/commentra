package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, k, q int
	fmt.Sscanf(strings.Join(os.Args[1:], " "), "%d%d%d", &n, &k, &q)
	arr := make([]int, n+1)
	for i := 0; i <= n; i++ {
		arr[i] = 0
	}
	for i := 0; i < q; i++ {
		var temp int
		fmt.Sscanf(strings.Join(os.Args[1:], " "), "%d", &temp)
		arr[temp] += 1
	}
	for i := 1; i <= n; i++ {
		if arr[i] > (q - k) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

