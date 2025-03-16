package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var t [][]string

	// Loop through 4 iterations to get input strings from user
	for i := 0; i < 4; i++ {
		input, _ := reader.ReadString('\n')
		l := strings.Split(strings.TrimSpace(input), "")
		t = append(t, l)
	}

	black := 0
	white := 0
	correct := 0

	// Loop through the first 3 rows of the 4x4 grid represented by list 't'
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if t[i][j] == "#" {
				black++
			} else {
				white++
			}

			if t[i][j+1] == "#" {
				black++
			} else {
				white++
			}

			if t[i+1][j] == "#" {
				black++
			} else {
				white++
			}

			if t[i+1][j+1] == "#" {
				black++
			} else {
				white++
			}

			// Check the current cell and its neighbors for winning conditions
			if black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4 {
				correct = 1
				break
			}

			// Reset black and white counters for the next iteration of the inner loop
			black = 0
			white = 0
		}
		if correct == 1 {
			break
		}
	}

	if correct == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

