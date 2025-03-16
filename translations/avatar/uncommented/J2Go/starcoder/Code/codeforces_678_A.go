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
	fmt.Println("Enter the number of people")
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))
	fmt.Println("Enter the number of seats")
	input, _ = reader.ReadString('\n')
	k, _ := strconv.Atoi(strings.TrimSpace(input))
	n++
	z := 0
	if n%k!= 0 {
		z = k - n%k
	}
	fmt.Println(n + z)
}

