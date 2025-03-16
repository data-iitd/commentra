<<<<<<< HEAD

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)
=======
package main

import "fmt"
>>>>>>> 98c87cb78a (data updated)

// Define a struct QUEUE to store the current state and the total number of steps taken
type QUEUE struct {
	a, b, c, tot int
}

// Initialize an empty hash table to store visited states
<<<<<<< HEAD
var Hash [1000000] []int

// Function to check if a state is already in the hash table
func HASH(n int) bool {
	for i := 0; i < len(Hash[n%1000000]); i++ {
		if n == Hash[n%1000000][i] {
			return false
		}
	}
	Hash[n%1000000] = append(Hash[n%1000000], n)
=======
var Hash [7007] []int

// Function to check if a state is already in the hash table
func HASH(n int) bool {
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
>>>>>>> 98c87cb78a (data updated)
	return true
}

func main() {
	// Initialize some variables and read input data
	var Fro QUEUE
<<<<<<< HEAD
	Fro.tot = 0
	var que []QUEUE
	var Push QUEUE
	var a, b, c int
	fmt.Scanf("%d%d%d", &a, &b, &c)
	Push.a = a
	Push.b = b
	Push.c = c
	que = append(que, Push)

	// Main loop to find the solution
	for len(que) > 0 {
		Fro = que[0] // Dequeue the front element from the queue

		// Check if the current state is the goal state
		if Fro.a == Fro.b && Fro.b == Fro.c {
			fmt.Printf("%d\n", Fro.tot) // Print the total number of steps taken and exit the program
			os.Exit(0)
=======
	var Push QUEUE
	fmt.Scanf("%d%d%d", &Fro.a, &Fro.b, &Fro.c)
	Fro.tot = 0
	var que = make(chan QUEUE)
	que <- Fro

	// Main loop to find the solution
	for {
		Fro = <-que
		// Check if the current state is the goal state
		if Fro.a == Fro.b && Fro.b == Fro.c {
			fmt.Printf("%d\n", Fro.tot) // Print the total number of steps taken and exit the program
			return
>>>>>>> 98c87cb78a (data updated)
		}

		// Try all six possible moves and check if the resulting state is already in the hash table
		for i := 0; i < 6; i++ {
<<<<<<< HEAD
			Push = Fro // Copy the current state into a new variable Push
			Push.tot++ // Increment the total number of steps taken
=======
			Push = Fro
			Push.tot++
>>>>>>> 98c87cb78a (data updated)
			Push.a += F[i][0]
			Push.b += F[i][1]
			Push.c += F[i][2]
			n := Push.a*10000 + Push.b*100 + Push.c
			if!HASH(n) {
				continue
			}
<<<<<<< HEAD
			que = append(que, Push) // Otherwise, push it into the queue and continue the search
		}

		// Dequeue the front element from the queue to continue the search
		que = que[1:]
	}

	// Return 0 to indicate that the program has finished running
	os.Exit(0)
=======
			que <- Push
		}
	}
>>>>>>> 98c87cb78a (data updated)
}

