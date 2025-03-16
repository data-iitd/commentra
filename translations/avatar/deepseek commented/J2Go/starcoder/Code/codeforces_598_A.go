package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var q int
	fmt.Scanf("%d", &q)
	for i := 0; i < q; i++ {
		var n int
		fmt.Scanf("%d", &n)
		x := int(math.Log(float64(n)) / math.Log(2))
		x++
		s := -1*int64(math.Pow(2, float64(x))) + 2 + int64(n*(n+1)/2) - int64(math.Pow(2, float64(x)))
		fmt.Println(s)
	}
}

