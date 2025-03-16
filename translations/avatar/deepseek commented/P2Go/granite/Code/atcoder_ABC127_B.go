
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	r, D, x := readThreeIntegers()
	for i := 2; i <= 11; i++ {
		result := int((pow(r, i-1) * (x + D/(1-r))) - D/(1-r))
		fmt.Println(result)
	}
}

func readThreeIntegers() (int, int, int) {
	scanner := bufio.NewScanner(os.Stdin)
	var r, D, x int
	fmt.Scan(&r, &D, &x)
	return r, D, x
}

func pow(x, n int) int {
	result := 1
	for i := 0; i < n; i++ {
		result *= x
	}
	return result
}

