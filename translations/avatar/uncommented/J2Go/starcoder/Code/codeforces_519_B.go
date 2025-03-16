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
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	a := 0
	b := 0
	c := 0
	for i := 0; i < n; i++ {
		fmt.Println("Enter the element")
		a += int(strings.TrimSpace(reader.ReadString()))
	}
	for i := 0; i < n-1; i++ {
		fmt.Println("Enter the element")
		b += int(strings.TrimSpace(reader.ReadString()))
	}
	for i := 0; i < n-2; i++ {
		fmt.Println("Enter the element")
		c += int(strings.TrimSpace(reader.ReadString()))
	}
	x := a - b
	y := b - c
	fmt.Println(x)
	fmt.Println(y)
}

