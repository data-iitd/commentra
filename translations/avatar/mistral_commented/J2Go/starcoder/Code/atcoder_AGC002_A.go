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
	fmt.Print("Enter a: ")
	a, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Print("Enter b: ")
	b, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	if a > 0 {
		fmt.Println("Positive")
	} else if b >= 0 {
		fmt.Println("Zero")
	} else if (b-a+1)%2 == 0 {
		fmt.Println("Positive")
	} else {
		fmt.Println("Negative")
	}
}

