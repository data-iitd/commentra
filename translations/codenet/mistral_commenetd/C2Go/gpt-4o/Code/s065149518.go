package main

import (
	"fmt"
)

const MAX = 21

var n, x, y int
var fld [MAX][MAX]int

func initGame(i int) {
	var a, b int
	x, y = 10, 10 // Set the initial position of the player
	for i > 0 {
		fmt.Scanf("%d %d", &a, &b) // Read and store the obstacles' positions
		fld[b][a] = 1
		i--
	}
}

func movePlayer(i int) {
	var a int
	var direction string
	for i > 0 {
		fmt.Scanf("%1s %d", &direction, &a) // Read the direction and the number of steps
		var d int
		switch direction[0] {
		case 'N':
			d = 0
		case 'E':
			d = 1
		case 'S':
			d = 2
		case 'W':
			d = 3
		}
		for a > 0 {
			if d%2 == 1 { // If the direction is odd, move horizontally
				if d == 1 {
					x++ // Move East
				} else {
					x-- // Move West
				}
			} else { // If the direction is even, move vertically
				if d == 0 {
					y++ // Move North
				} else {
					y-- // Move South
				}
			}
			if fld[y][x] == 1 { // If there's an obstacle at the current position
				fld[y][x] = 0 // Remove the obstacle
				n--           // Decrease the number of available moves
			}
			a--
		}
		i--
	}
}

func main() {
	var m int // m is the number of moves to be made
	for {
		if _, err := fmt.Scanf("%d", &n); err == nil { // Try to read an integer from the standard input
			if n >= 0 { // If n is non-negative, initialize the game and read m
				initGame(n)
				fmt.Scanf("%d", &m)
				movePlayer(m)
				if n > 0 {
					fmt.Println("No") // Print whether it's possible to make all moves
				} else {
					fmt.Println("Yes")
				}
			} else {
				break // If n is non-positive, break the loop
			}
		}
	}
}

// <END-OF-CODE>
