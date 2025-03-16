package main

import (
	"fmt"
	"math"
)

// Define a struct QUEUE to store the current state and the total number of steps taken
type QUEUE struct {
	a, b, c, tot int
}

// Initialize an empty hash table to store visited states
var Hash [7007][]int

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
	var Push QUEUE
	que := make([]QUEUE, 0)
	fmt.Scan(&Push.a, &Push.b, &Push.c)
	que = append(que, Push)

	// Main loop to find the solution
	for len(que) > 0 {
		Fro := que[0] // Dequeue the front element from the queue

		// Check if the current state is the goal state
		if Fro.a == Fro.b && Fro.b == Fro.c {
			fmt.Println(Fro.tot) // Print the total number of steps taken and exit the program
			return
		}

		// Try all six possible moves and check if the resulting state is already in the hash table
		for i := 0; i < 6; i++ {
			Push = Fro // Copy the current state into a new variable Push
			Push.tot++ // Increment the total number of steps taken
			Push.a += F[i][0]
			Push.b += F[i][1]
			Push.c += F[i][2]
			n := Push.a*10000 + Push.b*100 + Push.c
			if !HASH(n) {
				continue
			}
			que = append(que, Push) // Otherwise, push it into the queue and continue the search
		}

		// Dequeue the front element from the queue to continue the search
		que = que[1:]
	}

	// Return 0 to indicate that the program has finished running
	return
}

// Define a 2D array F to store the six possible moves
var F = [6][3]int{
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1},
	{-1, 0, 0},
	{0, -1, 0},
	{0, 0, -1},
}

// Define a function to calculate the hash code of a state
func HASH(a, b, c int) int {
	return a*10000 + b*100 + c
}

// Define a function to check if a state is already in the hash table
func HASH(n int) bool {
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}

// Define a function to check if a state is the goal state
func GOAL(a, b, c int) bool {
	return a == b && b == c
}

// Define a function to print the solution
func PRINT(tot int) {
	fmt.Println(tot)
}

// Define a function to calculate the total number of steps taken
func TOT(a, b, c int) int {
	return a + b + c
}

// Define a function to apply a move to a state
func MOVE(a, b, c, i int) (int, int, int) {
	return a + F[i][0], b + F[i][1], c + F[i][2]
}

// Define a function to check if a state is already in the hash table
func HASH(a, b, c int) bool {
	n := HASH(a, b, c)
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}

// Define a function to check if a state is the goal state
func GOAL(a, b, c int) bool {
	return a == b && b == c
}

// Define a function to print the solution
func PRINT(tot int) {
	fmt.Println(tot)
}

// Define a function to calculate the total number of steps taken
func TOT(a, b, c int) int {
	return a + b + c
}

// Define a function to apply a move to a state
func MOVE(a, b, c, i int) (int, int, int) {
	return a + F[i][0], b + F[i][1], c + F[i][2]
}

// Define a function to check if a state is already in the hash table
func HASH(a, b, c int) bool {
	n := HASH(a, b, c)
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}

// Define a function to check if a state is the goal state
func GOAL(a, b, c int) bool {
	return a == b && b == c
}

// Define a function to print the solution
func PRINT(tot int) {
	fmt.Println(tot)
}

// Define a function to calculate the total number of steps taken
func TOT(a, b, c int) int {
	return a + b + c
}

// Define a function to apply a move to a state
func MOVE(a, b, c, i int) (int, int, int) {
	return a + F[i][0], b + F[i][1], c + F[i][2]
}

// Define a function to check if a state is already in the hash table
func HASH(a, b, c int) bool {
	n := HASH(a, b, c)
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}

// Define a function to check if a state is the goal state
func GOAL(a, b, c int) bool {
	return a == b && b == c
}

// Define a function to print the solution
func PRINT(tot int) {
	fmt.Println(tot)
}

// Define a function to calculate the total number of steps taken
func TOT(a, b, c int) int {
	return a + b + c
}

// Define a function to apply a move to a state
func MOVE(a, b, c, i int) (int, int, int) {
	return a + F[i][0], b + F[i][1], c + F[i][2]
}

// Define a function to check if a state is already in the hash table
func HASH(a, b, c int) bool {
	n := HASH(a, b, c)
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}

// Define a function to check if a state is the goal state
func GOAL(a, b, c int) bool {
	return a == b && b == c
}

// Define a function to print the solution
func PRINT(tot int) {
	fmt.Println(tot)
}

// Define a function to calculate the total number of steps taken
func TOT(a, b, c int) int {
	return a + b + c
}

// Define a function to apply a move to a state
func MOVE(a, b, c, i int) (int, int, int) {
	return a + F[i][0], b + F[i][1], c + F[i][2]
}

// Define a function to check if a state is already in the hash table
func HASH(a, b, c int) bool {
	n := HASH(a, b, c)
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}

// Define a function to check if a state is the goal state
func GOAL(a, b, c int) bool {
	return a == b && b == c
}

// Define a function to print the solution
func PRINT(tot int) {
	fmt.Println(tot)
}

// Define a function to calculate the total number of steps taken
func TOT(a, b, c int) int {
	return a + b + c
}

// Define a function to apply a move to a state
func MOVE(a, b, c, i int) (int, int, int) {
	return a + F[i][0], b + F[i][1], c + F[i][2]
}

// Define a function to check if a state is already in the hash table
func HASH(a, b, c int) bool {
	n := HASH(a, b, c)
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}

// Define a function to check if a state is the goal state
func GOAL(a, b, c int) bool {
	return a == b && b == c
}

// Define a function to print the solution
func PRINT(tot int) {
	fmt.Println(tot)
}

// Define a function to calculate the total number of steps taken
func TOT(a, b, c int) int {
	return a + b + c
}

// Define a function to apply a move to a state
func MOVE(a, b, c, i int) (int, int, int) {
	return a + F[i][0], b + F[i][1], c + F[i][2]
}

// Define a function to check if a state is already in the hash table
func HASH(a, b, c int) bool {
	n := HASH(a, b, c)
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}

// Define a function to check if a state is the goal state
func GOAL(a, b, c int) bool {
	return a == b && b == c
}

// Define a function to print the solution
func PRINT(tot int) {
	fmt.Println(tot)
}

// Define a function to calculate the total number of steps taken
func TOT(a, b, c int) int {
	return a + b + c
}

// Define a function to apply a move to a state
func MOVE(a, b, c, i int) (int, int, int) {
	return a + F[i][0], b + F[i][1], c + F[i][2]
}

// Define a function to check if a state is already in the hash table
func HASH(a, b, c int) bool {
	n := HASH(a, b, c)
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}

// Define a function to check if a state is the goal state
func GOAL(a, b, c int) bool {
	return a == b && b == c
}

// Define a function to print the solution
func PRINT(tot int) {
	fmt.Println(tot)
}

// Define a function to calculate the total number of steps taken
func TOT(a, b, c int) int {
	return a + b + c
}

// Define a function to apply a move to a state
func MOVE(a, b, c, i int) (int, int, int) {
	return a + F[i][0], b + F[i][1], c + F[i][2]
}

// Define a function to check if a state is already in the hash table
func HASH(a, b, c int) bool {
	n := HASH(a, b, c)
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}

// Define a function to check if a state is the goal state
func GOAL(a, b, c int) bool {
	return a == b && b == c
}

// Define a function to print the solution
func PRINT(tot int) {
	fmt.Println(tot)
}

// Define a function to calculate the total number of steps taken
func TOT(a, b, c int) int {
	return a + b + c
}

// Define a function to apply a move to a state
func MOVE(a, b, c, i int) (int, int, int) {
	return a + F[i][0], b + F[i][1], c + F[i][2]
}

// Define a function to check if a state is already in the hash table
func HASH(a, b, c int) bool {
	n := HASH(a, b, c)
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}

// Define a function to check if a state is the goal state
func GOAL(a, b, c int) bool {
	return a == b && b == c
}

// Define a function to print the solution
func PRINT(tot int) {
	fmt.Println(tot)
}

// Define a function to calculate the total number of steps taken
func TOT(a, b, c int) int {
	return a + b + c
}

// Define a function to apply a move to a state
func MOVE(a, b, c, i int) (int, int, int) {
	return a + F[i][0], b + F[i][1], c + F[i][2]
}

// Define a function to check if a state is already in the hash table
func HASH(a, b, c int) bool {
	n := HASH(a, b, c)
	for _, v := range Hash[n%7007] {
		if n == v {
			return false
		}
	}
	Hash[n%7007] = append(Hash[n%7007], n)
	return true
}

// Define a function to check if a state is the goal state
func GOAL(a, b, c int) bool {
	return a == b && b == c
}

// Define a function to print the solution
fun