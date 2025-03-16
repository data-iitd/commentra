
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter two integers separated by a space:")
	text, _ := reader.ReadString('\n')
	x, _ := strconv.Atoi(text[:len(text)-1])
	y, _ := strconv.Atoi(text[len(text)-1:])

	a := 0
	for x >= 0 && y >= 22 || x >= 1 && y >= 12 || x >= 2 && y >= 2 {
		if a == 1 {
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

	if a == 0 {
		fmt.Println("Ciel")
	} else {
		fmt.Println("Hanako")
	}
}
