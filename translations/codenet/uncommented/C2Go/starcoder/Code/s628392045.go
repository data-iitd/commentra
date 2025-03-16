package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var i int
	var h [100001]int
	var max int = -1
	var flag int = 0

	fmt.Scanf("%d", &n)

	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &h[i])
		if max < h[i] {
			max = h[i]
		}

		if max-h[i] >= 2 {
			flag = 1
		}
	}

	if flag == 1 {
		fmt.Printf("No\n")
	} else {
		fmt.Printf("Yes\n")
	}
}

