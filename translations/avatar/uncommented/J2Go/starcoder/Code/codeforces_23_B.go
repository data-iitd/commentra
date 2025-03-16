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
	fmt.Println("Enter the number of test cases")
	tc, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	for i := 0; i < tc; i++ {
		fmt.Println("Enter the number")
		n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		fmt.Println(maxLeft(n))
	}
}

func maxLeft(n int) int {
	if n > 2 {
		return n - 2
	}
	return 0
}

