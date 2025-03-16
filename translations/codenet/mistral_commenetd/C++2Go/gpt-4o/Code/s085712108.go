package main

import (
	"fmt"
	"container/list"
)

const MOD = 7007

// Define a struct QUEUE to store the current state and the total number of steps taken
type QUEUE struct {
	a, b, c, tot int // a, b, c represent the current state and tot is the total number of steps taken
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
	var Push QUEUE
	Push.tot = 0

	var que list.List
	fmt.Scan(&Push.a, &Push.b, &Push.c)
	que.PushBack(Push)

	// Define the possible moves
	F := [][3]int{
		{1, 0, 0}, {0, 1, 0}, {0, 0, 1},
		{-1, 0, 0}, {0, -1, 0}, {0, 0, -1},
	}

	// Main loop to find the solution
	for que.Len() > 0 {
		// Dequeue the front element from the queue
		Fro := que.Remove(que.Front()).(QUEUE)

		// Check if the current state is the goal state
		if Fro.a == Fro.b && Fro.b == Fro.c {
			fmt.Println(Fro.tot) // Print the total number of steps taken and exit the program
			return
		}

		// Try all six possible moves and check if the resulting state is already in the hash table
		for _, move := range F {
			Push = Fro // Copy the current state into a new variable Push
			Push.tot++ // Increment the total number of steps taken
			Push.a += move[0]
			Push.b += move[1]
			Push.c += move[2] // Apply the move to the new state
			n := Push.a*10000 + Push.b*100 + Push.c // Calculate the hash code of the new state
			if !HASH(n) {
				continue // If the new state is already in the hash table, skip it
			}
			que.PushBack(Push) // Otherwise, push it into the queue and continue the search
		}
	}
}
