
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Function to find the smallest divisor of a number
func div(n int) int {
	if n%2 == 0 {
		return 2
	}
	s := int(math.Sqrt(float64(n)))
	for i := 3; i <= s; i += 2 {
		if n%i == 0 {
			return i
		}
	}
	return n
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter an integer: ")
	text, _ := reader.ReadString('\n')
	num, _ := strconv.Atoi(text)
	fmt.Print(num, ":")
	for num!= 1 {
		fmt.Print(" ", div(num))
		num = num / div(num)
	}
	fmt.Println()
}

// 