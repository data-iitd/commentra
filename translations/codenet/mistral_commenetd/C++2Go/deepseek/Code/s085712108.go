package main

import (
	"fmt"
	"math/rand"
)

const MOD = 7007

// Define a struct QUEUE to store the current state and the total number of steps taken
type QUEUE struct {
	a, b, c, tot int
}

// Initialize an empty hash table to store visited states
var Hash [MOD][]int

// Function to check if a state is already in the hash table
func HASH(n int) bool {
	for _, v := range Hash[n%MOD] {
		if n == v {
			return false
		}
	}
	Hash[n%MOD] = append(Hash[n%MOD], n)
	return true
}

func main() {
	// Initialize some variables and read input data
	Push := QUEUE{tot: 0}
	var que []QUEUE
	fmt.Scan(&Push.a, &Push.b, &Push.c)
	que = append(que, Push)

	// Main loop to find the solution
	for len(que) > 0 {
		Fro := que[0] // Dequeue the front element from the queue
		que = que[1:]

		// Check if the current state is the goal state
		if Fro.a == Fro.b && Fro.b == Fro.c {
			fmt.Println(Fro.tot) // Print the total number of steps taken and exit the program
			return
		}

		// Try all six possible moves and check if the resulting state is already in the hash table
		for i := 0; i < 6; i++ {
			Push := Fro
			Push.tot++ // Increment the total number of steps taken
			// Apply the move to the new state
			// Note: The original C++ code had an array F[6][3] which is not defined here.
			// I'm assuming the moves are hardcoded for simplicity.
			switch i {
			case 0:
				Push.a++
				Push.b++
				Push.c++
			case 1:
				Push.a--
				Push.b--
				Push.c--
			case 2:
				Push.a += 2
				Push.b += 2
				Push.c += 2
			case 3:
				Push.a -= 2
				Push.b -= 2
				Push.c -= 2
			case 4:
				Push.a++
				Push.b--
				Push.c--
			case 5:
				Push.a--
				Push.b++
				Push.c++
			}
			n := Push.a*10000 + Push.b*100 + Push.c
			if !HASH(n) {
				continue // If the new state is already in the hash table, skip it
			}
			que = append(que, Push) // Otherwise, push it into the queue and continue the search
		}
	}

	// Return 0 to indicate that the program has finished running
	fmt.Println("No solution found")
}

