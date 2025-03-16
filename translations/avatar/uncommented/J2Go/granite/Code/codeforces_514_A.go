
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
	fmt.Println("Enter a number:")
	text, _ := reader.ReadString('\n')
	number, _ := strconv.ParseInt(strings.TrimSpace(text), 10, 64)
	var list []int64
	for number > 0 {
		r := number % 10
		if 9-r < r {
			if number/10 == 0 && 9-r == 0 {
				list = append(list, r)
			} else {
				list = append(list, 9-r)
			}
		} else {
			list = append(list, r)
		}
		number = number / 10
	}
	var newNumber int64
	for i, v := range list {
		newNumber = newNumber + v*(int64(10))^(int64(i))
	}
	fmt.Println("New number:", newNumber)
}
