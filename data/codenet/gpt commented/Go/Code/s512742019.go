package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// I/O
// Scanner struct to handle input reading
type Scanner struct {
	sc *bufio.Scanner
}

// NewScanner initializes a new Scanner for reading input
func NewScanner() *Scanner {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords) // Split input by words
	sc.Buffer(make([]byte, 1024), int(1e+9)) // Set buffer size
	return &Scanner{sc}
}

// nextStr reads the next string from input
func (s *Scanner) nextStr() string {
	s.sc.Scan()
	return s.sc.Text()
}

// nextInt reads the next integer from input
func (s *Scanner) nextInt() int {
	i, e := strconv.Atoi(s.nextStr())
	if e != nil {
		panic(e) // Panic if conversion fails
	}
	return i
}

// nextFloat reads the next float from input
func (s *Scanner) nextFloat() float64 {
	f, e := strconv.ParseFloat(s.nextStr(), 64)
	if e != nil {
		panic(e) // Panic if conversion fails
	}
	return f
}

// nextRuneSlice reads the next string and converts it to a slice of runes
func (s *Scanner) nextRuneSlice() []rune {
	return []rune(s.nextStr())
}

// nextIntSlice reads n integers from input and returns them as a slice
func (s *Scanner) nextIntSlice(n int) []int {
	res := make([]int, n)
	for i := 0; i < n; i++ {
		res[i] = s.nextInt()
	}
	return res
}

// nextFloatSlice reads n floats from input and returns them as a slice
func (s *Scanner) nextFloatSlice(n int) []float64 {
	res := make([]float64, n)
	for i := 0; i < n; i++ {
		res[i] = s.nextFloat()
	}
	return res
}

// Arithmetic
// max returns the maximum value from a list of integers
func max(nums ...int) int {
	m := nums[0]
	for _, i := range nums {
		if m < i {
			m = i
		}
	}
	return m
}

// min returns the minimum value from a list of integers
func min(nums ...int) int {
	m := nums[0]
	for _, i := range nums {
		if m > i {
			m = i
		}
	}
	return m
}

// abs returns the absolute value of an integer
func abs(x int) int {
	if x > 0 {
		return x
	}
	return -x
}

// pow calculates x raised to the power of y
func pow(x, y int) int {
	res := 1
	for i := 0; i < y; i++ {
		res *= x
	}
	return res
}

// ceil calculates the ceiling of a/b
func ceil(a, b int) int {
	if a%b == 0 {
		return a / b
	} else {
		return a/b + 1
	}
}

// Sort
// RuneSlice is a type that implements sort.Interface for slices of runes
type RuneSlice []rune

func (a RuneSlice) Len() int           { return len(a) }
func (a RuneSlice) Less(i, j int) bool { return a[i] < a[j] }
func (a RuneSlice) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }

// Main
const MOD = int(1e+9) + 7 // Define a constant for modulo operation
const INF = 1 << 60       // Define a constant for infinity

// Mon represents a monster with position x and health h
type Mon struct {
	x, h int
}

// Mons is a slice of Mon for sorting
type Mons []Mon

func (a Mons) Len() int           { return len(a) }
func (a Mons) Less(i, j int) bool { return a[i].x < a[j].x }
func (a Mons) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }

// Node represents a position and damage
type Node struct {
	x, h int
}

// Queue is a simple queue implementation for Nodes
type Queue struct {
	arr []Node
}

// push adds a Node to the end of the queue
func (q *Queue) push(v Node) {
	q.arr = append(q.arr, v)
}

// first returns the first Node in the queue without removing it
func (q *Queue) first() Node {
	return q.arr[0]
}

// pop removes and returns the first Node in the queue
func (q *Queue) pop() Node {
	res := q.arr[0]
	q.arr = q.arr[1:]
	return res
}

// isEmpty checks if the queue is empty
func (q *Queue) isEmpty() bool {
	return len(q.arr) == 0
}

// main function to execute the program logic
func main() {
	sc := NewScanner() // Initialize the scanner for input
	wtr := bufio.NewWriter(os.Stdout) // Create a writer for output
	N, D, A := sc.nextInt(), sc.nextInt(), sc.nextInt() // Read N, D, A
	M := make([]Mon, N) // Create a slice to hold monsters
	for i := 0; i < N; i++ {
		M[i] = Mon{sc.nextInt(), sc.nextInt()} // Read each monster's position and health
	}
	sort.Sort(Mons(M)) // Sort monsters by their position

	var q Queue // Initialize a queue to manage damage
	ans := 0    // Variable to count the total number of attacks
	total := 0  // Variable to track total damage dealt

	// Iterate through each monster
	for i := 0; i < N; i++ {
		m := M[i] // Get the current monster
		// Remove monsters from the queue that are out of range
		for !q.isEmpty() && q.first().x < m.x {
			total -= q.pop().h // Decrease total damage by the damage of the popped monster
		}
		// If the total damage is less than the monster's health
		if total < m.h {
			m.h -= total // Reduce the monster's health by total damage
			count := ceil(m.h, A) // Calculate how many attacks are needed
			ans += count // Increment the total attack count
			damage := count * A // Calculate the total damage dealt to this monster
			q.push(Node{m.x + 2*D, damage}) // Add the monster's damage to the queue
			total += damage // Update the total damage
		}
	}

	fmt.Fprintln(wtr, ans) // Output the total number of attacks
	wtr.Flush() // Flush the writer to ensure all output is written
}
