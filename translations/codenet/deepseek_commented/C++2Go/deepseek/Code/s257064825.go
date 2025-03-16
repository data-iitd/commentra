package main

import (
	"fmt"
	"strconv"
)

func main() {
	var str string
	fmt.Scan(&str)
	var sum int
	for _, x := range str {
		digit, _ := strconv.Atoi(string(x))
		sum += digit
	}
	if sum%9 == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
