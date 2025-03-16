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
	fmt.Println("Enter the number of times to print the string")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the number of times to move right")
	k, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the string to print")
	a := strings.TrimSpace(reader.ReadString())

	if k > n/2 {
		for i := 0; i < n; i++ {
			fmt.Println("RIGHT")
		}
	} else {
		for i := 0; i < k; i++ {
			fmt.Println("LEFT")
		}
	}

	if k == 1 {
		for i := 0; i < len(a); i++ {
			fmt.Println("PRINT", a[i])
			if i+1 < len(a) {
				fmt.Println("RIGHT")
			}
		}
	} else {
		for i := len(a) - 1; i >= 0; i-- {
			fmt.Println("PRINT", a[i])
			if i-1 >= 0 {
				fmt.Println("LEFT")
			}
		}
	}
}

