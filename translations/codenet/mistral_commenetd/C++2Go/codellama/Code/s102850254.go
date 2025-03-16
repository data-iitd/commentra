
package main

import (
	"fmt"
	"strings"
)

func main() {
	var d int // number of test cases
	var map [105]string // 2D array to store the grid
	var n int // size of the grid
	dx := [4]int{0, 1, 0, -1} // directions to move in 4 directions
	dy := [4]int{-1, 0, 1, 0} // directions to move in 4 directions
	var sum, flg int // variables used in visit function
	x, y := 2, n // initial position of the function
	var temp string // temporary variable to store the character in the grid

	fmt.Scan(&d) // read the number of test cases

	for l := 0; l < d; l++ { // iterate through each test case
		fmt.Scan(&n) // read the size of the grid

		if n == 1 { // if the size of the grid is 1
			fmt.Println("#") // print '#'
			if l != d-1 {
				fmt.Println() // print newline if it's not the last test case
			}
			continue // move to the next test case
		}

		for i := 0; i <= n+1; i++ { // initialize the map with '#' and '.
			map[i] = strings.Repeat(".", n+2)
			for j := 0; j <= n+1; j++ {
				if i == 0 || j == 0 || i == n+1 || j == n+1 {
					map[i] = strings.Replace(map[i], ".", "#", 1)
				}
			}
		}

		visit() // call the visit function

		for i := 1; i <= n; i++ { // print the grid
			for j := 1; j < len(map[i])-1; j++ {
				fmt.Print(string(map[i][j]))
			}
			fmt.Println()
		}

		if l != d-1 {
			fmt.Println() // print newline if it's not the last test case
		}
	}
}

func visit() {
	// function to find the path of 'O' in the grid
	ab := [4]int{2, 2, 2, 2} // array to store the number of 'O's in 4 directions

	for {
		sum = 0 // initialize sum to 0
		flg = 0 // initialize flag to 0

		for {
			if map[y+dy[flg]*2][x+dx[flg]*2] != "#" && map[y+dy[flg]][x+dx[flg]] != " " {
				// check if the next cell is not a wall or empty
				flg++ // increment flag

				// mark the cell as visited
				map[y+dy[flg]][x+dx[flg]] = " "

				// move to the next cell
				y = y + dy[flg]
				x = x + dx[flg]

				sum++ // increment sum

				break
			}
		}

		if flg == 4 { // if all 4 directions are visited
			flg = 0 // reset flag

			if sum == 0 {
				break // if no 'O' is found, break the loop
			}

			ab[0] = ab[1] // copy the value of ab[1] to ab[0]
			ab[1] = ab[2] // copy the value of ab[2] to ab[1]
			ab[2] = sum // store the number of 'O's in the current direction

			if ab[0] == 1 && ab[2] == 1 && ab[1] == 1 { // check if all 3 directions have 'O's
				break // if yes, break the loop
			}
		}
	}
}

