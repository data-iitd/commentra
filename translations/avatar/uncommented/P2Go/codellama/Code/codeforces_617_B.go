package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	fmt.Print("Enter a string: ")
	var a string
	fmt.Scan(&a)
	fmt.Println(0, a.Count("1") == 0)
	fmt.Println(prod([]int{i.Count("0") + 1 for i in strings.Split(strings.TrimLeft(a, "0"), "1")}))
}

func prod(a []int) int {
	var result int = 1
	for _, v := range a {
		result *= v
	}
	return result
}

