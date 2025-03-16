
package main

import (
	"fmt"
	"container/heap"
)

func main() {
	// Create a Scanner object to read input from the standard input stream
	sc := new(Scanner)

	// Read the integer N from the input
	var N int
	fmt.Scan(&N)

	// Initialize an array of size N to store the integers
	arr := make([]int, N)

	// Read N integers from the input and store them in the array
	for i := 0; i < N; i++ {
		fmt.Scan(&arr[i])
	}

	// Initialize a sum variable to 0
	sum := 0

	// Create a priority queue to store the integers in ascending order
	q := make(PriorityQueue, 0)

	// Iterate through the array and add each element to the priority queue
	for i := 0; i < len(arr); i++ {
		heap.Push(&q, arr[i])

		// Check if the current element is less than or equal to the smallest element in the priority queue
		if arr[i] <= q[0] {
			sum++
		}
	}

	// Return the sum
	fmt.Println(sum)
}

// Define a type for the priority queue
type PriorityQueue []int

// Define the Less function for the priority queue
func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i] < pq[j]
}

// Define the Swap function for the priority queue
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

// Define the Len function for the priority queue
func (pq PriorityQueue) Len() int {
	return len(pq)
}

// Define the Pop function for the priority queue
func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

// Define the Push function for the priority queue
func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(int))
}

// Define the Peek function for the priority queue
func (pq PriorityQueue) Peek() interface{} {
	return pq[0]
}

// Define the Empty function for the priority queue
func (pq PriorityQueue) Empty() bool {
	return len(pq) == 0
}

// Define the Scanner struct
type Scanner struct {
}

// Define the Scan function for the Scanner struct
func (sc *Scanner) Scan(a ...interface{}) {
	for i := range a {
		fmt.Scan(a[i].(*int))
	}
}

// Define the NextInt function for the Scanner struct
func (sc *Scanner) NextInt() int {
	var x int
	sc.Scan(&x)
	return x
}

// Define the NextIntSlice function for the Scanner struct
func (sc *Scanner) NextIntSlice(n int) []int {
	a := make([]int, n)
	sc.Scan(a...)
	return a
}

// Define the NextFloat64 function for the Scanner struct
func (sc *Scanner) NextFloat64() float64 {
	var x float64
	sc.Scan(&x)
	return x
}

// Define the NextFloat64Slice function for the Scanner struct
func (sc *Scanner) NextFloat64Slice(n int) []float64 {
	a := make([]float64, n)
	sc.Scan(a...)
	return a
}

// Define the NextString function for the Scanner struct
func (sc *Scanner) NextString() string {
	var x string
	sc.Scan(&x)
	return x
}

// Define the NextStringSlice function for the Scanner struct
func (sc *Scanner) NextStringSlice(n int) []string {
	a := make([]string, n)
	sc.Scan(a...)
	return a
}

// Define the NextRuneSlice function for the Scanner struct
func (sc *Scanner) NextRuneSlice() []rune {
	return []rune(sc.Text())
}

// Define the NextInt64 function for the Scanner struct
func (sc *Scanner) NextInt64() int64 {
	var x int64
	sc.Scan(&x)
	return x
}

// Define the NextInt64Slice function for the Scanner struct
func (sc *Scanner) NextInt64Slice(n int) []int64 {
	a := make([]int64, n)
	sc.Scan(a...)
	return a
}

// Define the NextFloat32Slice function for the Scanner struct
func (sc *Scanner) NextFloat32Slice(n int) []float32 {
	a := make([]float32, n)
	sc.Scan(a...)
	return a
}

// Define the NextFloat32 function for the Scanner struct
func (sc *Scanner) NextFloat32() float32 {
	var x float32
	sc.Scan(&x)
	return x
}

// Define the NextInt32 function for the Scanner struct
func (sc *Scanner) NextInt32() int32 {
	var x int32
	sc.Scan(&x)
	return x
}

// Define the NextInt32Slice function for the Scanner struct
func (sc *Scanner) NextInt32Slice(n int) []int32 {
	a := make([]int32, n)
	sc.Scan(a...)
	return a
}

// Define the NextUint64 function for the Scanner struct
func (sc *Scanner) NextUint64() uint64 {
	var x uint64
	sc.Scan(&x)
	return x
}

// Define the NextUint64Slice function for the Scanner struct
func (sc *Scanner) NextUint64Slice(n int) []uint64 {
	a := make([]uint64, n)
	sc.Scan(a...)
	return a
}

// Define the NextUint32 function for the Scanner struct
func (sc *Scanner) NextUint32() uint32 {
	var x uint32
	sc.Scan(&x)
	return x
}

// Define the NextUint32Slice function for the Scanner struct
func (sc *Scanner) NextUint32Slice(n int) []uint32 {
	a := make([]uint32, n)
	sc.Scan(a...)
	return a
}

// Define the NextUint16 function for the Scanner struct
func (sc *Scanner) NextUint16() uint16 {
	var x uint16
	sc.Scan(&x)
	return x
}

// Define the NextUint16Slice function for the Scanner struct
func (sc *Scanner) NextUint16Slice(n int) []uint16 {
	a := make([]uint16, n)
	sc.Scan(a...)
	return a
}

// Define the NextByte function for the Scanner struct
func (sc *Scanner) NextByte() byte {
	var x byte
	sc.Scan(&x)
	return x
}

// Define the NextByteSlice function for the Scanner struct
func (sc *Scanner) NextByteSlice(n int) []byte {
	a := make([]byte, n)
	sc.Scan(a...)
	return a
}

// Define the NextRune function for the Scanner struct
func (sc *Scanner) NextRune() rune {
	var x rune
	sc.Scan(&x)
	return x
}

// Define the NextIntSlice2 function for the Scanner struct
func (sc *Scanner) NextIntSlice2(n int) [][]int {
	a := make([][]int, n)
	for i := range a {
		a[i] = sc.NextIntSlice(sc.NextInt())
	}
	return a
}

// Define the NextFloat64Slice2 function for the Scanner struct
func (sc *Scanner) NextFloat64Slice2(n int) [][]float64 {
	a := make([][]float64, n)
	for i := range a {
		a[i] = sc.NextFloat64Slice(sc.NextInt())
	}
	return a
}

// Define the NextStringSlice2 function for the Scanner struct
func (sc *Scanner) NextStringSlice2(n int) [][]string {
	a := make([][]string, n)
	for i := range a {
		a[i] = sc.NextStringSlice(sc.NextInt())
	}
	return a
}

// Define the NextInt64Slice2 function for the Scanner struct
func (sc *Scanner) NextInt64Slice2(n int) [][]int64 {
	a := make([][]int64, n)
	for i := range a {
		a[i] = sc.NextInt64Slice(sc.NextInt())
	}
	return a
}

// Define the NextFloat32Slice2 function for the Scanner struct
func (sc *Scanner) NextFloat32Slice2(n int) [][]float32 {
	a := make([][]float32, n)
	for i := range a {
		a[i] = sc.NextFloat32Slice(sc.NextInt())
	}
	return a
}

// Define the NextFloat64Slice2 function for the Scanner struct
func (sc *Scanner) NextFloat64Slice2(n int) [][]float64 {
	a := make([][]float64, n)
	for i := range a {
		a[i] = sc.NextFloat64Slice(sc.NextInt())
	}
	return a
}

// Define the NextInt32Slice2 function for the Scanner struct
func (sc *Scanner) NextInt32Slice2(n int) [][]int32 {
	a := make([][]int32, n)
	for i := range a {
		a[i] = sc.NextInt32Slice(sc.NextInt())
	}
	return a
}

// Define the NextUint64Slice2 function for the Scanner struct
func (sc *Scanner) NextUint64Slice2(n int) [][]uint64 {
	a := make([][]uint64, n)
	for i := range a {
		a[i] = sc.NextUint64Slice(sc.NextInt())
	}
	return a
}

// Define the NextUint32Slice2 function for the Scanner struct
func (sc *Scanner) NextUint32Slice2(n int) [][]uint32 {
	a := make([][]uint32, n)
	for i := range a {
		a[i] = sc.NextUint32Slice(sc.NextInt())
	}
	return a
}

// Define the NextUint16Slice2 function for the Scanner struct
func (sc *Scanner) NextUint16Slice2(n int) [][]uint16 {
	a := make([][]uint16, n)
	for i := range a {
		a[i] = sc.NextUint16Slice(sc.NextInt())
	}
	return a
}

// Define the NextByteSlice2 function for the Scanner struct
func (sc *Scanner) NextByteSlice2(n int) [][]byte {
	a := make([][]byte, n)
	for i := range a {
		a[i] = sc.NextByteSlice(sc.NextInt())
	}
	return a
}

// Define the NextRuneSlice2 function for the Scanner struct
func (sc *Scanner) NextRuneSlice2(n int) [][]rune {
	a := make([][]rune, n)
	for i := range a {
		a[i] = sc.NextRuneSlice(sc.NextInt())
	}
	return a
}

// Define the NextIntSlice3 function for the Scanner struct
func (sc *Scanner) NextIntSlice3(n int) [][][]int {
	a := make([][][]int, n)
	for i := range a {
		a[i] = sc.NextIntSlice2(sc.NextInt())
	}
	return a
}

// Define the NextFloat64Slice3 function for the Scanner struct
func (sc *Scanner) NextFloat64Slice3(n int) [][][]float64 {
	a := make([][][]float64, n)
	for i := range a {
		a[i] = sc.NextFloat64Slice2(sc.NextInt())
	}
	return a
}

// Define the NextStringSlice3 function for the Scanner struct
func (sc *Scanner) NextStringSlice3(n int) [][][]string {
	a := make([][][]string, n)
	for i := range a {
		a[i] = sc.NextStringSlice2(sc.NextInt())
	}
	return a
}

// Define the NextInt64Slice3 function for the Scanner struct
func (sc *Scanner) NextInt64Slice3(n int) [][][]int64 {
	a := make([][][]int64, n)
	for i := range a {
		a[i] = sc.NextInt64Slice2(sc.NextInt())
	}
	return a
}

// Define the NextFloat32Slice3 function for the Scanner struct
func (sc *Scanner) NextFloat32Slice3(n int) [][][]float32 {
	a := make([][][]float32, n)
	for i := range a {
		a[i] = sc.NextFloat32Slice2(sc.NextInt())
	}
	return a
}

// Define the NextFloat64Slice3 function for the Scanner struct
func (sc *Scanner) NextFloat64Slice3(n int) [][][]float64 {
	a := make([][][]float64, n)
	for i := range a {
		a[i] = sc.NextFloat64Slice2(sc.NextInt())
	}
	return a
}

// Define the NextInt32Slice3 function for the Scanner struct
func (sc *Scanner) NextInt32Slice3(n int) [][][]int32 {
	a := make([][][]int32, n)
	for i := range a {
		a[i] = sc.NextInt32Slice2(sc.NextInt())
	}
	return a
}

// Define the NextUint64Slice3 function for the Scanner struct
func (sc *Scanner) NextUint64Slice3(n int) [][][]uint64 {
	a := make([][][]uint64, n)
	for i := range a {
		a[i] = sc.NextUint64Slice2(sc.NextInt())
	}
	return a
}

// Define the NextUint32Slice3 function for the Scanner struct
func (sc *Scanner) NextUint32Slice3(n int) [][][]uint32 {
	a := make([][][]uint32, n)
	for i := range a {
		a[i] = sc.NextUint32Slice2(sc.NextInt())
	}
	return a
}

// Define the Ne