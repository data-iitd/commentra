
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Take an input from the user and store it in variable 'a'
	var a string
	fmt.Scanln(&a)

	// Print the result based on the input
	if strings.Count(a, "1") == 0 {
		fmt.Println(0)
	} else {
		var result int = 1
		for _, v := range strings.Split(strings.Trim(a, "0"), "1") {
			result *= len(v) + 1
		}
		fmt.Println(result)
	}
}

