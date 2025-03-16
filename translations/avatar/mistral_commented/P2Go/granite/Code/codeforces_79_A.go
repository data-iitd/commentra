

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	x, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
	y, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n')[0])-1])
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
	fmt.Println([2]string{"Ciel", "Hanako"}[1-a])
}

