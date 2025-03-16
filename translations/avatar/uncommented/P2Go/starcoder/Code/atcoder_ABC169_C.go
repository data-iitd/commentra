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
	fmt.Println("Enter the first number:")
	a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the second number:")
	b, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println(a * b / 100)
}
