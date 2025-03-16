package main

import (
	"fmt"
	"strconv"
)

func main() {
	const INF = 1e15
	var number string
	fmt.Scan(&number)
	digits := make([]int, len(number)+1)
	for i := 0; i < len(number); i++ {
		digits[i] = int(number[len(number)-1-i] - '0')
	}
	bills := 0
	for i := 0; i <= len(number); i++ {
		if digits[i] == 10 {
			digits[i+1]++
			digits[i] = 0
		}
		if digits[i] < 5 {
			bills += digits[i]
		} else if digits[i] == 5 {
			if i+1 < len(number) && digits[i+1] >= 5 {
				digits[i+1]++
			}
			bills += 5
		} else {
			digits[i+1]++
			bills += 10 - digits[i]
		}
	}
	fmt.Println(bills)
}

