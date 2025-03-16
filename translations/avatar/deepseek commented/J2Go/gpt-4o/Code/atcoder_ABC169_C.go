package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var a int64
	var b string

	// Reading input
	fmt.Scan(&a)
	fmt.Scan(&b)

	// Removing periods from the string 'b'
	bStr := strings.ReplaceAll(b, ".", "")

	// Parsing the filtered string as an integer
	bInt, err := strconv.Atoi(bStr)
	if err != nil {
		fmt.Println("Error parsing integer:", err)
		return
	}

	// Calculating the result
	result := (a * int64(bInt)) / 100

	// Printing the result
	fmt.Println(result)
}

// <END-OF-CODE>
