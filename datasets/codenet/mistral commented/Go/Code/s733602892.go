
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	// Read input: N and K
	N, K := ReadInt(), ReadInt()

	// Read input: N integers As
	As := ReadInts(N)

	// Read input: N integers Fs
	Fs := ReadInts(N)

	// Sort As and Fs in ascending and descending order respectively
	sort.Ints(As)
	sort.Sort(sort.Reverse(sort.IntSlice(Fs)))

	// Calculate the score for each element in As
	scores := make([]int, N)
	for i := 0; i < N; i++ {
		scores[i] = As[i] * Fs[i]
	}

	// Sort scores in descending order
	sort.Sort(sort.Reverse(sort.IntSlice(scores)))

	// Binary search to find the answer
	ok := scores[0]
	ng := -1
	for ok-ng > 1 {
		mid := (ok + ng) / 2

		// Check if it's possible to distribute the flowers to K students with the given mid score
		isOK := true
		k := K
		for i := 0; isOK && i < N; i++ {
			if As[i]*Fs[i] > mid {
				// Subtract the difference between mid and the product of the current element from the remaining flowers
				k -= As[i] - mid/Fs[i]
			}
			if k < 0 {
				// If the remaining flowers are not enough to distribute to all students, it's not possible to distribute the flowers with the given mid score
				isOK = false
				break
			}
		}

		if isOK {
			// If it's possible to distribute the flowers with the given mid score, update ok with mid
			ok = mid
		} else {
			// If it's not possible to distribute the flowers with the given mid score, update ng with mid
			ng = mid
		}

	}

	// Print the answer
	fmt.Println(ok)
}

func ReadInts(n int) []int {
	// Read n integers and return as a slice
	ret := make([]int, n)
	for i := 0; i < n; i++ {
		ret[i] = ReadInt()
	}
	return ret
}

var sc = bufio.NewScanner(os.Stdin)

// Initialize scanner with a large buffer and ScanWords split function
func init()        { sc.Buffer(make([]byte, 256), 1e9); sc.Split(bufio.ScanWords) }

// Read a single word from standard input
func Read() string { sc.Scan(); return sc.Text() }

// Read an integer from standard input
func ReadInt() int {
	// Convert the read word to an integer and panic if conversion fails
	v, e := strconv.Atoi(Read())
	if e != nil {
		panic(e.Error())
	}
	return v
}

