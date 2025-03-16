package main

import (
	"fmt"
	"strconv"
)

func main() {
	for {
		var str string
		fmt.Scan(&str)

		if str == "0" {
			break
		}

		sum := 0

		for _, char := range str {
			num, _ := strconv.Atoi(string(char))
			sum += num
		}

		fmt.Println(sum)
	}
}

