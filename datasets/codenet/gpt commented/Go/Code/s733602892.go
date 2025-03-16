package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Read the number of elements N and the threshold K
	N, K := ReadInt(), ReadInt()
	
	// Read the two slices of integers As and Fs
	As := ReadInts(N)
	Fs := ReadInts(N)

	// Sort the As slice in ascending order
	sort.Ints(As)
	// Sort the Fs slice in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(Fs)))
	
	// Create a slice to hold the scores calculated from As and Fs
	scores := make([]int, N)
	for i := 0; i < N; i++ {
		// Calculate the score for each pair of As and Fs
		scores[i] = As[i] * Fs[i]
	}
	
	// Sort the scores in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(scores)))

	// Initialize binary search boundaries
	ok := scores[0] // The maximum possible score
	ng := -1        // The minimum possible score

	// Perform binary search to find the maximum score that can be achieved
	for ok-ng > 1 {
		mid := (ok + ng) / 2 // Calculate the midpoint of the current range

		isOK := true // Flag to check if the current mid is achievable
		k := K       // Remaining threshold to adjust scores
		for i := 0; isOK && i < N; i++ {
			// If the current score exceeds mid, calculate how much we need to reduce
			if As[i]*Fs[i] > mid {
				k -= As[i] - mid/Fs[i]
			}
			// If we exceed the allowed threshold, mark isOK as false
			if k < 0 {
				isOK = false
			}
		}

		// Adjust binary search boundaries based on whether mid is achievable
		if isOK {
			ok = mid // If achievable, move the upper boundary
		} else {
			ng = mid // If not achievable, move the lower boundary
		}
	}

	// Print the maximum achievable score
	fmt.Println(ok)
}

// ReadInts reads n integers from input and returns them as a slice
func ReadInts(n int) []int {
	ret := make([]int, n)
	for i := 0; i < n; i++ {
		ret[i] = ReadInt() // Read each integer and store it in the slice
	}
	return ret
}

// Initialize a scanner for reading input
var sc = bufio.NewScanner(os.Stdin)

// Initialize the scanner with a buffer and split function
func init() { 
	sc.Buffer(make([]byte, 256), 1e9); 
	sc.Split(bufio.ScanWords) 
}

// Read reads the next token from input as a string
func Read() string { 
	sc.Scan(); 
	return sc.Text() 
}

// ReadInt reads the next integer from input and returns it
func ReadInt() int {
	v, e := strconv.Atoi(Read()) // Convert the input string to an integer
	if e != nil {
		panic(e.Error()) // Panic if conversion fails
	}
	return v
}
