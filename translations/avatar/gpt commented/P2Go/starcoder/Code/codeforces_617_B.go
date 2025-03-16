package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var a string
	fmt.Fscan(os.Stdin, &a)
	fmt.Println(0)
	if strings.Count(a, "1") == 0 {
		return
	}
	fmt.Println(math.Prod(intSlice(strings.Split(strings.Trim(a, "0"), "1"))))
}

func intSlice(a []string) []int {
	b := make([]int, len(a))
	for i, v := range a {
		b[i], _ = strconv.Atoi(v)
	}
	return b
}

