package main

import (
	"fmt"
	"strconv"
)

func main() {
	var a int64
	var b string
	fmt.Scan(&a, &b)
	bChars := []rune(b)
	length := len(bChars)
	bStr := ""
	for i := 0; i < length; i++ {
		if bChars[i] != '.' {
			bStr += string(bChars[i])
		}
	}
	bInt, _ := strconv.Atoi(bStr)
	result := (a * int64(bInt)) / 100
	fmt.Println(result)
}

