package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"

	"flag"
	"runtime"
	"runtime/pprof"
)

// Define a large prime number for modulo operations
var magic = 1000000007

// Command-line flags for CPU and memory profiling
var cpuprofile = flag.String("cpuprofile", "", "write cpu profile to file")
var memprofile = flag.String("memprofile", "", "write mem profile to file")

var N int
var p [200000]int

// Function to check if a number exists in the array p
func find(n int) int {
	for i := 0; i < N; i++ {
		if n == p[i] {
			return 0 // Number found
		}
	}
	return 1 // Number not found
}

// Main solving function
func solve() {
	io := NewIo() // Create a new IO instance for input/output
	defer io.Flush() // Ensure the output buffer is flushed at the end

	// PARSE HELPER SESSION
	// Read and log the input values
	X := io.NextInt() // Read an integer
	Logf("%v\n", X) // Log the integer
	N = io.NextInt() // Read the size of the array
	Logf("%v\n", N) // Log the size
	for i := 0; i < N; i++ {
		p[i] = io.NextInt() // Read integers into the array p
	}
	Logf("p %v\n", p[0:10]) // Log the first 10 elements of p

	// Check for numbers around X that are not in the array p
	for i := 0; i <= 100; i++ {
		if find(X-i) == 1 { // Check X - i
			fmt.Printf("%v\n", X-i) // Print the result
			os.Exit(0) // Exit the program
		}
		if find(X+i) == 1 { // Check X + i
			fmt.Printf("%v\n", X+i) // Print the result
			os.Exit(0) // Exit the program
		}
	}

	// OUTPUT GENERATION PART
	// ans := 0
	// fmt.Printf("%v\n", ans)

	// if ans > 0 {
	//   fmt.Printf("Yes\n")
	// } else {
	//   fmt.Printf("No\n")
	// }

	// BFS/DFS PART
	// visited := []int{}
	// bfs/dfs(1, neighbor, func(node int) {
	// 	visited = append(visited, node)
	// })
	// fmt.Println(visited)

	// DFS 2
	// var dp [2000000]int
	// nei := make(map[int][]int)
	// nei[0] = []int{1, 2}
	// nei[1] = []int{0}
	// nei[2] = []int{0, 3}
	// nei[3] = []int{2}
	// dfs2(0, nei, func(n, p int) {
	// 	Logf("%v -> %v\n", p, n)
	// 	dp[n] = p
	// }, func(n, p int) {
	// 	Logf("%v -> %v\n", n, p)
	// })
	// Logf("%v\n", dp[0:5])

	// COMBINATION
	// fmt.Printf("%d %d %d\n", N, M, intMax(N, M))
	// fmt.Printf("Lucas %d %d\n", combMod(N, M, 13), combination(N, M))
}

// Main function to execute the program
func main() {
	flag.Parse() // Parse command-line flags
	if *cpuprofile != "" {
		f, err := os.Create(*cpuprofile) // Create CPU profile file
		if err != nil {
			Logf("%v\n", err) // Log any error
			os.Exit(1) // Exit on error
		}
		pprof.StartCPUProfile(f) // Start CPU profiling
		defer pprof.StopCPUProfile() // Stop profiling when done
	}

	solve() // Call the solve function

	if *memprofile != "" {
		f, err := os.Create(*memprofile) // Create memory profile file
		if err != nil {
			Logf("could not create memory profile: ", err) // Log error
			os.Exit(1) // Exit on error
		}
		defer f.Close() // Close the file when done
		runtime.GC() // Trigger garbage collection for accurate memory stats
		if err := pprof.WriteHeapProfile(f); err != nil {
			Logf("could not write memory profile: ", err) // Log error
			os.Exit(1) // Exit on error
		}
	}
}

// Libraries

// Io helps parsing inputs from standard input for programming contests.
type Io struct {
	reader    *bufio.Reader
	writer    *bufio.Writer
	tokens    []string
	nextToken int
}

// NewIo generates Io instance.
func NewIo() *Io {
	return &Io{
		reader: bufio.NewReader(os.Stdin), // Initialize reader
		writer: bufio.NewWriter(os.Stdout), // Initialize writer
	}
}

// Flush flushes buffer. Don't forget to do this when you call Io.Printf/Io.PrintLn for final output.
func (io *Io) Flush() {
	err := io.writer.Flush() // Flush the writer buffer
	if err != nil {
		panic(err) // Panic on error
	}
}

// NextLine parses line as string.
func (io *Io) NextLine() string {
	var buffer []byte
	for {
		line, isPrefix, err := io.reader.ReadLine() // Read a line
		if err != nil {
			panic(err) // Panic on error
		}
		buffer = append(buffer, line...) // Append line to buffer
		if !isPrefix {
			break // Break if not a prefix
		}
	}
	return string(buffer) // Return the complete line as string
}

// Next parse next word as string.
func (io *Io) Next() string {
	for io.nextToken >= len(io.tokens) {
		line := io.NextLine() // Read the next line
		io.tokens = strings.Fields(line) // Split line into tokens
		io.nextToken = 0 // Reset token index
	}
	r := io.tokens[io.nextToken] // Get the next token
	io.nextToken++ // Move to the next token
	return r // Return the token
}

// NextInt parse next word as Int.
func (io *Io) NextInt() int {
	i, err := strconv.Atoi(io.Next()) // Convert the next token to int
	if err != nil {
		panic(err) // Panic on error
	}
	return i // Return the integer
}

// NextFloat parses next word as float64.
func (io *Io) NextFloat() float64 {
	i, err := strconv.ParseFloat(io.Next(), 64) // Convert the next token to float64
	if err != nil {
		panic(err) // Panic on error
	}
	return i // Return the float
}

// PrintLn does buffer write with linefeed.
func (io *Io) PrintLn(a ...interface{}) {
	fmt.Fprintln(io.writer, a...) // Write to buffer with linefeed
}

// Printf does formatted buffer write.
func (io *Io) Printf(format string, a ...interface{}) {
	fmt.Fprintf(io.writer, format, a...) // Write formatted output to buffer
}

// PrintIntLn prints Int array in a single line.
func (io *Io) PrintIntLn(a []int) {
	b := []interface{}{}
	for _, x := range a {
		b = append(b, x) // Append each integer to the slice
	}
	io.PrintLn(b...) // Print the integers in a single line
}

// PrintStringLn prints string array in a single line.
func (io *Io) PrintStringLn(a []string) {
	b := []interface{}{}
	for _, x := range a {
		b = append(b, x) // Append each string to the slice
	}
	io.PrintLn(b...) // Print the strings in a single line
}

// Log print single value to standard output (contest server ignores this so you don't have to remove when finishing)
func Log(name string, value interface{}) {
	fmt.Fprintf(os.Stderr, "%s=%+v\n", name, value) // Log the value to stderr
}

// Logf print formatted output to standard output (contest server ignores this so you don't have to remove when finishing)
func Logf(format string, a ...interface{}) {
	fmt.Fprintf(os.Stderr, format, a...) // Log formatted output to stderr
}

// Helper functions for mathematical operations

// Returns the minimum of two integers
func intMin(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// Returns the maximum of two integers
func intMax(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Direct calculation of combination
// n, m should be "small"
func combination(n, m int) int {
	if m > n {
		return 0 // Not possible to choose more than available
	} else if m == n || m == 0 {
		return 1 // Only one way to choose all or none
	} else {
		res := 1
		for i := 0; i < m; i++ {
			res *= (n - i) // Calculate numerator
		}
		for i := 1; i <= m; i++ {
			res /= i // Calculate denominator
		}
		return res // Return the combination result
	}
}

// Calculate combination modulo based on Lucas theorem
func lucas(n, m, p int) int {
	ntemp := n
	mtemp := m
	res := 1
	for i := 0; i < 100; i++ {
		nreminder := ntemp % p // Remainder of n
		ntemp = ntemp / p // Update n
		mreminder := mtemp % p // Remainder of m
		mtemp = mtemp / p // Update m
		res = res * (combination(nreminder, mreminder) % p) // Combine results
		if ntemp == 0 {
			break // Break if n is exhausted
		}
	}
	return res % p // Return the result modulo p
}

// Wrapper function for combination modulo
func combMod(n, m, p int) int {
	return lucas(n, m, p) // Call lucas function
}

// Breadth-First Search (BFS) implementation
func bfs(start int, nodes map[int][]int, fn func(int)) {
	frontier := []int{start} // Initialize the frontier with the start node
	visited := map[int]bool{} // Track visited nodes

	for 0 < len(frontier) {
		next := []int{} // Prepare for the next frontier
		for _, node := range frontier {
			visited[node] = true // Mark the node as visited
			fn(node) // Execute the provided function on the node
			for _, n := range bfsFrontier(node, nodes, visited) {
				next = append(next, n) // Add unvisited neighbors to the next frontier
			}
		}
		frontier = next // Move to the next frontier
	}
}

// Helper function to get unvisited neighbors for BFS
func bfsFrontier(node int, nodes map[int][]int, visited map[int]bool) []int {
	next := []int{}
	iter := func(n int) bool { _, ok := visited[n]; return !ok } // Check if a node is unvisited
	for _, n := range nodes[node] {
		if iter(n) {
			next = append(next, n) // Add unvisited neighbor to the list
		}
	}
	return next // Return the list of unvisited neighbors
}

// Depth-First Search (DFS) implementation
func dfs(node int, nodes map[int][]int, fn func(int)) {
	dfsRecur(node, nodes, map[int]bool{}, fn) // Start the recursive DFS
}

// Recursive DFS helper function
func dfsRecur(node int, nodes map[int][]int, v map[int]bool, fn func(int)) {
	v[node] = true // Mark the node as visited
	fn(node) // Execute the provided function on the node
	for _, n := range nodes[node] {
		if _, ok := v[n]; !ok {
			dfsRecur(n, nodes, v, fn) // Recursively visit unvisited neighbors
		}
	}
}

// DFS with two functions: one before entering child tree, and another after
func dfs2(node int, nodes map[int][]int, fn1, fn2 func(int, int)) {
	dfs2Recur(node, -1, nodes, map[int]bool{}, fn1, fn2) // Start the recursive DFS with parent tracking
}

// Recursive DFS helper function with parent tracking
func dfs2Recur(node, parent int, nodes map[int][]int, v map[int]bool, fn1, fn2 func(int, int)) {
	v[node] = true // Mark the node as visited
	if fn1 != nil {
		fn1(node, parent) // Execute the first function
	}
	for _, n := range nodes[node] {
		if _, ok := v[n]; !ok {
			dfs2Recur(n, node, nodes, v, fn1, fn2) // Recursively visit unvisited neighbors
		}
	}
	if fn2 != nil {
		fn2(node, parent) // Execute the second function
	}
}

// Stack data structure implementation
type Stack struct {
	top  *Element // Pointer to the top element
	size int // Size of the stack
}

// Element is a struct for stack element
type Element struct {
	value interface{} // Value of the element
	next  *Element // Pointer to the next element
}

// Len returns stack height
func (s *Stack) Len() int {
	return s.size // Return the size of the stack
}

// Push puts an element on the stack.
func (s *Stack) Push(value interface{}) {
	s.top = &Element{value, s.top} // Create a new element and set it as the top
	s.size++ // Increment the size
}

// Pop picks out the last element from the stack.
func (s *Stack) Pop() (value interface{}) {
	if s.size > 0 {
		value, s.top = s.top.value, s.top.next // Get the top value and update the top pointer
		s.size-- // Decrement the size
		return
	}
	return nil // Return nil if the stack is empty
}

// Power function for integer parameters
func powerInt(n, p int) int {
	tmp := 1
	for i := 0; i < n; i++ {
		tmp *= p // Calculate p^n
	}
	return tmp // Return the result
}

// Function to find divisors of a number
func findDivisors(n int, a *[]int) {
	if n == 1 {
		return // 1 has no divisors
	}

	sqrt := int(math.Sqrt(float64(n))) // Calculate the square root of n
	for i := 2; i <= sqrt; i++ {
		if n%i == 0 {
			*a = append(*a, i) // Append divisor i
			*a = append(*a, n/i) // Append corresponding divisor n/i
		}
	}
	*a = append(*a, n) // Append n itself as a divisor
}

// Function to remove duplicates from a slice
func removeDuplicate(a []int) []int {
	m := make(map[int]bool) // Create a map to track unique values
	for i := 0; i < len(a); i++ {
		m[a[i]] = true // Mark each value as seen
	}
	res := []int{}
	for i := range m {
		res = append(res, i) // Append unique values to the result slice
	}
	return res // Return the slice of unique values
}

// Function to calculate the absolute value
func abs(a int) int {
	if a > 0 {
		return a // Return a if positive
	}
	return -a // Return -a if negative
}

// Function to calculate the greatest common divisor (GCD)
func gcd(a, b int) int {
	for a != 0 {
		a, b = b % a, a // Euclidean algorithm
	}
	return b // Return the GCD
}

// Function to calculate power of 2 modulo a given number
func power2mod(n, mod int) int {
	res, x := 1, 2
	for ; n > 0; n >>= 1 {
		if n&1 == 1 {
			res = res * x % mod // Update result if the current bit is set
		}
		x = x * x % mod // Square the base
	}
	return res // Return the result
}

// Function to calculate power of 2 with modulo magic
func power2(n int) int {
	return power2mod(n, magic) // Call power2mod with magic
}
