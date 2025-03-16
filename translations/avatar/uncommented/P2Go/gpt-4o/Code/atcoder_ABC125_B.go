package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)

	VInput := ""
	fmt.Scan(&VInput)
	VStrings := strings.Split(VInput, " ")
	V := make([]int, N)
	for i := 0; i < N; i++ {
		V[i], _ = strconv.Atoi(VStrings[i])
	}

	CInput := ""
	fmt.Scan(&CInput)
	CStrings := strings.Split(CInput, " ")
	C := make([]int, N)
	for i := 0; i < N; i++ {
		C[i], _ = strconv.Atoi(CStrings[i])
	}

	list := []int{0}
	ans := 0
	X := 0
	Y := 0

	for i := 0; i < N; i++ {
		if V[i]-C[i] > 0 {
			X = V[i]
			Y = C[i]
			list = append(list, X-Y)
		}
	}

	sum := 0
	for _, value := range list {
		sum += value
	}

	fmt.Println(sum)
}

// <END-OF-CODE>
