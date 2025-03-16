package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var soz string
	fmt.Scan(&soz)

	a := make([]int, len(soz)+1)
	for i := 1; i < len(soz); i++ {
		a[i] = a[i-1]
		if soz[i-1] == soz[i] {
			a[i]++
		}
	}

	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		var input string
		fmt.Scan(&input)
		mL := strings.Split(input, " ")
		m, _ := strconv.Atoi(mL[0])
		l, _ := strconv.Atoi(mL[1])
		arr[i] = a[l-1] - a[m-1]
	}

	for _, value := range arr {
		fmt.Println(value)
	}
}

// <END-OF-CODE>
