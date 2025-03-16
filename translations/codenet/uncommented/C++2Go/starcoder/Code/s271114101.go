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
	fmt.Println("Enter three numbers:")
	a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	b, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	c, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println((a+b == c || b+c == a || a+c == b) && "Yes" || "No")
}

