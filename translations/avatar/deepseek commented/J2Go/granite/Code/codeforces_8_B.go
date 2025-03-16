
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
	fmt.Print("Enter the input string: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	input = strings.Replace(input, "\n", "", -1)

	x, y := 0, 0
	coordinates := make([][]int, 2, 101)
	coordinates[0] = make([]int, 101)
	coordinates[1] = make([]int, 101)
	coordinates[0][0] = x
	coordinates[1][0] = y
	k := 1

	for _, direction := range input {
		switch direction {
		case 'L':
			x--
		case 'R':
			x++
		case 'U':
			y++
		case 'D':
			y--
		}
		coordinates[0][k] = x
		coordinates[1][k] = y
		k++
	}

	bugFound := false
	for i := 0; i < k-3; i++ {
		for j := i + 3; j < k; j++ {
			dx := coordinates[0][i] - coordinates[0][j]
			dy := coordinates[1][i] - coordinates[1][j]
			if dx < 0 {
				dx = -dx
			}
			if dy < 0 {
				dy = -dy
			}
			if (dx <= 1 && dy == 0) || (dy <= 1 && dx == 0) {
				bugFound = true
				break
			}
		}
		if bugFound {
			break
		}
	}

	if bugFound {
		fmt.Println("BUG")
	} else {
		fmt.Println("OK")
	}
}

