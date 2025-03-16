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
		digit, _ := strconv.Atoi(string(N[i]))
		S += digit
	}
	num, _ := strconv.Atoi(N)
	if num%S == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

// <END-OF-CODE>
