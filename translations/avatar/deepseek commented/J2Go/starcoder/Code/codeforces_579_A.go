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
	fmt.Println("Enter a number: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	num, _ := strconv.Atoi(input)
	var s string
	for num > 0 {
		s = string(num%2) + s
		num /= 2
	}
	var ans int
	for _, v := range s {
		if v == '1' {
			ans++
		}
	}
	fmt.Println(ans)
}

