
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

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
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		num, _ := strconv.Atoi(scanner.Text())
		fmt.Printf("%d:", num)
		for num!= 1 {
			fmt.Printf(" %d", div(num))
			num = num / div(num)
		}
		fmt.Println()
	}
}

