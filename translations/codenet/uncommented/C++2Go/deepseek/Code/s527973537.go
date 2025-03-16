package main

import (
	"fmt"
	"strconv"
)

func main() {
	var N string
	fmt.Scan(&N)
	S := 0
	for _, char := range N {
		S += int(char - '0')
	}
	if num, _ := strconv.Atoi(N); num%S == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

