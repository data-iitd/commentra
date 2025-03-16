package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N string
	fmt.Scan(&N)
	S := 0
	for i := 0; i < len(N); i++ {
		S += int(N[i] - '0')
	}
	if stoi(N)%S == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

func stoi(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

