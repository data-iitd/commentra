package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"os"
)

const Inf = 1 << 60

// Function to read a single integer from standard input
func ReadInt() int {
	var i int
	Scan(&i)
	return i
}

// Function to read a single string from standard input
func ReadString() string {
	var s string
	Scan(&s)
	return s
}

// Function to read multiple integers from standard input
func ReadInts(n int) []int {
	v := make([]int, n)
	for i := 0; i < n; i++ {
		Scan(&v[i])
	}
	return v
}

// Function to read the initial dimensions and number of moves from standard input
func ReadInput() (int, int, int, int, int, int, int, int) {
	H, W, K := ReadInt(), ReadInt(), ReadInt()
	x1, y1, x2, y2 := ReadInt()-1, ReadInt()-1, ReadInt()-1, ReadInt()-1
	x1, y1 = y1, x1
	x2, y2 = y2, x2
	return H, W, K, x1, y1, x2, y2
}

// Function to read the input grid from standard input
func ReadGrid(H, W int) []string {
	c := make([]string, H)
	for y := 0; y < H; y++ {
		c[y] = ReadString()
	}
	return c
}

// Function to calculate the index of a cell in the grid based on its position and direction
func toID(x, y, dir int) int {
	return 4 * (W * y + x) + dir
}

// Function to calculate the index of a cell from its index
func splatID(id int) (int, int, int) {
	x := id % W
	y := id / W
	dir := id % 4
	return x, y, dir
}

// Global variable to store the distance from the starting cell to all other cells
var dist []int

// Global variable to store the heap of states
var q Heap

// Constant to represent infinity
const Inf = 1 << 60

// Function to initialize the distances to infinity and add the starting cell to the heap
func initDist(H, W, K int, x1, y1, x2, y2 int) {
	dist = make([]int, W*H*4)
	for i := 0; i < W*H*4; i++ {
		dist[i] = Inf
	}
	for i := 0; i < 4; i++ {
		q = append(q, State{
			Cost: 0,
			ID:   toID(x1, y1, i),
		})
	}
}

// Type to represent a state of the grid
type State struct {
	Cost, ID int
}

// Type to represent a heap of states
type HeapElement interface{}
type Heap []State

// Function to check if one heap element is less than another
func (h Heap) Less(i, j int) bool {
	return h[i].Cost < h[j].Cost
}

// Function to get the length of the heap
func (h Heap) Len() int {
	return len(h)
}

// Function to swap two elements in the heap
func (h *Heap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

// Function to push an element onto the heap
func (h *Heap) Push(x interface{}) {
	*h = append(*h, x.(State))
}

// Function to pop an element from the heap
func (h *Heap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// Function to add a state to the heap
func (h *Heap) push(v State) {
	heap.Push(h, v)
}

// Function to remove a state from the heap
func (h *Heap) pop() State {
	return heap.Pop(h).(State)
}

// Function to read from standard input using a buffer reader
var reader = bufio.NewReader(os.Stdin)

// Function to scan multiple arguments from standard input
func Scan(a ...interface{}) {
	if _, err := fmt.Fscan(reader, a...); err != nil {
		panic(err)
	}
}

func main() {
	// Read the input dimensions, number of moves, and starting and ending positions
	H, W, K, x1, y1, x2, y2 := ReadInput()

	// Read the input grid
	c := ReadGrid(H, W)

	// Initialize the distances and add the starting cell to the heap
	initDist(H, W, K, x1, y1, x2, y2)

	// Process the heap until the goal cell is reached or all cells have been visited
	for len(q) > 0 {
		now := q.pop()
		x, y, dir := splatID(now.ID)

		// If the current cell is the goal cell, break the loop
		if x == x2 && y == y2 {
			break
		}

		// If the current cell has already been visited, continue to the next cell
		if dist[now.ID] <= now.Cost {
			continue
		}

		// Update the distance to the current cell and add its neighbors to the heap
		dist[now.ID] = now.Cost
		for i := 0; i < 4; i++ {
			nCost := now.Cost + K
			nID := toID(x, y, i)
			if dist[nID] <= nCost {
				continue
			}
			q.push(State{
				Cost: nCost,
				ID:   nID,
			})
		}

		// Move to the next neighbor and repeat the process
		nx := x + dx[dir]
		ny := y + dy[dir]
		if 0 <= nx && nx < W && 0 <= ny && ny < H {
			nCost := now.Cost + 1
			nID := toID(nx, ny, dir)
			if dist[nID] <= nCost {
				continue
			}
			q.push(State{
				Cost: nCost,
				ID:   nID,
			})
		}
	}

	// Calculate the minimum number of moves to reach the goal cell
	ans := Inf
	for i := 0; i < 4; i++ {
		id := toID(x2, y2, i)
		if dist[id] < ans {
			ans = dist[id]
		}
	}

	// Print the result
	if ans < Inf {
		fmt.Println(ans)
	} else {
		fmt.Println(-1)
	}
}

// Constants to represent the possible directions of movement
const (
	dx = [4]int{1, 0, -1, 0}
	dy = [4]int{0, 1, 0, -1}
)

// Function to calculate the index of the next cell in a given direction from the current cell
func toID(x, y, dir int) int {
	return 4 * (W*y+x) + dir
}

// Function to extract the position and direction from the index of a cell
func splatID(id int) (int, int, int) {
	x := id % W
	y := id / W
	dir := id % 4
	return x, y, dir
}

// Type to represent a state of the grid
type State struct {
	Cost, ID int
}

// Type to represent a heap of states
type HeapElement interface{}
type Heap []State

// Function to check if one heap element is less than another
func (h Heap) Less(i, j int) bool {
	return h[i].Cost < h[j].Cost
}

// Function to get the length of the heap
func (h Heap) Len() int {
	return len(h)
}

// Function to swap two elements in the heap
func (h *Heap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

// Function to push an element onto the heap
func (h *Heap) Push(x interface{}) {
	*h = append(*h, x.(State))
}

// Function to pop an element from the heap
func (h *Heap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// Function to add a state to the heap
func (h *Heap) push(v State) {
	heap.Push(h, v)
}

// Function to remove a state from the heap
func (h *Heap) pop() State {
	return heap.Pop(h).(State)
}

// Function to read from standard input using a buffer reader
var reader = bufio.NewReader(os.Stdin)

// Function to scan multiple arguments from standard input
func Scan(a ...interface{}) {
	if _, err := fmt.Fscan(reader, a...); err != nil {
		panic(err)
	}
}

// Function to initialize the distances and add the starting cell to the heap
func initDist(H, W, K int, x1, y1, x2, y2 int) {
	dist = make([]int, W*H*4)
	for i := 0; i < W*H*4; i++ {
		dist[i] = Inf
	}
	for i := 0; i < 4; i++ {
		q.push(State{
			Cost: 0,
			ID:   toID(x1, y1, i),
		})
	}
}

// Function to process the heap until the goal cell is reached or all cells have been visited
func processHeap() {
	for len(q) > 0 {
		now := q.pop()
		x, y, dir := splatID(now.ID)

		if x == x2 && y == y2 {
			break
		}

		if dist[now.ID] <= now.Cost {
			continue
		}

		dist[now.ID] = now.Cost
		for i := 0; i < 4; i++ {
			nCost := now.Cost + K
			nID := toID(x, y, i)
			if dist[nID] <= nCost {
				continue
			}
			q.push(State{
				Cost: nCost,
				ID:   nID,
			})
		}

		nx := x + dx[dir]
		ny := y + dy[dir]
		if 0 <= nx && nx < W && 0 <= ny && ny < H {
			nCost := now.Cost + 1
			nID := toID(nx, ny, dir)
			if dist[nID] <= nCost {
				continue
			}
			q.push(State{
				Cost: nCost,
				ID:   nID,
			})
		}
	}
}

// Function to calculate the minimum number of moves to reach the goal cell
func calculateAnswer() int {
	ans := Inf
	for i := 0; i < 4; i++ {
		id := toID(x2, y2, i)
		if dist[id] < ans {
			ans = dist[id]
		}
	}
	return ans
}

// Function to print the result
func printResult() {
	if ans < Inf {
		fmt.Println(ans)
	} else {
		fmt.Println(-1)
	}
}

// Global variables
var dist []int
var q Heap
const Inf = 1 << 60

// Constants
const (
	dx = [4]int{1, 0, -1, 0}
	dy = [4]int{0, 1, 0, -1}
)

// Types
type State struct {
	Cost, ID int
}
type HeapElement interface{}
type Heap []State

// Functions
func ReadInt() int
func ReadString() string
func ReadInts(n int) []int
func ReadInput() (int, int, int, int, int, int, int, int)
func ReadGrid(H, W int) []string
func toID(x, y, dir int) int
func splatID(id int) (int, int, int)
func initDist(H, W, K int, x1, y1, x2, y2 int)
func processHeap()
func calculateAnswer() int
func printResult()
func Scan(a ...interface{})
func main()

// Comments
// Function to read a single integer from standard input
// Returns an integer value read from standard input
func ReadInt() int {
	var i int
	Scan(&i)
	return i
}

// Function to read a single string from standard input
// Returns a string value read from standard input
func ReadString() string {
	var s string
	Scan(&s)
	return s
}

// Function to read multiple integers from standard input
// Reads n integers from standard input and returns a slice of integers
func ReadInts(n int) []int {
	v := make([]int, n)
	for i := 0; i < n; i++ {
		Scan(&v[i])
	}
	return v
}

// Function to read the initial dimensions and number of moves from standard input
// Returns the height, width, and number of moves of the grid
func ReadInput() (int, int, int, int, int, int, int, int) {
	H, W, K := ReadInt(), ReadInt(), ReadInt()
	x1, y1, x2, y2 := ReadInt()-1, ReadInt()-1, ReadInt()-1, ReadInt()-1
	x1, y1 = y1, x1
	x2, y2 = y2, x2
	return H, W, K, x1, y1, x2, y2
}

// Function to read the input grid from standard input
// Returns a slice of strings representing the grid
func ReadGrid(H, W int) []string {
	c := make([]string, H)
	for y := 0; y < H; y++ {
		c[y] = ReadString()
	}
	return c
}

// Function to calculate the index of a cell in the grid based on its position and direction
func toID(x, y, dir int) int {
	return 4 * (W * y + x) + dir
}

// Function to extract the position and direction from the index of a cell
func splatID(id int) (int, int, int) {
	x := id % W
	y := id / W
	dir := id % 4
	return x, y, dir
}

// Function to initialize the distances to all cells to infinity and add the starting cell to the heap
func initDist(H, W, K int, x1, y1, x2, y2 int) 