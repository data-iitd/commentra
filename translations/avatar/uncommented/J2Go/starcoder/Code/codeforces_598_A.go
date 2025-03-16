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
	for q > 0 {
		var n int
		fmt.Scanf("%d", &n)
		x := int(math.Log(float64(n)) / math.Log(2))
		x++
		s := -1*(int(math.Pow(2, float64(x)))) + 2 + (int(n)*(int(n)+1))/2 - (int(math.Pow(2, float64(x))))
		fmt.Println(s)
		q--
	}
}

