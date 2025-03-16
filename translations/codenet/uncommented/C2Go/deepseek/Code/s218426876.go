package main

import (
	"fmt"
	"strconv"
)

func main() {
	var x string
	for {
		fmt.Scanln(&x)
		if x == "0" {
			break
		}
		sum := 0
		for _, char := range x {
			digit, _ := strconv.Atoi(string(char))
			sum += digit
		}
		fmt.Println(sum)
	}
}
