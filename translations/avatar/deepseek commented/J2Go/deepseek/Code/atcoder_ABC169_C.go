package main

import (
	"fmt"
	"strconv"
)

func main() {
	var a int64
	var b string
	fmt.Scan(&a, &b)

	bBytes := []byte(b)
	length := len(bBytes)
	var bStr string

	for i := 0; i < length; i++ {
		if bBytes[i] != '.' {
			bStr += string(bBytes[i])
		}
	}

	bInt, _ := strconv.Atoi(bStr)
	result := (a * int64(bInt)) / 100
	fmt.Println(result)
}

