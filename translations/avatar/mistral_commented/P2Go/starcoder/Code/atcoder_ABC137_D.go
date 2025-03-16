
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// HeapItem is a struct for storing the day and salary of an employee
type HeapItem struct {
	day   int
	salary int
}

// Heap is a min heap for storing the employees
type Heap []*HeapItem

// Len returns the length of the heap
func (h Heap) Len() int {
	return len(h)
}

// Less returns true if the element at index i is less than the element at index j
func (h Heap) Less(i, j int) bool {
	return h[i].day < h[j].day
}

// Swap swaps the elements at index i and j
func (h Heap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

// Push pushes the element x to the heap
func (h *Heap) Push(x interface{}) {
	*h = append(*h, x.(*HeapItem))
}

// Pop pops the element at index 0 from the heap
func (h *Heap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// NewHeap returns a new heap
func NewHeap() Heap {
	return make(Heap, 0)
}

// main function
func main() {
	// Reading input from stdin
	reader := bufio.NewReader(os.Stdin)
	// Taking input of number of days and number of employees
	n, m := readTwoNums(reader)
	// Initializing empty lists for storing days and salaries
	x := NewHeap()
	y := NewHeap()
	// Iterating through each employee and adding their details to the heap 'x'
	for i := 0; i < n; i++ {
		day, salary := readTwoNums(reader)
		// Adding employee details as a tuple to the heap 'x' with negative day and salary values
		heapq.Push(x, &HeapItem{-day, -salary})
	}
	// Simulation loop to check if an employee can be added to the list 'y'
	for x.Len() > 0 {
		// Popping the employee with minimum negative day from the heap 'x'
		d, s := heapq.Pop(x).(*HeapItem)
		// Calculating the remaining capacity in the list 'y'
		r := m - y.Len()
		// Checking if the remaining capacity is enough to add the current employee
		if r >= d {
			// If yes, adding the salary of the employee to the list 'y'
			heapq.Push(y, &HeapItem{0, -s})
		} else {
			// If no, removing an employee with minimum salary from the list 'y' and adding the current employee
			heapq.Push(y, &HeapItem{0, -s})
			heapq.Pop(y)
		}
	}
	// Printing the sum of salaries of employees in the list 'y'
	fmt.Printf("%d\n", sum(y))
}

// readTwoNums reads two integers from stdin
func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

// readNNums reads n integers from stdin
func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-'; x++ {
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

// readInt reads an integer from a byte slice
func readInt(bs []byte, from int, val *int) int {
	i := from
	sign := 1
	if bs[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bs) && bs[i] >= '0' && bs[i] <= '9' {
		tmp = tmp*10 + int(bs[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

// func solve(n int, m int, x []int, y []int) int {
// 	// TODO - Will be added later
// 	return 0
// }

// func main() {
// 	reader := bufio.NewReader(os.Stdin)
// 	tc := readNum(reader)
// 	var buf bytes.Buffer
// 	for tc > 0 {
// 		tc--
// 		n, m := readTwoNums(reader)
// 		x := readNNums(reader, n)
// 		y := readNNums(reader, m)
// 		res := solve(n, m, x, y)
// 		buf.WriteString(fmt.Sprintf("%d\n", res))
// 	}
// 	fmt.Print(buf.String())
// }

// func readInt(bytes []byte, from int, val *int) int {
// 	i := from
// 	sign := 1
// 	if bytes[i] == '-' {
// 		sign = -1
// 		i++
// 	}
// 	tmp := 0
// 	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
// 		tmp = tmp*10 + int(bytes[i]-'0')
// 		i++
// 	}
// 	*val = tmp * sign
// 	return i
// }

// func readNum(reader *bufio.Reader) (a int) {
// 	bs, _ := reader.ReadBytes('\n')
// 	readInt(bs, 0, &a)
// 	return
// }

// func readTwoNums(reader *bufio.Reader) (a int, b int) {
// 	res := readNNums(reader, 2)
// 	a, b = res[0], res[1]
// 	return
// }

// func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
// 	res := readNNums(reader, 3)
// 	a, b, c = res[0], res[1], res[2]
// 	return
// }

// func readNNums(reader *bufio.Reader, n int) []int {
// 	res := make([]int, n)
// 	x := 0
// 	bs, _ := reader.ReadBytes('\n')
// 	for i := 0; i < n; i++ {
// 		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-'; x++ {
// 		}
// 		x = readInt(bs, x, &res[i])
// 	}
// 	return res
// }

// func readUint64(bytes []byte, from int, val *uint64) int {
// 	i := from
// 	var tmp uint64
// 	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
// 		tmp = tmp*10 + uint64(bytes[i]-'0')
// 		i++
// 	}
// 	*val = tmp
// 	return i
// }

// func solve(n int, m int, x []int, y []int) int {
// 	// TODO - Will be added later
// 	return 0
// }

// func main() {
// 	reader := bufio.NewReader(os.Stdin)
// 	tc := readNum(reader)
// 	var buf bytes.Buffer
// 	for tc > 0 {
// 		tc--
// 		n, m := readTwoNums(reader)
// 		x := readNNums(reader, n)
// 		y := readNNums(reader, m)
// 		res := solve(n, m, x, y)
// 		buf.WriteString(fmt.Sprintf("%d\n", res))
// 	}
// 	fmt.Print(buf.String())
// }

// func readInt(bytes []byte, from int, val *int) int {
// 	i := from
// 	sign := 1
// 	if bytes[i] == '-' {
// 		sign = -1
// 		i++
// 	}
// 	tmp := 0
// 	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
// 		tmp = tmp*10 + int(bytes[i]-'0')
// 		i++
// 	}
// 	*val = tmp * sign
// 	return i
// }

// func readNum(reader *bufio.Reader) (a int) {
// 	bs, _ := reader.ReadBytes('\n')
// 	readInt(bs, 0, &a)
// 	return
// }

// func readTwoNums(reader *bufio.Reader) (a int, b int) {
// 	res := readNNums(reader, 2)
// 	a, b = res[0], res[1]
// 	return
// }

// func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
// 	res := readNNums(reader, 3)
// 	a, b, c = res[0], res[1], res[2]
// 	return
// }

// func readNNums(reader *bufio.Reader, n int) []int {
// 	res := make([]int, n)
// 	x := 0
// 	bs, _ := reader.ReadBytes('\n')
// 	for i := 0; i < n; i++ {
// 		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-'; x++ {
// 		}
// 		x = readInt(bs, x, &res[i])
// 	}
// 	return res
// }

// func readUint64(bytes []byte, from int, val *uint64) int {
// 	i := from
// 	var tmp uint64
// 	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
// 		tmp = tmp*10 + uint64(bytes[i]-'0')
// 		i++
// 	}
// 	*val = tmp
// 	return i
// }

// func solve(n int, m int, x []int, y []int) int {
// 	// TODO - Will be added later
// 	return 0
// }

// func main() {
// 	reader := bufio.NewReader(os.Stdin)
// 	tc := readNum(reader)
// 	var buf bytes.Buffer
// 	for tc > 0 {
// 		tc--
// 		n, m := readTwoNums(reader)
// 		x := readNNums(reader, n)
// 		y := readNNums(reader, m)
// 		res := solve(n, m, x, y)
// 		buf.WriteString(fmt.Sprintf("%d\n", res))
// 	}
// 	fmt.Print(buf.String())
// }

// func readInt(bytes []byte, from int, val *int) int {
// 	i := from
// 	sign := 1
// 	if bytes[i] == '-' {
// 		sign = -1
// 		i++
// 	}
// 	tmp := 0
// 	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
// 		tmp = tmp*10 + int(bytes[i]-'0')
// 		i++
// 	}
// 	*val = tmp * sign
// 	return i
// }

// func readNum(reader *bufio.Reader) (a int) {
// 	bs, _ := reader.ReadBytes('\n')
// 	readInt(bs, 0, &a)
// 	return
// }

// func readTwoNums(reader *bufio.Reader) (a int, b int) {
// 	res := readNNums(reader, 2)
// 	a, b = res[0], res[1]
// 	return
// }

// func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
// 	res := readNNums(reader, 3)
// 	a, b, c = res[0], res[1], res[2]
// 	return
// }

// func readNNums(reader *bufio.Reader, n int) []int {
// 	res := make([]int, n)
// 	x := 0
// 	bs, _ := reader.ReadBytes('\n')
// 	for i := 0; i < n; i++ {
// 		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-'; x++ {
// 		}
// 		x = readInt(bs, x, &res[i])
// 	}
// 	return res
// }

// func readUint64(bytes []byte, from int, val *uint64) int {
// 	i := from
// 	var tmp uint64
// 	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
// 		tmp = tmp*10 + uint64(bytes[i]-'0')
// 		i++
// 	}
// 	*val = tmp
// 	return i
// }

// func solve(n int, m int, x []int, y []int) int {
// 	// TODO - Will be added later
// 	return 0
// }

// func main() {
// 	reader := bufio.NewReader(os.Stdin)
// 	tc := readNum(reader)
// 	var buf bytes.Buffer
// 	for tc > 0 {
// 		tc--
// 		n, m := readTwoNums(reader)
// 		x := readNNums(reader, n)
// 		y := readNNums(reader, m)
// 		res := solve(n, m, x, y)
// 		buf.WriteString(fmt.Sprintf("%d\n", res))
// 	}
// 	fmt.Print(buf.String())
// }

// func readInt(bytes []byte, from int, val *int) int {
// 	i := from
// 	sign := 1
// 	if bytes[i] == '-' {
// 		sign = -1
// 		i++
// 	}
// 	tmp := 0
// 	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
// 		tmp = tmp*10 + int(bytes[i]-'0')
// 		i++
// 	}
// 	*val = tmp * sign
// 	return i
// }

// func readNum(reader *bufio.Reader) (a int) {
// 	bs, _ := reader.ReadBytes('\n')
// 	readInt(bs, 0, &a)
// 	return
// }

// func readTwoNums(reader *bufio.Reader) (a int, b int) {
// 	res := readNNums(reader, 2)
// 	a, b = res[0], res[1]
// 	return
// }

// func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
// 	res := readNNums(reader, 3)
// 	a, b, c = res[0], res[1], res[2]
// 	return
// }

// func readNNums(reader *bufio.Reader, n int) []int {
// 	res := make([]int, n)
// 	x := 0
// 	bs, _ := reader.ReadBytes('\n')
// 	for i := 0; i < n; i++ {
// 		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-'; x++ {
// 		}
// 		x = readInt(bs, x, &res[i])
// 	}
// 	return res
// }

// func readUint64(bytes []byte, from int, val *uint64) int {
// 	i := from
// 	var tmp uint64
// 	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
// 		tmp = tmp*10 + uint64(bytes[i]-'0')
// 		i++
// 	}
// 	*val = tmp
// 	return i
// }

// func solve(n int, m int, x []int, y []int) int {
// 	// TODO - Will be added later
// 	return 0
// }

// func main() {
// 	reader