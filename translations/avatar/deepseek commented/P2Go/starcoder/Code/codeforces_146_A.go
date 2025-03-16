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
	input = strings.TrimSpace(input)
	number := strings.Split(input, " ")
	n, _ := strconv.Atoi(number[0])
	number = number[1:]
	h1 := 0
	h2 := 0
	x := 0
	for i := 0; i < n; i++ {
		if number[i]!= "4" && number[i]!= "7" {
			fmt.Println("NO")
			x = 1
			break
		}
		if i < n/2 {
			h1 += int(number[i][0] - '0')
		} else {
			h2 += int(number[i][0] - '0')
		}
	}
	if!x {
		if h1 == h2 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

