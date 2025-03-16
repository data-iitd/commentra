package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

const Inf = 1 << 60 // Define a constant for infinity

func main() {
	// Read the dimensions of the grid and the cost parameter
	H, W, K := ReadInt(), ReadInt(), ReadInt()
	// Read the starting and ending coordinates, adjusting for 0-based indexing
	x1, y1, x2, y2 := ReadInt()-1, ReadInt()-1, ReadInt()-1, ReadInt()-1
	x1, y1 = y1, x1 // Swap x and y for the starting point
	x2, y2 = y2, x2 // Swap x and y for the ending point

	// Read the grid representation
	c := make([]string, H)
	for y := 0; y < H; y++ {
		c[y] = ReadString()
	}

	// Define movement directions (right, down, left, up)
	var dx = []int{1, 0, -1, 0}
	var dy = []int{0, 1, 0, -1}

	// Function to convert (x, y, dir) to a unique ID
	toID := func(x, y, dir int) int {
		return 4*(W*y+x) + dir
	}
	// Function to convert an ID back to (x, y, dir)
	splatID := func(id int) (x, y, dir int) {
		return id / 4 % W, id / 4 / W, id % 4
	}

	// Initialize the distance array with infinity
	dist := make([]int, W*H*4)
	for i := 0; i < W*H*4; i++ {
		dist[i] = Inf
	}

	// Initialize the priority queue (min-heap) with starting states
	q := Heap{}
	for i := 0; i < 4; i++ {
		q = append(q, State{
			Cost: 0,
			ID:   toID(x1, y1, i),
		})
	}

	// Main loop for Dijkstra's algorithm
	for len(q) > 0 {
		now := q.pop() // Get the state with the lowest cost
		x, y, dir := splatID(now.ID) // Decompose the ID into coordinates and direction

		// Skip if the current position is a wall
		if c[y][x] == '@' {
			continue
		}
		// Skip if we have already found a better cost for this state
		if dist[now.ID] <= now.Cost {
			continue
		}
		// Update the distance for the current state
		dist[now.ID] = now.Cost

		// If we reached the destination, exit the loop
		if x == x2 && y == y2 {
			break
		}

		// Explore all four possible directions
		for i := 0; i < 4; i++ {
			nCost := (now.Cost + K - 1) / K * K // Calculate the new cost
			nID := toID(x, y, i) // Get the new ID for the direction
			if dist[nID] <= nCost { // Skip if we have a better cost
				continue
			}
			// Push the new state into the priority queue
			q.push(State{
				Cost: nCost,
				ID:   nID,
			})
		}

		// Move in the current direction
		nx := x + dx[dir]
		ny := y + dy[dir]
		// Check if the new position is within bounds
		if 0 <= nx && nx < W && 0 <= ny && ny < H {
			nCost := now.Cost + 1 // Increment the cost for moving forward
			nID := toID(nx, ny, dir) // Get the new ID for the position
			if dist[nID] <= nCost { // Skip if we have a better cost
				continue
			}
			// Push the new state into the priority queue
			q.push(State{
				Cost: nCost,
				ID:   nID,
			})
		}
	}

	// Determine the minimum cost to reach the destination
	ans := Inf
	for i := 0; i < 4; i++ {
		id := toID(x2, y2, i) // Get the ID for the destination in each direction
		if dist[id] < ans { // Check if we found a better cost
			d2 := (dist[id] + K - 1) / K // Calculate the cost in terms of K
			if d2 < ans { // Update the answer if it's better
				ans = d2
			}
		}
	}

	// Output the result
	if ans < Inf {
		fmt.Println(ans) // Print the minimum cost
	} else {
		fmt.Println(-1) // Print -1 if the destination is unreachable
	}
}

// State represents a state in the priority queue with its cost and ID
type State struct {
	Cost, ID int
}

// Define the heap element type for the priority queue
type HeapElement = State
type Heap []HeapElement

// Implement the heap interface for the custom heap type
func (h Heap) Less(i, j int) bool    { return h[i].Cost < h[j].Cost }
func (h Heap) Len() int              { return len(h) }
func (h Heap) Swap(i, j int)         { h[i], h[j] = h[j], h[i] }
func (h *Heap) Push(x interface{})   { *h = append(*h, x.(HeapElement)) }
func (h *Heap) Pop() (x interface{}) { *h, x = (*h)[:len(*h)-1], (*h)[len(*h)-1]; return }
func (h *Heap) push(v HeapElement)   { heap.Push(h, v) }
func (h *Heap) pop() HeapElement     { return heap.Pop(h).(HeapElement) }

// Reader for standard input
var reader = bufio.NewReader(os.Stdin)

// Scan function to read input
func Scan(a ...interface{}) {
	if _, err := fmt.Fscan(reader, a...); err != nil {
		panic(err) // Panic if there's an error in reading
	}
}

// ReadInt reads an integer from input
func ReadInt() (i int) {
	Scan(&i)
	return
}

// ReadString reads a string from input
func ReadString() (s string) {
	Scan(&s)
	return
}

// ReadInts reads a slice of integers from input
func ReadInts(n int) []int {
	v := make([]int, n)
	for i := 0; i < n; i++ {
		Scan(&v[i])
	}
	return v
}
