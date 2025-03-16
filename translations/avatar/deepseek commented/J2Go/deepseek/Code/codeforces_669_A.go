package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(input[:len(input)-1])
	solve(n)
}

func solve(n int) {
	result := (n / 3) * 2
	if n % 3 != 0 {
		result += 1
	}
	fmt.Println(result)
}

