package main

import (
	"fmt"
)

func main() {
	var sum int
	var x string

	for {
		fmt.Scan(&x)
		if x == "0" {
			break
		}

		sum = 0
		for i := 0; i < len(x); i++ {
			sum += int(x[i] - '0')
		}
		fmt.Println(sum)
	}
}

// <END-OF-CODE>
