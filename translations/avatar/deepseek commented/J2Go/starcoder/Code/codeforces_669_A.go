
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of test cases: ")
	tc, _ := strconv.Atoi(reader.ReadString('\n'))
	for i := 0; i < tc; i++ {
		fmt.Println("Enter the number: ")
		n, _ := strconv.Atoi(reader.ReadString('\n'))
		solve(n)
	}
}

func solve(n int) {
	// Calculating the result based on the given logic
	fmt.Println((n/3)*2 + (n%3 == 0? 0 : 1))
}

