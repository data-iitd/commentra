package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	a, b, c, d := readInts()
	fmt.Println(max(a * c, b * d, a * d, b * c))
}

func readInts() (int, int, int, int) {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)
	return a, b, c, d
}

func max(a, b, c, d int) int {
	return int(math.Max(math.Max(math.Max(float64(a), float64(b)), float64(c)), float64(d)))
}

