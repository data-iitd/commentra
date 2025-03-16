package main

import (
	"fmt"
	"strconv"
)

func main() {
	var x [1002]string
	var sum int
	var flag int

	for {
		fmt.Scanln(&x[0])
		if x[0] == "0" {
			break
		}
		sum = 0
		for i := 0; i < len(x[0]); i++ {
			digit, _ := strconv.Atoi(string(x[0][i]))
			sum += digit
		}
		fmt.Println(sum)
	}
}

