
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define a struct QUEUE to store the current state and the total number of steps taken
type QUEUE struct {
	a, b, c, tot int
}

// Initialize an empty hash table to store visited states
var Hash = make(map[int][]int)

// Function to check if a state is already in the hash table
func HASH(n int) bool {
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}

func main() {
	// Initialize some variables and read input data
	var F = [6][3]int{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}}
	var Push QUEUE
	Push.tot = 0
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d %d\n", &Push.a, &Push.b, &Push.c)
	que := make([]QUEUE, 0)
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
			Push = Fro
			Push.tot++ // Increment the total number of steps taken
			Push.a += F[i][0]
			Push.b += F[i][1]
			Push.c += F[i][2]
			n := Push.a*10000 + Push.b*100 + Push.c // Calculate the hash code of the new state
			if!HASH(n) {
				continue // If the new state is already in the hash table, skip it
			}
			que = append(que, Push) // Otherwise, push it into the queue and continue the search
		}
	}

	// Return 0 to indicate that the program has finished running
	return
}

