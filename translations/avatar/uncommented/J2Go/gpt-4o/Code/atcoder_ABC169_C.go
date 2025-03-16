package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var a int64
	var b string
	fmt.Scan(&a)
	fmt.Scan(&b)

	// Remove the '.' from the string
	bStr := strings.ReplaceAll(b, ".", "")

	// Convert the cleaned string to an integer
	bInt, err := strconv.Atoi(bStr)
	if err != nil {
		fmt.Println("Error converting string to integer:", err)
		return
	}

	// Calculate the result
	result := (a * int64(bInt)) / 100
	fmt.Println(result)
}

// <END-OF-CODE>
