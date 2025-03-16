
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
	fmt.Print("Enter x and y: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	x, y := strings.Split(input, " ")
	x, _ = strconv.Atoi(x)
	y, _ = strconv.Atoi(y)
	a := 0
	for x >= 0 && y >= 22 || x >= 1 && y >= 12 || x >= 2 && y >= 2 {
		if a {
			if y >= 22 {
				y -= 22
			} else if x >= 1 && y >= 12 {
				x -= 1
				y -= 12
			} else {
				x -= 2
				y -= 2
			}
		} else {
			if x >= 2 && y >= 2 {
				x -= 2
				y -= 2
			} else if x >= 1 && y >= 12 {
				x -= 1
				y -= 12
			} else {
				y -= 22
			}
		}
		a = 1 - a
	}
	fmt.Println([2]string{"Ciel", "Hanako"}[1-a])
}

