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
	tc, _ := strconv.Atoi(reader.ReadString('\n'))
	for i := 0; i < tc; i++ {
		fmt.Println("Enter the number of digits")
		n, _ := strconv.Atoi(reader.ReadString('\n'))
		fmt.Println("Enter the number")
		m, _ := strconv.Atoi(reader.ReadString('\n'))
		fmt.Println("The reverse of the number is", reverse(m), n)
	}
}

func reverse(n int) int {
	if n < 10 {
		return n * 10
	}
	t := n
	r := 0
	for t > 0 {
		r = (r * 10) + t%10
		t = t / 10
	}
	return r
}

