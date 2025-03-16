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
	fmt.Println("Enter A:")
	a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter B:")
	b, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	result := 0
	amari := 0
	result = (b - 1) / (a - 1)
	amari = (b - 1) % (a - 1)
	if amari!= 0 {
		result += 1
	}
	fmt.Println(result)
}

