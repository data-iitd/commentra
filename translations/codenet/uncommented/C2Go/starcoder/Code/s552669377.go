package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var i, n, tmp int
	var min, max, sum int64
	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &tmp)
		if min > tmp {
			min = tmp
		}
		if max < tmp {
			max = tmp
		}
		sum += tmp
	}
	fmt.Printf("%d %d %d\n", min, max, sum)
}

