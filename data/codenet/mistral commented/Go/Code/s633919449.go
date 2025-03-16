package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"math"
	"os"
	"strconv"
)

// Constants for buffer sizes and modulo value
const (
	initialBufSize = 10000
	maxBufSize     = 1000000
	mod            = 1e9 + 7
)

// Scanner for reading input
var (
	sc *bufio.Scanner = func() *bufio.Scanner {
		sc := bufio.NewScanner(os.Stdin)
		buf := make([]byte, initialBufSize)
		sc.Buffer(buf, maxBufSize)
		sc.Split(bufio.ScanWords)
		return sc
	}()
)

func main() {
	// Read an integer input
	N := getInt()

	// Determine the output based on the last digit of N
	switch N % 10 {
	case 2, 4, 5, 7, 9:
		fmt.Println("hon")
	case 0, 1, 6, 8:
		fmt.Println("pon")
	case 3:
		fmt.Println("bon")
	}
}

// Graph structure to represent edges
type Graph struct {
	n     int
	edges [][]int
}

// Constructor for creating a new graph
func NewGraph(n int) *Graph {
	g := &Graph{
		n:     n,
		edges: make([][]int, n),
	}
	return g
}

// Method to add an edge between two nodes in the graph
func (g *Graph) AddEdge(u, v int) {
	g.edges[v] = append(g.edges[v], u)
	g.edges[u] = append(g.edges[u], v)
}

// Depth-first search (DFS) algorithm implementation
func dfs(c int, edges [][]int, visited map[int]struct{}) {
	visited[c] = struct{}{}

	// Visit all adjacent nodes recursively
	for _, v := range edges[c] {
		_, flag := visited[v]
		if flag {
			continue
		}
		dfs(v, edges, visited)
	}
}

// Breadth-first search (BFS) algorithm implementation
func bfs(c int, graph *Graph) {
	next := make([]int, 0)
	next = append(next, c)
	visited := make(map[int]struct{})

	// Continue until there are no more nodes to visit
	for len(next) != 0 {
		u := next[0]
		next = next[1:]
		visited[u] = struct{}{}

		// Process each adjacent node
		for _, v := range graph.edges[u] {
			_, flag := visited[v]
			if flag {
				continue
			}

			// Placeholder for processing the node (e.g., marking, counting, etc.)

			next = append(next, v)
		}
	}
}

// Function to read an integer from input
func getInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

// Function to read an array of integers from input
func getIntArray(n int) []int {
	array := make([]int, n)
	for i := 0; i < n; i++ {
		array[i] = getInt()
	}
	return array
}

// Function to read a string from input
func getString() string {
	sc.Scan()
	return sc.Text()
}

// Function to read an array of strings from input
func getStringArray(n int) []string {
	array := make([]string, n)
	for i := 0; i < n; i++ {
		array[i] = getString()
	}
	return array
}

// Function to calculate the absolute value of an integer
func abs(a int) int {
	return int(math.Abs(float64(a)))
}

// Function to calculate p raised to the power of q
func pow(p, q int) int {
	return int(math.Pow(float64(p), float64(q)))
}

// Function to calculate n raised to the power of p modulo mod
func powMod(n, p int) int {
	if p == 0 {
		return 1
	} else if p%2 == 0 {
		t := powMod(n, p/2)
		return calcMod(t * t)
	} else {
		return calcMod(n * powMod(n, p-1))
	}
}

// Function to find the minimum value among a list of integers
func min(nums ...int) int {
	if len(nums) == 0 {
		panic("function min() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Min(float64(res), float64(nums[i])))
	}
	return res
}

// Function to find the maximum value among a list of integers
func max(nums ...int) int {
	if len(nums) == 0 {
		panic("function max() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Max(float64(res), float64(nums[i])))
	}
	return res
}

// Function to check if a string exists in an array of strings
func strSearch(a []string, b string) bool {
	for i := 0; i < len(a); i++ {
		if a[i] == b {
			return true
		}
	}
	return false
}

// Function to print an array of integers
func printIntArray(array []int) {
	strArray := fmt.Sprint(array)
	fmt.Println(strArray[1 : len(strArray)-1])
}

// Function to calculate x modulo mod
func calcMod(x int) int {
	return x % mod
}

// Function to reverse a string
func reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

// Function to check if a number is prime
func isPrime(n int) bool {
	if n < 2 {
		return false
	} else if n == 2 {
		return true
	} else if n%2 == 0 {
		return false
	}

	sqrtN := int(math.Sqrt(float64(n)))
	for i := 3; i <= sqrtN; i += 2 {
		if n%i == 0 {
			return false
		}
	}

	return true
}

// Function to check if an integer exists in a slice
func contains(s []int, e int) bool {
	for _, v := range s {
		if e == v {
			return true
		}
	}
	return false
}

// Function to create a range of integers from min to max
func makeRange(min, max int) []int {
	a := make([]int, max-min+1)
	for i := range a {
		a[i] = min + i
	}
	return a
}

// Function to generate the powerset of a given slice of integers
func powerset2(nums []int) [][]int {
	length := int(math.Pow(2, float64(len(nums))))
	result := make([][]int, length)

	index := 0
	result[index] = []int{}
	index++

	// Generate all subsets
	for _, n := range nums {
		max := index
		for i := 0; i < max; i++ {
			result[index] = copyAndAppend(result[i], n)
			index++
		}
	}

	return result
}

// Helper function to copy a slice and append a new element
func copyAndAppend(nums []int, n int) []int {
	dst := make([]int, len(nums)+1)
	copy(dst, nums)
	dst[len(nums)] = n
	return dst
}

// Function to calculate the greatest common divisor (GCD) of two integers
func calcGcd(x, y int) int {
	if y == 0 {
		return x
	} else if x >= y {
		return calcGcd(y, x%y)
	} else {
		return calcGcd(x, y%x)
	}
}

// Function to get all divisors of a number
func getDivisor(n int) []int {
	divisor := make(map[int]struct{})
	divisor[1] = struct{}{}
	if n != 1 {
		divisor[n] = struct{}{}
	}

	sqrt := int(math.Sqrt(float64(n)))
	for i := 2; i <= sqrt; i++ {
		if n%i == 0 {
			divisor[i] = struct{}{}
			divisor[n/i] = struct{}{}
		}
	}

	var divisorArray []int
	for d := range divisor {
		divisorArray = append(divisorArray, d)
	}
	return divisorArray
}

// Custom heap type for integers
type intHeap []int

// Implementing heap.Interface for intHeap
func (h intHeap) Len() int {
	return len(h)
}

func (h intHeap) Less(i, j int) bool {
	return h[i] > h[j]
}

func (h intHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

// Push an element onto the heap
func (h *intHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

// Pop an element from the heap
func (h *intHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// Initialize a new integer heap
func initHeap() *intHeap {
	ih := &intHeap{}
	heap.Init(ih)
	return ih
}

// Push an integer onto the heap
func (h *intHeap) pushHeap(n int) {
	heap.Push(h, n)
}

// Pop an integer from the heap
func (h *intHeap) popHeap() int {
	return heap.Pop(h).(int)
}

// Function to calculate factorial modulo mod
func factMod(n int) int {
	value := 1
	for ; n > 1; n-- {
		value = calcMod(value * n)
	}
	return value
}

// Function to calculate combinations modulo mod
func combinationMod(n, k int) int {
	factN := factMod(n)
	factK := factMod(k)
	factNK := factMod(n - k)
	factKR := powMod(factK, mod-2)
	factNKR := powMod(factNK, mod-2)
	return calcMod(factN * calcMod(factKR * factNKR))
}

// Function to find prime factors of a number
func primeFactors(n int) []int {
	factors := make([]int, 0)
	i := 2
	for i*i <= n {
		r := n % i
		if r != 0 {
			i += 1
		} else if r == 0 {
			n /= i
			factors = append(factors, i)
		}
	}
	if n > 1 {
		factors = append(factors, n)
	}
	return factors
}
