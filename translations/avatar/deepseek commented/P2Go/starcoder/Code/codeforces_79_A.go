
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
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	x, y := strings.Split(line, " ")
	x, _ = strconv.Atoi(x)
	y, _ = strconv.Atoi(y)
	a := 0
	for {
		if x >= 0 && y >= 22 || x >= 1 && y >= 12 || x >= 2 && y >= 2 {
			if a {
				if y >= 22 {
					y -= 22
				} else if x >= 1 && y >= 12 {
					x -= 1
					y -= 12
				} else {
					x -= 2
					y -= 2
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
			a = 1 - a
		} else {
			break
		}
	}
	fmt.Println([2]string{"Ciel", "Hanako"}[1-a])
}

