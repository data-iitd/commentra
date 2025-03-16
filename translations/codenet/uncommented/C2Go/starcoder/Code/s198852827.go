package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	var t, x, y int
	var nx, ny, nt int
	var i, j, k, tmp int
	fmt.Scanf("%d", &N)
	for i = 0; i < N; i++ {
		fmt.Scanf("%d%d%d", &t, &x, &y)
		tmp = t - nt - (int(math.Abs(float64(x-nx))) + int(math.Abs(float64(y-ny))))
		if tmp < 0 || tmp%2!= 0 {
			fmt.Println("No")
			os.Exit(0)
		}
	}
	fmt.Println("Yes")
}

