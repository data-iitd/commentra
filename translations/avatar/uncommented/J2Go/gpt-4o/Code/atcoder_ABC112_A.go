package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(nStr[:len(nStr)-1]) // Convert string to int and remove newline

	if n == 1 {
		fmt.Println("Hello World")
	} else {
		strs := make([]string, 2)
		for i := 0; i < 2; i++ {
			str, _ := reader.ReadString('\n')
			strs[i] = str[:len(str)-1] // Remove newline
		}
		num1, _ := strconv.Atoi(strs[0])
		num2, _ := strconv.Atoi(strs[1])
		fmt.Println(num1 + num2)
	}
}

// <END-OF-CODE>
