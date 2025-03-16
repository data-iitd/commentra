package main

import (
	"fmt"
	"container/list"
)

const MOD = 7007

type QUEUE struct {
	a, b, c, tot int // a, b, c represent the amounts in the glasses, tot represents the number of operations
}

var F = [6][3]int{
	{1, 1, 0},
	{1, 0, 1},
	{0, 1, 1},
	{2, 0, 0},
	{0, 2, 0},
	{0, 0, 2},
}

var Hash [MOD][]int

func HASH(n int) bool {
	for _, v := range Hash[n%MOD] {
		if n == v {
			return false // State already visited
		}
	}
	Hash[n%MOD] = append(Hash[n%MOD], n) // Add the state to the hash table
	return true                            // State is new
}

func main() {
	var Push QUEUE
	Push.tot = 0

	var que list.List

	// Read the initial amounts in the glasses
	fmt.Scan(&Push.a, &Push.b, &Push.c)
	// Push the initial state into the queue
	que.PushBack(Push)

	// Perform BFS until the queue is empty
	for que.Len() > 0 {
		// Get the front state from the queue
		Fro := que.Remove(que.Front()).(QUEUE)

		// Check if all glasses have the same amount
		if Fro.a == Fro.b && Fro.b == Fro.c {
			// If they are equal, print the number of operations and exit
			fmt.Println(Fro.tot)
			return
		}

		// Iterate through all possible operations
		for i := 0; i < 6; i++ {
			Push = Fro
			Push.tot++ // Increment the operation count

			// Apply the operation to the glasses
			Push.a += F[i][0]
			Push.b += F[i][1]
			Push.c += F[i][2]

			// Create a unique identifier for the new state
			n := Push.a*10000 + Push.b*100 + Push.c

			// Check if the new state has been visited
			if !HASH(n) {
				continue // If visited, skip to the next operation
			}

			// Push the new state into the queue for further exploration
			que.PushBack(Push)
		}
	}
}

// <END-OF-CODE>
