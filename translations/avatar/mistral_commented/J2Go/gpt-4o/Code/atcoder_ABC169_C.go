package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var a int64 // Declaring and initializing long variable 'a'
	fmt.Scan(&a) // Reading long value from the console and assigning it to 'a'

	var b string // Declaring and initializing String variable 'b'
	fmt.Scan(&b) // Reading String value from the console and assigning it to 'b'

	bStr := strings.ReplaceAll(b, ".", "") // Removing '.' from the string 'b'
	bInt, err := strconv.Atoi(bStr) // Converting String 'bStr' to integer and assigning it to 'bInt'
	if err != nil {
		fmt.Println("Error converting string to integer:", err)
		return
	}

	result := (a * int64(bInt)) / 100 // Multiplying 'a' with 'bInt', then dividing the result by 100 and assigning it to 'result'

	fmt.Println(result) // Printing the value of 'result' to the console
}

// <END-OF-CODE>
