
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
	fmt.Print("Enter two integers: ")
	input, _ := reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	a, _ := strconv.Atoi(input)
	fmt.Print("Enter another integer: ")
	input, _ = reader.ReadString('\n')
	input = strings.Replace(input, "\n", "", -1)
	input = strings.Replace(input, " ", "", -1)
	b, _ := strconv.Atoi(input)
	hole := 1
	i := 0
	check := true
	for check {
		if hole >= b {
			check = false
		} else {
			hole = a * (i + 1) - i
			i++
		}
	}
	fmt.Println(i)
}

